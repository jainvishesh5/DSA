#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue{
    int *front;
    int*rear;
    int *array;
    int capacity;
    int size;
}queue;

void initQueue(queue *list , int capacity){
    list->size = 0;
    list->capacity = capacity;
    list->array = (int*)malloc(capacity*sizeof(int));
    list->front = list->array;
    list->rear = list->array;
}

bool isEmpty(queue *list){
    return (list->front == list->rear);
}

bool isFull(queue *list){
    return (list->rear == list->array+list->capacity);
}

void enqueue(queue *list , int data){
    if(isFull(list)){
        printf("queue overflow\n");
        return;
    }
   *(list->rear) = data;
    list->rear++;
    list->size++;
}

void dequeue(queue *list){
    if(isEmpty(list)){
        printf("queue underflow\n");
        return;
    }
    list->front++;
    list->size--;
}
void peek(queue *list){

    if(isEmpty(list)){
        printf("list is empty\n");
        return;
    }
    int*temp = list->front;
    do{
        printf("%d\n", *temp);
        temp++;
    }
    while(temp!=list->rear);
}
int main(){
    queue *list = (queue*)malloc(sizeof(queue));
    initQueue(list , 7);
    enqueue(list , 10);
    enqueue(list , 20);
    enqueue(list , 30);
    enqueue(list , 40);
    enqueue(list , 50);
    peek(list);
    dequeue(list);
    dequeue(list);
    dequeue(list);
    dequeue(list);
    dequeue(list);
    peek(list);
    enqueue(list,60);
    peek(list);
}
