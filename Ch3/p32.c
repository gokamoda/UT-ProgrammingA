//編集距離(再帰版)

#include <stdio.h>
#include <stdlib.h>
#include "../custom_library/char.h"

int delta(char *X, int a, char* Y, int b);
int ld(char*X, int m, char*Y, int n);

int main(){
  int len_x, len_y;
  scanf("%d",&len_x);
  scanf("%d",&len_y);
  char* data_x = read_string_(len_x);
  char* data_y = read_string_(len_y);
  char* buf = func_mallocation_char_(len_x*len_y);

  int c = ld(data_x, len_x, data_y, len_y);

  printf("%s %d\n",data_x, len_x);
  printf("%s %d\n",data_y, len_y);
  printf("%d\n",c);
  
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
  if(m==0||n==0){
    return vmax_(m,n);
  }else{
    return vmin3_(ld(X,m-1,Y,n-1)+delta(X,m,Y,n),ld(X,m-1,Y,n)+1,ld(X,m,Y,n-1)+1);
  }
}