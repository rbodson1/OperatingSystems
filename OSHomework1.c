#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define BUFFER_SIZE 10
#define READ_END 0
#define WRITE_END 1



int comparator (const void * p1, const void * p2)
{
return (*(long*)p1 - *(long*)p2);
}

int main(int argc, char *argv[]){

int n;
pid_t pid;
int previous = 0;
int result = 0;
int child = 0;
int fd[2];
int ith = 1;

if(pipe(fd) == -1){
   fprintf(stderr,"PIPE FAILED");
   return 1;
   }
if (argc == 1) {
	fprintf(stderr,"Usage: ./hw1 <starting value>\n");
	
	return -1;
}

pid = fork();
n = atoi(argv[1]); // n is the input starting value

if(pid < 0){
fprintf(stderr, "Fork Failed");
return 1;

} else if( pid == 0){

execlp("bin/ls","ls",NULL);
  
do{
previous = n;  
int l = 3;

// get the digits 
int digits[3];  
for (int i=0; i<l; i++){  
digits[i] = n%10;  
n = n/10;  
}

// Sorting the digits in ascending order  
qsort(digits, l, sizeof(int), comparator);
int asc = 0;  
for (int i=0; i<l; i++)  
asc = asc*10 + digits[i];  
 
 // sorting the digits in descending order 
qsort(digits, l, sizeof(int), comparator);
int desc = 0;  
for (int i=2; i>=0; i--)  
desc = desc*10 + digits[i];  

// Get the difference of two numbers as the result 
 result = abs(desc - asc); 

printf ("\nChild process %d: %dth: %d - %d = %d\n",getpid(),ith,desc,asc,result);

n = result;
ith++;

} while (result != previous);
 // write the result of the child process into the pipe
    close(fd[0]); 
    write(fd[1],&result, 3);
    close(fd[1]);
    return result;  

} else {
wait(NULL);
 // read result of the child process from pipe
    close(fd[1]);
    read(fd[0],&child, 3); 
    close(fd[0]);
printf("\n\nResult from child process 1: %d\n",child);
}
return 0;
}
