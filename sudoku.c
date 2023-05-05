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
    /*
    for(int k = 0 ; k < 9 ; k++)
    {
        int filcol[9] = {};
        int cuadrado[9] = {};
        
        for(int p = 0 ; p < 9 ; p++)
        {
            int i=3*(k/3) + (p/3) ;
            int j=3*(k%3) + (p%3) ;

            int numero = n->sudo[i][j];
            
            if(cuadrado[numero - 1] == 0)
                cuadrado[numero - 1] = 1;
            else
                return 0;


            if(filcol[n->sudo[i][p] - 1] == 1 || filcol[n->sudo[p][j] - 1] == 1)
                return 0;


            filcol[n->sudo[i][p] - 1] = 1;
            filcol[n->sudo[p][j] - 1] = 1;
            
            
        }
        
    }
    */
    
    


    int i, j;
    for(i = 0 ; i < 0 ; i++)
    {
        int filas[10] = {0};
        int columnas[10] = {0};

        for(j = 0 ; j < 9 ; j++)
        {
            if(n->sudo[i][j] != 0 && filas[n->sudo[i][j]] == 1) return 0;
            filas[n->sudo] = 1;

            if(n->sudo[j][i] != 0 && filas[n->sudo[j][i]] == 1) return 0;
            columnas[n->sudo] = 1;
        }
    }

    int k;

    for(k = 0 ; k < 9 ; k++)
    {
        int sudoku[10] = {0};
        for(p = 0 ; p < 9 ; p++)
        {
            int i=3*(k/3) + (p/3) ;
            int j=3*(k%3) + (p%3) ;
            //printf("%d ",nodo->sudo[i][j]);
            //if(p%3 == 2) printf("\n");
            
        }
    }

        
    }
    
    
    return 1;
}




List* get_adj_nodes(Node* n){
    List* list=createList();
    int i, j;

    for(i = 0 ; i < 9 ; i++)
    {
        for(j = 0 ; j < 9 ; j++)
        {
            if(n->sudo[i][j] == 0)
            {
                Node* adj = copy(n);
                for(int k = 1 ; k <= 9 ; k++)
                {
                    adj->sudo[i][j] = k;
                    if(is_valid(adj))
                        pushBack(list,adj);
                }
                
            } 
        }
    }  

    
    
    //int k, num;


    /*
    for (i = 0 ; i < 9 ; i++)
        for (j = 0 ; j < 9 ; j++)
        {
            if(n->sudo[i][j] == 0)
            {
                for (num = 1 ; num <= 9 ; num++)
                {
                    int valido = 1;
                    for(k = 0 ; k < 9 ; k++)
                        if(n->sudo[i][k] == num || n->sudo[k][j] == num)
                        {
                            valido = 0;
                            break;
                        }
                    
                    if(valido){
                        Node* adj = copy(n);
                        adj->sudo[i][j] = num;
                        pushBack(list,adj);
                        
                    }
                        
                }
                
            }
        
        }
    */
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