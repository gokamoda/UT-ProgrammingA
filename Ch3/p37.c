#include<stdio.h>
#include<stdlib.h>
#include "../custom_library/char.h"

void print_matrix(int N, int ** data);
int rec(int N, int** data);
int check_invalid(int N, int ** data);

int main(){
  int N=9;
  int ** data = func_mallocation_2d_(N,N);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      scanf("%d",&data[i][j]);
    }
  }
  printf("### INIT\n");
  print_matrix(N, data);
  int invalid = check_invalid(N, data);
  if(invalid!=0){
    printf("### INVALID INPUT\n");
    return 0;
  }
  if(rec(N,data)==1){
    printf("### FOUND\n");
    print_matrix(N, data);
  }else{
    printf("### NOT FOUND\n");
  }
  fun_free_2d_(data, N);
  return 0;
}

void print_matrix(int N, int ** data){
  printf("   #1 #2 #3 #4 #5 #6 #7 #8 #9\n");
  for(int i=0; i<N; i++){
    printf("#%d",i+1);
    for(int j=0; j<N;j++){
      printf(" %2d",data[i][j]);
    }
    printf("\n");
  }
}

int rec(int N, int** data){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(data[i][j]!=0){
        continue;
      }else{
        for(int a=1; a<=N; a++){
          data[i][j]=a;
          int c = check_invalid(N, data);
          int r = 2;
          if(c==0){
            r = rec(N,data);
          }
          if(c==1||r==0){
            data[i][j]=0;
            if(a==N){
              return 0;
            }
          }
          if(r==1){
            return 1;
          }
        }
      }
    }
  }
  return 1;
}

int check_invalid(int N, int ** data){
  int top, left;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(data[i][j]==0){
        continue;
      }

      for(int k=i+1; k<N; k++){
        if(data[i][j]==data[k][j]){
          return 1;
        }
      }

      for(int l=j+1; l<N; l++){
        if(data[i][j]==data[i][l]){
          return 1;
        }
      }

      top=3*(i/3);
      left=3*(j/3);
      for(int k=0; k<3; k++){
        if(i==top+k){
          continue;
        }
        for(int l=0; l<3; l++){
          if(j==left+l){
            continue;
          }
          if(data[i][j]==data[top+k][left+l]){
            return 1;
          }
        }
      }
    }
  }
  return 0;
}