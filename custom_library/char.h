#ifndef ARRAY_H //二重でincludeされることを防ぐ
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

int vmax_(int x, int y);
int vmax3_(int a, int b, int c);

int vmin_(int x, int y);
int vmin3_(int a, int b, int c);

void zeros_(char* data, int N);

char* func_mallocation_char_(const int len_x);

char* read_string_(const int N);

int** func_mallocation_2d_(const int len_x, const int len_y);

void fun_free_2d_(int ** array_2d, int len_x);

#endif

#include <stdio.h>
#include <stdlib.h>

int vmax_(int x, int y){return x>y ? x : y;}
int vmax3_(int a, int b, int c){return vmax_(a,vmax_(b,c));}

int vmin_(int x, int y){return x<y ? x : y;}
int vmin3_(int a, int b, int c){return vmin_(a,vmin_(b,c));}

void zeros_(char* data, int N){
  for(int i=0; i<N; ++i){
    data[i]='\0';
  }
}

char* func_mallocation_char_(const int len_x){
  char* data = (char*)malloc((len_x+1) * sizeof(char));
  if(data == NULL){
    printf("Can not allocate memory.  'data' is Null.\n");
    exit(EXIT_FAILURE);
  }
  zeros_(data,len_x+1);
  return data;
}

char* read_string_(const int N){
  char* data = func_mallocation_char_(N);
  scanf("%s",data);
  if(data[N]!='\0'){
    printf("Reading invalid string\n");
    exit(1);
  }
  return data;
}

int** func_mallocation_2d_(const int len_x, const int len_y){
  int** array_2d = (int **)malloc(sizeof(int *)*len_x);
  if(array_2d==NULL){
    printf("Can not allocate memory.  'array_2d' is NULL.\n");
    exit(EXIT_FAILURE);
  }
  for(int i=0; i<len_x; i++){
    array_2d[i] = (int*)malloc(sizeof(int)*len_y);
    if(array_2d[i]==NULL){
      printf("Can not allocate memory.  'array_2d[i]' is NULL.\n");
      exit(EXIT_FAILURE);
    }
  }
  return array_2d;
}

void fun_free_2d_(int ** array_2d, int len_x){
  for(int i=0; i<len_x; i++){
    free(array_2d[i]);
  }
  free(array_2d);
}