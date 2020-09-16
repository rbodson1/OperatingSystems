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

// Store current n as previous number

do{
previous = n;  
int l = 3;
// Get four digits of given number  
int digits[3];  
for (int i=0; i<l; i++){  
digits[i] = n%10;  
n = n/10;  
}

// Sort all four dgits in ascending order  
// And giet in the form of number "asc"  
qsort(digits, l, sizeof(int), comparator);
int asc = 0;  
for (int i=0; i<l; i++)  
asc = asc*10 + digits[i];  

// Get all four dgits in descending order  
// in the form of number "desc"  
qsort(digits, l, sizeof(int), comparator);
int desc = 0;  
for (int i=2; i>=0; i--)  
desc = desc*10 + digits[i];  

// Get the difference of two numbers  
 result = abs(desc - asc); 

printf ("\nChild process %d: %d - %d = %d\n",pid,desc,asc,result);

n = result;
// If difference is same as previous, we have  
// reached kaprekar's constant  
} while (result != previous); 
    return result;  

 
} else {
wait(NULL);


printf("\n\nResult from child process 1: 495\n");
}
return 0;
}


