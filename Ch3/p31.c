//文字列間の共通文字列挙

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

int find_matching(char* X, int M, char *Y, int N, char* buf);
void sort_buf(char* buf, int N);

int main(){
  int len_x, len_y;
  scanf("%d",&len_x);
  scanf("%d",&len_y);
  char* data_x = read_string_(len_x);
  char* data_y = read_string_(len_y);
  char* buf = func_mallocation_char_(len_x*len_y);

  int cnt = find_matching(data_x, len_x, data_y, len_y, buf);

  sort_buf(buf, cnt);

  printf("%s %d\n",data_x, len_x);
  printf("%s %d\n",data_y, len_y);
  
  char prev='\0';
  for(int i=0; i<cnt; ++i){
    if(buf[i]==prev){
      continue;
    }
    printf("%c\n", buf[i]);
    prev = buf[i];
  }

  free(data_x);
  free(data_y);
  free(buf);
  return 0;
}

int find_matching(char* X, int len_x, char* Y, int len_y, char* buf){
  int cnt=0;
  for(int i=0; i<len_x; i++){
    for(int j=0; j<len_y; j++){
      if(X[i]==Y[j]){
        buf[cnt]=X[i];
        cnt++;
      }
    }
  }
  return cnt;
}

void sort_buf(char* buf, int N){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(buf[j-1]>buf[j]){
        buf[N] = buf[i];
        buf[i]=buf[j];
        buf[j]=buf[N];
      }
    }
  }
}