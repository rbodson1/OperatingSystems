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
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/errno.h>

#include "buffer.h"

buffer_item buffer[BUFFER_SIZE];
int count, in, out = 0;

//mutex lock
pthread_mutex_t mutex;

//semaphores
sem_t full, empty;

void* producer(void *ptr) {

	buffer_item item;
	while(1) {
		/* sleep for a random period of time */
		int rNum = rand() % 10 + 10;
		sleep(rNum);

		//generate random number to insert
		item = rand() / 1000000;

		//wait to acquire sem
		sem_wait(&empty);

		//acquire mutex
		pthread_mutex_lock(&mutex);
		//printf("mutex aquired: mutex=%d\n", mutex);

		insert_item(item);

		/* release the mutex lock */
		pthread_mutex_unlock(&mutex);
		//printf("mutex released: mutex=%d\n", mutex);

		/* signal full */
		sem_post(&full);
   }
}

void* consumer(void *ptr) {

	while(1) {
		/* sleep for a random period of time */
		int rNum = rand() % 10 + 10;
		sleep(rNum);

		/* aquire the full lock */
		sem_wait(&full);
		/* aquire the mutex lock */
		pthread_mutex_lock(&mutex);
		remove_item();

		/* release the mutex lock */
		pthread_mutex_unlock(&mutex);
		//printf("mutex released: mutex=%d\n", mutex);

		/* signal empty */
		sem_post(&empty);
	}
}


int main(int argc, char *argv[]) {

	/* 1. Get command line arguments argv[1],argv[2],argv[3] */
	if (argc != 4) {
		printf("Incorrect number of aguments. Usage:\n");
		printf("producerconsumer <time to sleep before terminating> <number of producers> <number of consumers>\n");
		return -1;
	}

	int timeToSleep = atoi(argv[1]);
	int numProducerThreads = atoi(argv[2]);
	printf("Producer threads %i\n", numProducerThreads);
	int numConsumerThreads = atoi(argv[3]);
	printf("Consumer threads %i\n", numConsumerThreads);


	//create mutex
   pthread_mutex_init(&mutex, NULL);

	//create 'full' semaphore == 0
	if (sem_init(&full, 0, 0) == -1) {
		fprintf(stderr, "Error creating full semaphore %d\n", errno);
		return -1;
	}

	//create 'empty' semaphore == BUFFER_SIZE
	if (sem_init(&empty, 0, BUFFER_SIZE) == -1) {
		fprintf(stderr, "Error creating empty semaphore %d\n", errno);
		return -1;
	}
	
	/* 3. Create producer thread(s) */
	pthread_t producers[numProducerThreads];
	for (int i = 0; i < numProducerThreads; i++) {
		pthread_create(&producers[i], NULL, producer, NULL);
	}

	/* 4. Create consumer thread(s) */
	pthread_t consumers[numConsumerThreads];
	for (int j = 0; j < numConsumerThreads; j++) {
		pthread_create(&consumers[j], NULL, consumer, NULL);
	}
	
	/* 5. Sleep */
	printf("Time to sleep: %i\n", timeToSleep);
	sleep(timeToSleep);

	// kill threads
	for (int i = 0; i < numProducerThreads; i++) {
		pthread_kill(&producers[i], 0);
	}

	for (int i = 0; i < numConsumerThreads; i++) {
		pthread_kill(&consumers[i], 0);
	}

	/* 6. Exit */
	return 0;
}

int insert_item(buffer_item item) {

	/* produce an item in next produced */
	while (count == BUFFER_SIZE) {
		/* do nothing */
	}

	buffer[in] = item;
	in = (in + 1) % BUFFER_SIZE;
	printf("Thread id: %u Producer inserting item: %i...", pthread_self(), item);
	count++;
	printf("...Success. Count=%d\n", count);
}

int remove_item() {
	buffer_item item;
	
	while(count == 0){
		//do nothing
	}
   
    item = buffer[out];
	out = (out+1) % BUFFER_SIZE;
	printf("Thread id: %u Consumer removing item: %i...", pthread_self(), item);
    count--;
	printf("...Success. Count=%d\n", count);
}

	sleepTime = atoi(argv[1]);
	producerThreads = atoi(argv[2]);
	consumerThreads = atoi(argv[3]);

	/* Initialize the synchronization tools */
	printf("%d\n",pthread_mutex_init(&mutex, NULL));
	printf("%d\n",sem_init(&empty, 0, 5));
	printf("%d\n",sem_init(&full, 0, 0));
	srand(time(0));

	/* Create the producer and consumer threads */
	for(i = 0; i < producerThreads; i++)
	{
		pthread_t tid;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&tid, &attr, producer, NULL);
	}

	for(j = 0; j < consumerThreads; j++)
	{
		pthread_t tid;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&tid, &attr, consumer, NULL);
	}

	/* Sleep for user specified time */
	sleep(sleepTime);
	return 0;
}

void *producer(void *param)
{
	buffer_item random;
	int r;

	while(TRUE)
	{
		r = rand() % 5;
		sleep(r);
		random = rand();

		if(insert_item(random))
			fprintf(stderr, "Error");

		printf("Producer produced %d \n", random);

	}

}

void *consumer(void *param)
{
	buffer_item random;
	int r;

	while(TRUE)
	{
		r = rand() % 5;
		sleep(r);

		if(remove_item(&random))
			fprintf(stderr, "Error Consuming");
		else
			printf("Consumer consumed %d \n", random);
	}
}
