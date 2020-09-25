#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_THREADS 12
#define dim1 12 
#define dim2 12



//Declare necessary global variables including 2D-array to store input and output matrices
int mat1[dim1][dim2];
int mat2[dim1][dim2] ;
int matC[dim1][dim2] ;
int r, c; //rows and columns
int step_i = 0;

/*
 Create structure to store thread input info
 */
 
 


// Function Declaration:
//void *matrixMulter(void *params);
void* multi(void* arg);
void matrixFunc(int(*arr1), int(*arr2));



int main(int argc, char *argv[]){
//pid_t pid;



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

    // read in the matrix
    for (r = 0; r < dim1; r++)
        for (c = 0; c < dim2; c++)
            fscanf(f1, " %d", &mat1[r][c]); 

            
    for (r = 0; r < dim1; r++)
        for (c = 0; c < dim2; c++)
            fscanf(f2, " %d", &mat2[r][c]); 
    
 

     matrixFunc(&mat1[r][c],&mat2[r][c]);


	
    return 0;
} 

/*
 Create your functions here..

*/
void* multi(void* arg)
{
    int core = step_i++;
  
    // Each thread computes 1/4th of matrix multiplication
    for (r = 0  ; r < dim1 ; ++r) 
        for ( c = 0; c < dim1 ; ++c) 
           //matC[r][c] = 0;
            for (int k = 0; k < dim1; ++k) 
                matC[r][c] += mat1[r][k] * mat2[k][c]; 
                
                
 
}


void matrixFunc(int(*arr1), int(*arr2)){



  // Displaying matrix 1  
    for (r = 0; r < dim1; r++) {
        for (c = 0; c < dim2; c++)
            printf(" %d", mat1[r][c]);
        printf("\n");
    }
  
  printf("\n\n");


    //Displaying matrix 2
    for (r = 0; r < dim1; r++) {
        for (c = 0; c < dim2; c++)
            printf(" %d", mat2[r][c]);
        printf("\n");
    }
   
    
    
  
    // declaring four threads
    pthread_t threads[NUM_THREADS];
  
    // Creating four threads, each evaluating its own part
    for (int i = 0; i < NUM_THREADS; i++) {
         int* p;
        pthread_create(&threads[i], NULL, multi, (void*)(p));
    }
  
    // joining and waiting for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) 
        pthread_join(threads[i], NULL); 	
  
    // Displaying the result matrix
    printf("\n");
         printf("Multiplication of A and B\n");
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) 
             printf("%d ",matC[i][j]);
        printf("\n");
    }
    
      
	
	
    }
    







