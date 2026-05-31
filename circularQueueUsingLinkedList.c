#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int data;
   struct node*next;
}node;

typedef struct queue{
    node*front;
    node*rear;
}queue;

void initQueue(queue *q) {
    q->front = NULL;
    q->rear = NULL;
}


bool isEmpty(queue *q){
    return q->front == NULL;
}
void enqueue(queue*q , int data){
    node*newNode = (node*) malloc (sizeof(node));
    if(newNode ==NULL){
        printf("queue overflow");
        return;
    }
    newNode->data = data;
    newNode->next = NULL; 
    if(q->front == NULL){
        q->front = newNode;
        q->rear = newNode;
    }
    else{q->rear->next = newNode;
    q->rear =newNode;}
}

void dequeue(queue*q){
    if(isEmpty(q)){
        return;
    }
    node*ptr = q->front;
    q->front = q->front->next;
    free(ptr);
    if(q->front ==NULL){
        q->rear =NULL;
    }
}

void traverse(queue*q){
    if(isEmpty(q)){
        printf("queue empty\n");
        return;
    }
    node*temp = q->front;
    while(temp != NULL){
        printf("%d\n" , temp->data);
        temp = temp->next;
    }
}

int main(){
    queue *q = (queue*)malloc(sizeof(queue));
    initQueue(q);
    enqueue(q , 10);
    enqueue(q , 20);
    enqueue(q , 30);
    enqueue(q , 40);
    traverse(q);
    dequeue(q);
    traverse(q);
}