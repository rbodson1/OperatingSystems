#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_THREADS 12
#define dim1 12 
#define dim2 12



//Declaring necessary global variables including 2D-array to store input and output matrices
int mat1[dim1][dim2];
int mat2[dim1][dim2] ;
int resultMat[dim1][dim2] ;
int r, c; //rows and columns

//Creating structure to store thread input info
 struct threadInput{
     pthread_t threads[NUM_THREADS];
     pthread_attr_t attr;
     int row;
     int column;
   };
 
// Function Declaration:
void *matrixMulter(void *params);
void matrixFunc(int(*arr1), int(*arr2));

//main function
int main(int argc, char *argv[]){

    char *file1;
    char *file2;
    FILE *f1;
    FILE *f2;
   
   file1 = argv[1];
   file2 = argv[2];

   if(argc!=3){
   fprintf(stderr,"Usage: ./filename <mat1> <mat2>\n");
   return -1;
	}
	
    //opening files to read
    f1 = fopen(file1, "r");
    if (f1 == NULL) {
        printf("Can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    f2 = fopen(file2, "r");
    if (f2 == NULL) {
        printf("Can't open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // read in the data and store in matrix_1 and matrix_2
    printf("Read matrix_1:\nRow: %d, col: %d\n",dim1,dim2);
    for (r = 0; r < dim1; r++)
        for (c = 0; c < dim2; c++)
            fscanf(f1, " %d", &mat1[r][c]); 
    printf("Read matrix_2:\nRow: %d, col: %d\n\n",dim1,dim2);        
    for (r = 0; r < dim1; r++)
        for (c = 0; c < dim2; c++)
            fscanf(f2, " %d", &mat2[r][c]); 
 


     
     //calling matrix function with pointers
     matrixFunc(&mat1[r][c],&mat2[r][c]);
	
    return 0;
} 

/*
 Functions that I created.
*/
void *matrixMulter(void *params)
{
    //Memory allocation for threadInput structure
    struct threadInput *info = malloc(sizeof(struct threadInput));
    info->row = r;
    info->column = c;
       
    // initializing resultMat
    for (r = 0  ; r < dim1 ; r++) 
        for ( c = 0; c < dim1 ;c++) 
           resultMat[r][c] = 0;
             
    // matrix multiplication
    for (info->row = 0  ; info->row < dim1 ; info->row++)
        for ( info->column = 0; info->column < dim1 ; info->column++)
            for (int k = 0; k < dim1; k++) 
                resultMat[info->row][info->column] += mat1[info->row][k] * mat2[k][info->column]; 
                
}

void matrixFunc(int(*arr1), int(*arr2)){

    //Memory allocation for threadInput structure
    struct threadInput *info = malloc(sizeof(struct threadInput));
    info->threads[NUM_THREADS];
    info->attr;
    
    pthread_attr_init(&info->attr);
   
    // Creating 12 threads
    printf("===== Thread Generation of %d Threads =====\n",NUM_THREADS);
    for ( int i = 1; i <= NUM_THREADS; i++) {
         int* p;
        printf("Creating thread no.%d\n",i);
        pthread_create(&info->threads[i], &info->attr, matrixMulter, (void*)(p));
        printf("Row %d calculation succeed!\n",i);
    }
  
    printf("\n\nThe final result has been generated!\n\n");
    
    // joining and waiting for all threads to complete
    for (int i = 1; i <= NUM_THREADS; i++) 
        pthread_join(info->threads[i], NULL);

    // Displaying matrix 1 
    printf("Matrix_1 =\n"); 
    for (r = 0; r < dim1; r++) {
        for (c = 0; c < dim2; c++)
            printf("%d ", mat1[r][c]);
        printf("\n");
    }
  
    printf("\n");

    //Displaying matrix 2
    printf("Matrix_2 =\n");
    for (r = 0; r < dim1; r++) {
        for (c = 0; c < dim2; c++)
            printf("%d ", mat2[r][c]);
        printf("\n");
    }
   
    printf("\n");
    // Displaying the result of matrix_1 * matrix_2
        printf("Matrix_1*Matrix_2 =\n");
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) 
             printf("%d ",resultMat[i][j]);
        printf("\n");
    }
	
}
