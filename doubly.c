#include <stdio.h>
#define MAX 5
 
//Declaration of Dequeue.
typedef struct
{
    int front   ;
    int rear    ;
    int count   ;
    int ele[MAX]    ;
}DQueue;
 
//Initailization of Dequeue.
void initDQueue(DQueue * q)
{
    q->front =  0;
    q->rear  = -1;
    q->count =  0;
}
 
//Check Dequeue is full or not
int isFull(DQueue * q)
{
    int full=0;
     
    if(q->count == MAX)
        full = 1;   
 
    return full;
}
 
//Check Dequeue is empty or not
int isEmpty(DQueue * q)
{
    int empty=0;
     
    if(q->count == 0)
        empty = 1;  
 
    return empty;
}
 
//To insert item into Dequeue at rear.
void insertDQueueAtRear(DQueue * q, int item)
{
    if( isFull(q) )
    {
        printf("\nQueue Overflow");
        return;
    }
     
    q->rear = (q->rear+1)%MAX;
    q->ele[q->rear] = item;
     
    q->count++;
  
    printf("\nAfter insert At Rear FRONT : %d, REAR : %d",q->front,q->rear);
    printf("\nInserted item : %d\n",item);
}
 
//To delete item from Dequeue at front.
int deleteDQueueAtFront(DQueue * q, int *item)
{
    if( isEmpty(q) )
    {
        printf("\nQueue Underflow");
        return -1;
    }
 
    *item    = q->ele[q->front];
 
    q->front = (q->front+1)%MAX;
     
    q->count--;
 
    printf("\nAfter Delete At Front FRONT : %d, REAR : %d",q->front,q->rear);
    return 0;
}
 
//To insert item into Dequeue at front.
void insertDQueueAtFront(DQueue * q, int item)
{
    if( isFull(q) )
    {
        printf("\nQueue Overflow");
        return;
    }
     
    if ( q->front == 0)
        q->front = MAX - 1;
    else
        q->front = q->front - 1;
    q->ele[q->front] = item;
     
    q->count++;
    printf("\nAfter Insert At Front FRONT : %d, REAR : %d",q->front,q->rear);
    printf("\nInserted item : %d\n",item);
}
 
//To delete item from Dequeue at rear.
int deleteDQueueAtRear(DQueue * q, int *item)
{
    if( isEmpty(q) )
    {
        printf("\nQueue Underflow");
        return -1;
    }
 
    *item = q->ele[q->rear];
 
    if(q->rear == 0)
        q->rear = MAX - 1;
    else
        q->rear = q->rear - 1;
 
    printf("\nAfterDeleteAtRear FRONT : %d, REAR : %d",q->front,q->rear);
    q->count--;  
    return 0;
}
