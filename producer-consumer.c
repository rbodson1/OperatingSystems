/* Author : Teja Sasank Gorthi
   Email  : jet.sasank@gmail.com */

/**
 *
 * This is a POSIX solution using unnamed semaphores.
 * 
 * This solution will not work on OS X systems, 
 * but will work with Linux.
 * Design a programming solution to the bounded-buffer problem using the producer and consumer processes. 
 * Use standard counting semaphores for empty and full and a mutex lock to represent mutex. 
 *The producer and consumer—running as separate threads—will move items to and from a buffer that is synchronized with the empty, full, and mutex structures.
 */

#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define TRUE 1

buffer_item buffer[BUFFER_SIZE];

pthread_mutex_t mutex;
sem_t empty;
sem_t full;

int insertPointer = 0, removePointer = 0;

void *producer(void *param);
void *consumer(void *param);

int insert_item(buffer_item item)
{
        int return_val = 0;   
	sem_wait(&empty);

	pthread_mutex_lock(&mutex);
	if (insertPointer < BUFFER_SIZE) {
	buffer[insertPointer++] = item;
	insertPointer = insertPointer % 5;
	} else {
	    return_val = -1;
	}
	pthread_mutex_unlock(&mutex);
        sem_post(&full);

	return return_val;	
}

int remove_item(buffer_item *item)
{
	int return_val;
	sem_wait(&full);

	pthread_mutex_lock(&mutex);
	if (insertPointer > 0) {
	*item = buffer[removePointer];
	buffer[removePointer++] = -1;
	removePointer = removePointer % 5;
    } else {
        return_val = -1;
    }
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);

	return return_val;	
}


int main(int argc, char *argv[])
{
	int sleepTime, producerThreads, consumerThreads;
	int i, j;

	if(argc != 4)
	{
		fprintf(stderr, "Useage: <sleep time> <producer threads> <consumer threads>\n");
		return -1;
	}
	
	
	
	
	
	
	
	
	
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "buffer.h"

// Global variables
buffer_item buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t full, empty;
int count, in, out;

// Function prototypes
int insert_item(buffer_item item);
int remove_item(buffer_item *item);
void *consumer(void *param);
void *producer(void *param);

int main(int argc, char **argv){
  if (argc != 4){
    printf("ERROR: Provide exactly three arguments.\n");
    exit(1);
  }

  // Retrieve command line arguments
  const long int stime = strtol(argv[1], NULL, 0);
  const long int num_producer = strtol(argv[2], NULL, 0);
  const long int num_consumer = strtol(argv[3], NULL, 0);

  // Initialize
  int i;
  srand(time(NULL));
  pthread_mutex_init(&mutex, NULL);
  sem_init(&empty, 0, BUFFER_SIZE); // All of buffer is empty
  sem_init(&full, 0, 0);
  count = in = out = 0;

  // Create the producer and consumer threads
  pthread_t producers[num_producer];
  pthread_t consumers[num_consumer];
  for(i = 0; i < num_producer; i++)
    pthread_create(&producers[i], NULL, producer, NULL);
  for(i = 0; i < num_consumer; i++)
    pthread_create(&consumers[i], NULL, consumer, NULL);

  // Sleep before terminating
  sleep(stime);
  return 0;
}

// Insert item into buffer.
//Returns 0 if successful, -1 indicating error
int insert_item(buffer_item item){
  int success;
  sem_wait(&empty);
  pthread_mutex_lock(&mutex);

  // Add item to buffer
  if( count != BUFFER_SIZE){
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    count++;
    success = 0;
  }
  else
    success = -1;

  pthread_mutex_unlock(&mutex);
  sem_post(&full);
  
  return success;
}

// Remove an object from the buffer, placing it in item.
// Returns 0 if successful, -1 indicating error
int remove_item(buffer_item *item){
  int success;
  
  sem_wait(&full);
  pthread_mutex_lock(&mutex);
  
  // Remove item from buffer to item
  if( count != 0){
    *item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;
    success = 0;
  }
  else
    success = -1;

  pthread_mutex_unlock(&mutex);
  sem_post(&empty);
  
  return success;
}

void *producer(void *param){
  buffer_item item;
  while(1){
    sleep(rand() % 5 + 1); // Sleep randomly between 1 and 5 seconds
    
    item = rand();
    if(insert_item(item))
      printf("Error occured\n");
    else
      printf("Producer produced %d\n", item);
  }
}


void *consumer(void *param){
  buffer_item item;
  while(1){
    sleep(rand() % 5 + 1); // Sleep randomly between 1 and 5 seconds

    if(remove_item(&item))
      printf("Error occured\n");
    else
      printf("Consumer consumed %d\n", item);
  }
}
