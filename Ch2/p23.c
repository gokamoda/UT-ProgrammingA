//交換ソート（バブルソート）

#include <stdio.h>
#include <stdlib.h>
#include "../custom_library/sort.h"


int bub_sort(int *, int);

int main(){
  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(N);  // 配列に動的メモリを割り当てる
  for (int i = 0; i < N; i++){
    scanf("%d", &array[i]);  // STDINから配列要素を受け取る
  }
  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力
  int cnt = bub_sort(array, N);  // 入力配列を逆順
  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力
  printf("%d\n", cnt);     // comp_が呼んだ合計回数を出力

  free(array);  // 配列に割り当てられたメモリの開放
  return 0;
}

int bub_sort(int *array, int N){
  int cnt=0;
  for(int i=0; i<N; i++){
    for(int j=0;j<N-i-1;j++){
      cnt +=1;
      if(comp_(array, j+1,j)==1){
        func_swap_(array, j, j+1);
        print_array_(array, N);
      }
    }
  }
  return cnt;
}


