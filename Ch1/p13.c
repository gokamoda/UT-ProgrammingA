/*
トリム平均
  スキー・ジャンプの飛型点の採点など，
  スポーツ競技の採点を複数の審判で行う際は，
  極端な採点による影響を抑えるため，
  審判員全員の採点を単純に平均するのではなく，
  最大値と最小値を外れ値として除外した平均がしばしば用いられる．
  トリム平均（trim mean），刈り込み平均（truncated mean），調整平均などと呼ばれる．
  ここではこのトリム平均を求めるプログラムを作成しよう．

問題
  標準入力から7個の実数値データを読み込み，
  そのデータから最大値と最小値を除外し，
  残った5個の実数値の平均値を標準出力に書き出すプログラムを作成せよ．

  ただし，入力される実数値は半角スペースで区切られて入力されると仮定してよい．
  プログラムは以下の仕様を満たすこと．

  入力値は−20より大きく，100より小さい範囲（−20<x<100）とし，
  それ以外の値が一つでも入力された場合はOut of Rangeと出力して終了すること．
  最大値となるデータが複数ある場合は，そのうちの1つのみ除外すればよい．
  同様に，最小値となるデータが複数ある場合は，そのうちの1つのみ除外すればよい．
  出力する平均値はprintf関数のフォーマット指定子を用い，小数点以下2位までを出力すること．
  各表示は標準出力に書き出し，末尾には改行文字\nを付けること．

*/

#include<stdio.h>

int main(){
  double x[7];
  double min = 100;
  double max = -20;
  double sum = 0;

  for(int i=0; i<7; i++){
    scanf("%lf", &x[i]);
    if(x[i]<=-20 || x[i]>=100){
      printf("Out of Range");
      return 0;
    }else{
      printf("%.2lf\n", x[i]);
      if(x[i]<min){
        min = x[i];
      }
      if(x[i]>max){
        max = x[i];
      }
      sum += x[i];
    }
  }
  printf("max=%.2lf, min=%.2lf, sum=%.2lf\n", max, min, sum);
  printf("%.2lf\n", (sum-max-min)/5);

  return 0;
}