
#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>



buffer_item buffer[BUFFER_SIZE];

pthread_mutex_t mutex;
sem_t empty;
sem_t full;

int insertion = 0;
int deletion = 0;

pthread_t tid;
pthread_attr_t attr;


void *producer(void *param);
void *consumer(void *param);

int insert_item(buffer_item item)
{
       
    	/* Acquire Empty Semaphore */
    	sem_wait(&empty);
		
	/* Acquire mutex lock to protect buffer */
	pthread_mutex_lock(&mutex);
	
	/* Insert item into buffer */
	if (insertion < BUFFER_SIZE) {
	buffer[insertion] = item;
	printf("Producer %u produced %d at position %d...  ",(unsigned int)pthread_self(), item,insertion);
	buffer[insertion++] = item;
	insertion = insertion % BUFFER_SIZE;
	
	printf("...[");
	for(int i = 0; i< BUFFER_SIZE ;i++){
	printf("%s%d", i ? ", " : "",buffer[i]);
	}
	printf("]\n");
	} else {
	    return -1;
	}
    
	/* Release mutex lock and full semaphore */
	pthread_mutex_unlock(&mutex);
        sem_post(&full);
      
	return 0;
}

int remove_item(buffer_item *item)
{       
	/* Acquire Full Semaphore */
	sem_wait(&full);

	/* Acquire mutex lock to protect buffer */
	pthread_mutex_lock(&mutex);
	
	/* remove an object from buffer placing it in item */
	if (insertion > 0) {
	*item = buffer[deletion];
	printf("Consumer %u consumed %d at position %d...  ",(unsigned int)pthread_self(), *item,deletion);
	buffer[deletion++] = -1;
	deletion = deletion % BUFFER_SIZE;
	
	printf("...[");
	for(int i = 0; i< BUFFER_SIZE ;i++){
	printf("%s%d", i ? ", " : "",buffer[i]);
	}
	printf("]\n");
        } else {
        return -1;
         }
     
	/* Release mutex lock and empty semaphore */
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
	
	
	return 0;
}


int main(int argc, char *argv[])
{
        int sleepTime; 
	int numOfProducer; 
	int numOfConsumer;

        pthread_attr_init(&attr);
	
	if(argc != 4)
	{
		fprintf(stderr, "Useage: <sleepTime> <producer> <consumer>\n");
		return -1;
	}
	/* Get command line arguments argv[1],argv[2],argv[3] */
	sleepTime = atoi(argv[1]);
	numOfProducer = atoi(argv[2]);
	numOfConsumer = atoi(argv[3]);
	
	/* Initialize buffer related synchronization tools */
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);
	srand(time(0));
	/* Create producer threads based on the command line input */
	for(int i = 0; i < numOfProducer; i++)
	{
		pthread_create(&tid, &attr, producer, NULL);
		
	}
	/* Create consumer threads based on the command line input */
        for(int j = 0; j < numOfConsumer; j++)
	{
		pthread_create(&tid, &attr, consumer, NULL);
		
	}
	/* Sleep for user specified time based on the command line input */
	sleep(sleepTime);
	
	return 0;
}

void *producer(void *param)
{
        buffer_item item;
	/* producer thread that calls insert_item() */
        while(1)
	{
	        
		sleep( rand() % 5);
		item = (rand() % 9)+1;
                
		if(insert_item(item))
			fprintf(stderr, "Error");	
                
	}

}

void *consumer(void *param)
{
        buffer_item item;
	/* consumer thread that calls remove_item() */
        while(1)
	{
		
		sleep( rand() % 5);
               item = (rand() % 9)+1;
               
		if(remove_item(&item))
		  fprintf(stderr," ");
	
     }
	
}
