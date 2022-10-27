/*
三目並べ
  三目並べ（oxゲーム）を管理・運営するプログラムを作成しよう．

問題
  以下の処理を行うプログラムを実装せよ．

  盤面を表示する．
  プロンプトを表示する．
  標準入力から「o」（英小文字の「オー」）もしくは「x」（英小文字の「エックス」）を置く場所（を表す数字）を読み込む．
  勝利および引き分け判定を行い，勝負が決着もしくは引き分けた盤面を表示し，その旨を表示してプログラムを終了する．
  1に戻る．
  盤面の初期状態は次の通りに表示する．
*/

#include<stdio.h>

int main(){
  int input;
  char disp[9]={'1','2','3','4','5','6','7','8','9'};
  int proc[9]={0,0,0,0,0,0,0,0,0};
  int a;
  int turn=1;
  char ox[3]={'x','-','o'};
  int win=1;
    printf("%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n", 
    disp[6],disp[7],disp[8], disp[3],disp[4],disp[5], disp[0],disp[1],disp[2]);

  for(int i=0; i<9; i++){
    while(1){
      printf("%c>", ox[turn+1]);
      scanf("%d", &input);
      printf(" \n");
      if(proc[input-1]==1 || input<=0 || input>=10){
        printf("ERROR\n");
      }else{
        break;
      }
    }
    proc[input-1]=turn;
    disp[input-1]=ox[turn+1];
    printf("%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n", 
    disp[6],disp[7],disp[8], disp[3],disp[4],disp[5], disp[0],disp[1],disp[2]);
    win=
    (proc[0]+proc[1]+proc[2]-3*turn)*
    (proc[3]+proc[4]+proc[5]-3*turn)*
    (proc[6]+proc[7]+proc[8]-3*turn)*
    (proc[0]+proc[3]+proc[6]-3*turn)*
    (proc[1]+proc[4]+proc[7]-3*turn)*
    (proc[2]+proc[5]+proc[8]-3*turn)*
    (proc[0]+proc[4]+proc[8]-3*turn)*
    (proc[2]+proc[4]+proc[6]-3*turn);
    if(win==0){
      printf("%c win!\n",ox[turn+1]);
      return 0;
    }
    turn*=-1;
  }
  printf("even.\n");
  return 0;
}