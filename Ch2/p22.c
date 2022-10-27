/*
選択ソート
  ここではもっともシンプルなソートアルゴリズムのひとつである
  挿入に基づくソートである 選択ソート (selection sort) を実装しよう．

  まず，ソートには昇順（小さい方から大きい方へ）と
  降順（大きい方から小さい方へ）の通常二パターンが考えられるが，
  本課題では，簡単のため昇順の場合のみを考える．
  以降，断りなく単に「ソート」と記載があった場合には，
  昇順ソートのこととする．

  選択ソートの基本操作は，
  ソートされていない要素から最も小さい値を見つけ出す」である．
  また，見つけた最小値を取り除き，同じ手順を行えば，
  2番目に小さい値，3番目に小さい値，と順番に抽出することができる．
  よって，その時点での最小値を取得したら，
  それを，配列の先頭から並べていけばソートが完成する．
  という仕組みである． 直感的にもわかりやすいアルゴリズムと言える．

  しかし，これを実際にプログラムで実装するためには，
  いろいろ考えることがある．
  もうすこし具体的な処理手順としては以下のようになる．

  配列全体から，もっとも値の小さいデータを探し，
  配列の先頭(1番目)の要素と交換する．
  1番目の要素を除き，配列の残りのデータの中から，
  もっとも値の小さいデータ（全体で2番目に値の小さいデータ）を探し，
  配列の先頭から2番の要素と交換する．
  1,2番目の要素を除き，配列の残りのデータの中から，
  もっとも値の小さいデータ（全体で3番目に値の小さいデータ）を探し，
  配列の手前から3番目の要素と交換する．
  以下同様

問題
  与えられた配列データを選択ソートにより昇順に並べ替えるプログラムを作成せよ．
  
  例：
  ソートしたい配列が　1 9 2 8 3 7
  なら、要素の数6を含めて、標準入力に
  6 1 9 2 8 3 7 と入れる。

*/
#include <stdio.h>
#include <stdlib.h>
#include "../custom_library/sort.h"


int sel_sort(int *, int);

int main(){
  int N;       // 入力配列の要素数
  scanf("%d", &N);               // STDINから要素数を受け取る
  int* array = func_mallocation_(N);  // 配列に動的メモリを割り当てる
  for (int i = 0; i < N; i++){
    scanf("%d", &array[i]);  // STDINから配列要素を受け取る
  }
  printf("INIT:::::::");
  print_array_(array, N);             // 配列の初期状態をSTDOUTに出力
  int cnt = sel_sort(array, N);  // 入力配列を逆順
  printf("DONE:::::::");
  print_array_(array, N);  // 配列の最終状態をSTDOUTに出力
  printf("%d\n", cnt);     // comp_が呼んだ合計回数を出力

  free(array);  // 配列に割り当てられた動的メモリを解放
  return 0;     
}

int sel_sort(int *array, int N){
  int min;
  int comp_count=0;
  for(int i=0; i<N-1; i++){
    min=i;
    for(int j=i+1; j<N; j++){
      comp_count+=1;
      if(comp_(array, j, min)==1){
        min = j;
      }
    }
    if(i!=min){
      func_swap_(array, i, min);
      print_array_(array, N);
    }
  return comp_count;
  }
}