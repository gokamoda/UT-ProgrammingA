//編集距離(再帰+メモ化)

#include <stdio.h>
#include <stdlib.h>
#include "../custom_library/char.h"
int count=0;
int countm=0;
int delta(char *X, int a, char* Y, int b);
int ld(char*X, int m, char*Y, int n);
int ldmemo(char*X, int m, char*Y, int n, int** memo);

int main(){
  int len_x, len_y;
  scanf("%d",&len_x);
  scanf("%d",&len_y);
  char* data_x = read_string_(len_x);
  char* data_y = read_string_(len_y);
  char* buf = func_mallocation_char_(len_x*len_y);
  int** memo = func_mallocation_2d_(len_x+1, len_y+1);
  for(int i=0; i<=len_x; i++){
    for(int j=0; j<=len_y; j++){
      if(i==0){
        memo[i][j]=j;
      }else if(j==0){
        memo[i][j]=i;
      }else{
        memo[i][j]=-1;
      } 
    }
  }

  int c = ld(data_x, len_x, data_y, len_y);
  int cm = ldmemo(data_x, len_x, data_y, len_y, memo);

  printf("%s %d\n",data_x, len_x);
  printf("%s %d\n",data_y, len_y);
  printf("%d %d\n",c, count);
  printf("%d %d\n",cm, countm);
  
  free(data_x);
  free(data_y);
  free(buf);
  return 0;
}

int delta(char *X, int a, char* Y, int b){
  if(X[a-1]==Y[b-1]){
    return 0;
  }else{
    return 1;
  }
}

int ld(char*X, int m, char*Y, int n){
  count++;
  if(m==0||n==0){
    return vmax_(m,n);
  }else{
    return vmin3_(ld(X,m-1,Y,n-1)+delta(X,m,Y,n),ld(X,m-1,Y,n)+1,ld(X,m,Y,n-1)+1);
  }
}

int ldmemo(char*X, int m, char*Y, int n, int** memo){
  countm++;
  if(memo[m][n]==-1){
    if(memo[m-1][n-1]==-1){
      ldmemo(X,m-1,Y,n-1,memo);
    }
    if(memo[m][n-1]==-1){
      ldmemo(X,m,Y,n-1,memo);
    }
    if(memo[m-1][n]==-1){
      ldmemo(X,m-1,Y,n,memo);
    }
    memo[m][n] = vmin3_(memo[m-1][n-1]+delta(X,m,Y,n),memo[m-1][n]+1,memo[m][n-1]+1);
  }
  return memo[m][n];
}