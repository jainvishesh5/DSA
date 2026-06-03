#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct stack{
    int capacity;
    int size;
    int *array;
    int *sp;
}stack ;

void initStack(stack *s , int capacity){
    s->capacity = capacity;
    s->size = 0;
    s->array = (int*)malloc(s->capacity*(sizeof (int)));
    s->sp = s->array;
}

bool isEmpty(stack s){
    return (s.sp == s.array);// or (size == 0)
}

bool isFull(stack s){
    return (s.sp == (s.array + s.capacity));// or (size == capacity)
}

void push (stack* s ,int data){
   if( isFull(*s)){
    return;
   }
    *(s->sp) = data;
    s->sp++;
    s->size++;
}

int pop(stack *s , int *out){
   if(! isEmpty(*s)){
     s->sp--;
    *out  = *(s->sp);
     s->size--;
   
    return 0;}
    else { 
        return (-1);
    }
   
}

void peek(stack s){
    int value;
    s.sp--;
    value = *(s.sp);
    printf("the top of the stack holds :%d\n",value);
}



void Traverse(stack s , bool reverse){
    int value;
    if(!reverse){
    do{
        s.sp--;
        value = *(s.sp);
        printf("%d\n" ,value);
    }while(s.sp != s.array);
}
    else{
        int*ptr = s.array;
        do{
            value = *ptr;
            printf("%d\n", value);
            ptr++;
        }while(ptr!=s.sp);
    }
}

int popIndex(stack *s , int *out ,int index){//index 0 = bottom
    stack temp;
    initStack(&temp , s->capacity);
    int i= s->size;
    while(i != index-1){
        int value;
        pop(s , &value);
        push(&temp, value);
        i--;
    }
    *out = s->array[index];
    int j = index+1;
    while(j != (s->size+1)){
        int value;
        pop(&temp , &value);
        push(s , value);
    }
    free(temp.array);
    return *out;
}
int main(){
    stack s;
    initStack(&s , 10);
    push(&s , 10);
    push(&s , 20);
    push(&s , 30);
    push(&s , 40);
    push(&s , 50);
    int value;
    if (pop(&s, &value)==0)
    {
        printf("popped %d\n" , value);
    }
    else{
        printf("stack empty!\n");
    }
    peek(s);
    printf("traversal\n");
    Traverse(s ,false);
    printf("reverse traversal\n");
    Traverse(s,true);
    popIndex(&s , &value ,2);
printf("hi %d\n", value);
free(s.array);

}




