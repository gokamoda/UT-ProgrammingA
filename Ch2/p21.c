/*
配列の逆順置換

問題
  以下のプログラムは与えられた配列データを読み込み，
  逆順にして出力する．このプログラムにコメントを追加せよ．
*/

#include <stdio.h>
#include <stdlib.h>
#include "../custom_library/sort.h"

int reverse_array(int*, int);

int main() {
  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(N);  // 配列に動的メモリを割り当てる
  for (int i = 0; i < N; i++)
    scanf("%d", &(array[i]));  // STDINから配列要素を受け取る
  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力
  int cnt = reverse_array(array, N);  // 入力配列を逆順
  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力
  printf("%d\n", cnt);     // comp_が呼んだ合計回数を出力

  free(array);  // 配列に割り当てられた動的メモリを解放
  return 0;     // ???
}

int reverse_array(  // ???
    int* array,     // ???
    int N           // ???
) {
  int pos_a = 0;       // ???
  int pos_b = N - 1;   // ???
  int comp_count = 0;  // ???

  while (pos_a < pos_b) {  // ???
    comp_count += 2;       // ???

    if ((comp_(array, pos_a, pos_b) +   // ???
        comp_(array, pos_b, pos_a))	// ???
    == 1) {   			// ???
      func_swap_(array, pos_a, pos_b);  // ???
      print_array_(array, N);           // ???
    }
    pos_a++;  // ???
    pos_b--;  // ???
  }
  return comp_count;  // ???
}