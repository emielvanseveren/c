#include <stdio.h>
#define COL 3
#define ROW 3

void lees_matrix(int [][COL], int, int);
void print_matrix(int [][COL], int, int);
void transponeer(int [][COL], int);
void vermenigvuldig_matrix(int [], int [][COL], int [][COL], int);

int main(){
    int matrix[ROW][COL]; //=9
    lees_matrix(matrix, ROW, COL);
    printf("Matrix\n");
    print_matrix(matrix, ROW, COL);

    printf("Product\n");
    int product[ROW]={0}; // product
    vermenigvuldig_matrix(product, matrix, matrix, ROW);
    print_matrix(product, ROW, COL);


    printf("Transponeer\n");
    transponeer(matrix, ROW);
    print_matrix(matrix,ROW,COL);


   return 0;
}

void vermenigvuldig_matrix(int product[], int m1[][COL], int m2[][COL], int dimensie){
    int i,j;
    for(i=0;i<dimensie;i++){
       for(j=0;j<dimensie;j++){
           product[i] += m1[i][j] * m2[j][i];
       }
    }
}

// Enkel vierkante matrix
void transponeer(int matrix[][COL], int dimensie){
    int i,j;
    for(i = 0; i<dimensie;i++){
        for(j=0; j<dimensie;j++){
           matrix[i][j] = matrix[j][i];
        }
    }
}

void lees_matrix(int matrix[][COL], int n_row , int n_col){
    int i, j;
    printf("geef getallen in");
    for(i=0;i<n_row;i++){
        for(j=0;j<n_col;j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int matrix[][COL], int n_row, int n_col){
    int i, j;
    for(i=0;i<n_row;i++){
        for(j=0;j<n_col;j++){
           printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Opmerkingen