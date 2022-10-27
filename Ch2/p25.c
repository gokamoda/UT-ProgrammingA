//マージソート

#include <stdio.h>
#include <stdlib.h>
#include "../custom_library/sort.h"


int mrg_sort(int *, int, int, int );
int merge(int *, int, int, int, int);

int main(){
  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(N*2);  // 配列に動的メモリを割り当てる
  for (int i = 0; i < N; i++){
    scanf("%d", &array[i]);  // STDINから配列要素を受け取る
  }
  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力
  int cnt = mrg_sort(array, N, 0, N-1);  // 入力配列を逆順
  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力
  printf("%d\n", cnt);     // comp_が呼んだ合計回数を出力

  free(array);  // 配列に割り当てられたメモリの開放
  return 0;
}

int mrg_sort(int *array, int N, int p, int q){
  int cnt = 0;
  if(p!=q){
    int r = (p+q)/2;
    cnt += mrg_sort(array, N, p, r);
    cnt += mrg_sort(array, N, r+1, q);
    cnt += merge(array, N, p, q, r);
  }
  return cnt;
}

int merge(int *array, int N, int p, int q, int r){
  int cnt=0;
  int i=0, j=0;
  while((p+i)<=r&&(r+1+j)<=q){
    cnt +=1;
    if(comp_(array, p+i, r+1+j)==1){
      func_copy_val_(array, p+i, N+p+i+j);
      i++;
    }else{
      func_copy_val_(array, r+1+j, N+p+i+j);
      j++;
    }
  }
  if(p+i==r+1){
    for(; (r+1+j)<=q; j++){
      func_copy_val_(array, r+1+j, N+p+i+j);
    }
  }
  if(r+1+j==q+1){
    for(; p+i<=r; i++){
      func_copy_val_(array, p+i, N+p+i+j);
    }
  }
  for(int k=p; k<=q; k++){
    func_copy_val_(array, N+k, k);
  }
  printf("MERG(%2d,%2d)",p,q);
  print_array_range_(array, N, p, q);
  return cnt;
}