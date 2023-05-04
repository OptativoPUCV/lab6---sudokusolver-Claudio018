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


    
    
    for(int i = 0 ; i < 9 ; i++)
    {
        int fila[10] = {};
        for(int j = 0 ; j < 9 ; j++){
            int num = n->sudo[i][j];
            if(fila[num] == 1)
                return 0;

            fila[num] = 1;

        }
    }

    for(int j = 0 ; j < 9 ; j++)
    {
        int columna[10] = {};
        for(int i = 0 ; i < 9 ; i++){
            int num = n->sudo[i][j];
            if(columna[num] == 1)
                return 0;

            columna[num] = 1;
        }
    }

    /*
    for (int k = 0; k < 9; k++) {
        int sudok[10] = {0};
        for (int p = 0; p < 9; p++) {
            int i = 3 * (k / 3) + (p / 3);
            int j = 3 * (k % 3) + (p % 3);
            int num = n->sudo[i][j];

            if (sudok[num] == 1) {
                return 0;
            }
            sudok[num] = 1;

        }
    
    */
    return 1;
}


/*
            for(int m = 0 ; m < 9 ; m++)
            { 
                if(filcol[n->sudo[i][m] - 1] == 0)
                    filcol[n->sudo[i][m] - 1] = 1;
                else
                {
                    if(filcol[n->sudo[m][j] - 1] == 0)
                        filcol[n->sudo[m][j] - 1] = 1;
                    else
                        return 0;
                }
            }
*/

List* get_adj_nodes(Node* n){
    List* list=createList();
    int i, j, k, num;
    
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