//編集距離(動的計画法)

#include <stdio.h>
#include <stdlib.h>
#include "../custom_library/char.h"

int delta(char *X, int a, char* Y, int b);
int ld_dp(char*X, int m, char*Y, int n, int  **dpt);
void print_array(char*X, int m, char*Y, int n, int  **dpt);

int main(){
  int len_x, len_y;
  scanf("%d",&len_x);
  scanf("%d",&len_y);
  char* data_x = read_string_(len_x);
  char* data_y = read_string_(len_y);
  int** dpt = func_mallocation_2d_(len_x+1, len_y+1);
  for(int i=0; i<=len_x; i++){
    dpt[i][0]=i;
  }
  for(int j=0; j<=len_y; j++){
    dpt[0][j]=j;
  }

  int c = ld_dp(data_x, len_x, data_y, len_y,dpt);

  printf("%s %d\n",data_x, len_x);
  printf("%s %d\n",data_y, len_y);
  printf("%d\n",c);
  print_array(data_x, len_x, data_y, len_y, dpt);
  
  fun_free_2d_(dpt, len_x+1);
  free(data_x);
  free(data_y);
  return 0;
}

int delta(char *X, int a, char* Y, int b){
  if(X[a-1]==Y[b-1]){
    return 0;
  }else{
    return 1;
  }
}

int ld_dp(char*X, int m, char*Y, int n, int** dpt){
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      dpt[i][j]=vmin3_(dpt[i-1][j-1]+delta(X,i,Y,j),dpt[i-1][j]+1, dpt[i][j-1]+1);
    }
  }
  return dpt[m][n];
}

void print_array(char*X, int m, char*Y, int n, int  **dpt){
  printf("dpt:\n");
  printf("i\\j  ");
  for(int j=0; j<=n; j++){
    printf(" %d",j);
  }
  printf("\n");
  printf("\n");
  for(int i=0; i<=m; i++){
    printf(" %d   ",i);
    for(int j=0; j<=n; j++){
      printf("%2d",dpt[i][j]);
    }
    if(i>0){
      printf("   %c",X[i-1]);
    }
    printf("\n");
  }
  printf("\n       ");
  for(int j=0; j<n; j++){
    printf(" %c",Y[j]);
  }
}


//↖replace/copy  ↑delete
//←insert

//delta==1（別の文字）⇒replace
//delta==0（同じ文字）⇒copy