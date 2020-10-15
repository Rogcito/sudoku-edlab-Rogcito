#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          fscanf (file, "%d", &n->sudo[i][j]);
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
    int i,j,k,p;
    for(k=0;k<9;k++){
      int num[10]={0,0,0,0,0,0,0,0,0,0};
      for(p=0;p<9;p++){
        i=3*(k/3)+(p/3);
        j=3*(k%3)+(p%3);
        if(n->sudo[i][j]!=0){
          if(num[n->sudo[i][j]-1]==0){
            num[n->sudo[i][j]-1]=n->sudo[i][j];
          }else{
            return 0;
          }
          int x,y;
          int cont=0;
          for(x=0;x<9;x++){
            if(n->sudo[i][j]==n->sudo[x][j]){
              cont++;
            }
          }
          if(cont!=1)return 0;
          cont=0;
          for(y=0;y<9;y++){
            if(n->sudo[i][j]==n->sudo[i][y]){
              cont++;
            }
          }
          if(cont!=1)return 0;
        }
      }
    }

    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int i,j,k;  
    for (i=0;i<9;i++){      
      for (j=0;j<9;j++){        
        if (n->sudo[i][j] == 0){
          for (k=1;k<=9;k++){
            Node* adj_node=copy(n);
            adj_node->sudo[i][j]=k;
            if(is_valid(adj_node))pushBack(list, adj_node);
          }
          return list;
        }
      }
    }
    return list;

}


int is_final(Node* n){
    int i,j;
    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
        if(n->sudo[i][j]==0){
          return 0;
        }
      }
    }
    return 1;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/