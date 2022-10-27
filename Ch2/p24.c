//挿入ソート

#include <stdio.h>
#include <stdlib.h>
#include "../custom_library/sort.h"


int ins_sort(int *, int);

int main(){
  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(N+1);  // 配列に動的メモリを割り当てる
  for (int i = 0; i < N; i++){
    scanf("%d", &array[i]);  // STDINから配列要素を受け取る
  }
  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力
  int cnt = ins_sort(array, N);  // 入力配列を逆順
  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力
  printf("%d\n", cnt);     // comp_が呼んだ合計回数を出力

  free(array);  // 配列に割り当てられたメモリの開放
  return 0;
}

int ins_sort(int *array, int N){
  int cnt=0;
  for(int i=1; i<N; i++){
    func_copy_val_(array, i, N);
    for(int j=i-1; j>=0; j--){
      cnt +=1;
      if(comp_(array, j, N)==1){
        if(i!=j+1){
          func_copy_val_(array, N, j+1);
          printf("INST(%2d,%2d)",i,j+1);
          print_array_(array, N);
        }
        break;
      }else{
        func_copy_val_(array, j, j+1);
        if(j==0){
          func_copy_val_(array, N, j);
          printf("INST(%2d,%2d)",j,i);
          print_array_(array, N);
        }
      }
    }
  }
  return cnt;
}