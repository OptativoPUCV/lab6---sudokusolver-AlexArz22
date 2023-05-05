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
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
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
  
  for (int k=0; k<9; k++){
    int *a=calloc(9,sizeof(int));
    for(int p=0;p<9;p++){
      int i=3*(k/3) + (p/3);
      int j=3*(k%3) + (p%3);
      if(a[(n->sudo[i][j])-1]==0){
        a[(n->sudo[i][j])-1]=1;
      } 
      else return 0;
    } 
  } 
  
  for(int i=0; i<9; i++){
    int *a=calloc(9,sizeof(int));
    for(int j=0; j<10; j++){
      if(a[(n->sudo[i][j])-1]==0){
        a[(n->sudo[i][j])-1]=1;
      } 
      else return 0;
    }
  }
  
  for(int i=0; i<9; i++){
    int *a=calloc(9,sizeof(int));
    for(int j=0; j<10; j++){
      if(a[(n->sudo[j][i])-1]==0) {
        a[(n->sudo[i][j])-1]=1;
      }
      else return 0;
    }
  }

  return 1;//valido
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  for(int j=0; j<9; j++){
    for(int k=0; k<9; k++){
      if(n->sudo[j][k]==0){
        for(int i=1; i<=9; i++){
          Node *aux=copy(n);
          aux->sudo[j][k]=i; 
          pushBack(list, aux);
        }
        return list;
      }
    }
  }
  return list;
}


int is_final(Node* n){
    return 0;
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