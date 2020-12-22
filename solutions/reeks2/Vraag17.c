
#include <stdio.h>
#define N 10 //maximale grootte

void lees_matrix(int mat[ ][N], int aant_rij, int aant_kol){ 
    int i, j;
    for (i=0; i<aant_rij; i++){
    	for(j=0; j<aant_kol; j++){    		
    		printf("mat[%d,%d]=", i, j);
    		scanf ("%d" , &mat[i][j] );
		}
	}
}

void print_matrix(int mat[ ][N], int aant_rij, int aant_kol){ 
    int i, j;
    for (i=0; i<aant_rij; i++){
    	for(j=0; j<aant_kol; j++){
    		printf("%d\t", mat[i][j] );
		}
		printf("\n");
	}
}

void transponeer_matrix(int mat[ ][N], int dim){ 
    int i, j, h;
    for (i=0; i<dim; i++){
    	for(j=i+1; j<dim; j++){
    		h = mat[i][j];
    		mat[i][j] = mat[j][i];
    		mat[j][i] = h;
		}
	}
}

void vermenigvuldig_matrix(int product[][N], int matrix1[][N], int matrix2[][N],int dim){
	int i, j, k, som;
    for (i=0; i<dim; i++){
    	for(j=0; j<dim; j++){
    		som = 0;
    		for(k=0;k<dim;k++){
    			som = som + matrix1[i][k] * matrix2[k][j];
			}
    		product[i][j] = som;
		}
	}
}


int main(){
    int matrix[N][N];
    int matrix2[N][N];
    int product[N][N];
    lees_matrix(matrix,2,2);
    printf("lees tweede matrix\n");
    lees_matrix(matrix2,2,2);
    transponeer_matrix(matrix,2);
    vermenigvuldig_matrix(product,matrix,matrix2,2);
    
    printf("matrix 1 getransponeerd\n");
    print_matrix(matrix,2,2);
    printf("matrix 2 \n");    
    print_matrix(matrix2,2,2);
    printf("produkt \n");    
    print_matrix(product,2,2);
    
    return 0;
}
