#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct myArray{
    int size;
    int capacity;
    int *baseAddress;
}MyArray;

void CreateArray(MyArray * arr, int size , int capacity){
    
    if(capacity < size){
        printf("Capacity should be greater than size\n");
        arr->baseAddress = NULL;
        arr->size = 0;
        arr->capacity = 0;
        return;
    }
    
    (*arr).size = size;// or Array->size = size;
    (*arr).capacity = capacity;
    (*arr).baseAddress  =(int*)malloc(capacity * sizeof(int));
    if(arr->baseAddress == NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
}
void showArray(MyArray *arr , bool reverse){//traversal

    if(reverse){
        printf("[ ");
          for(int i = arr->size - 1; i >= 0; i--){

            printf("%d", arr->baseAddress[i]);

            if(i != 0){
                printf(" ");
            }
        }
        printf(" ]\n");
        return;
    }
    printf("[ ");
    for (int i=0 ; i< arr->size ;i++){
        printf("%d " , (arr->baseAddress)[i]);
    }
    printf("]\n");
}
void setVal(MyArray *arr){
    for (int i=0 ; i< arr->size ; i++){
        printf("Enter value at index %d :", i);
        scanf("%d", &(arr->baseAddress)[i]);//or scanf("%d", Array->baseAddress + i);
    }
}
int length(MyArray *arr){
    return arr-> size;
}
bool resizeArray(MyArray *arr){
    int newCapacity = 0;
    if(arr->capacity == 0) newCapacity=1;
    else{newCapacity = arr->capacity *2;}
    int *newBaseAddress = (int*)malloc(newCapacity * (sizeof(int)));
    if(!newBaseAddress){
        printf("Memory allocation failed\n");
        return false;
    }
    for(int i=0 ;i<arr->size ;i++){
        newBaseAddress[i] = arr-> baseAddress[i];
    }
    free(arr->baseAddress);
    arr->baseAddress = newBaseAddress;
    arr->capacity = newCapacity;

    return true;
}

void overrideAt(MyArray *arr , int value , int index){
     if(index < 0 || index >= arr->size){
        printf("Index out of bounds\n");
        return;
    }
        arr->baseAddress[index] = value;
    }

void swapback(MyArray *arr , int value , int index){
    if(index < 0 || index > arr->size){
        printf("Index out of bounds\n");
        return;
    }
       if(arr->size == arr->capacity){
            printf("Array overflow! resizing...\n");
            if(!resizeArray(arr)){
                return;
             }
       }
    if(index == arr->size){
        arr->baseAddress[arr->size] = value;
        arr->size++;
        return;
    }
    int temp = arr->baseAddress[index];
        arr-> baseAddress[index] =value;
        (arr->baseAddress)[arr->size] =temp;
        arr->size++;
    }

void insertAt(MyArray *arr , int value, int index){
    if(index < 0 || index > arr->size){
        printf("Index out of bounds\n");
        return;
    }
   
        if(arr-> size >= arr->capacity){
            printf("array overflow! resizing...\n");
            if(!resizeArray(arr)){
            return;
}
        }
            arr->size++;
            for (int i = arr->size-1 ;i>index ; i--){
                arr->baseAddress[i] = arr->baseAddress[i-1];
            }
            arr->baseAddress[index] = value;
        }

void append(MyArray *arr, int value){
    insertAt(arr, value, arr->size);
}

void deleteAt(MyArray *arr , int index , bool swaplast){
    if(arr->size == 0){
        printf("Array is empty\n");
        return;
    }
    if(index<0 || index >=arr->size){
        printf("index out of bounds\n");
        return;
    }
    
    if(!swaplast){
        for(int i=index ; i<arr->size-1 ; i++){
         arr->baseAddress[i] = arr->baseAddress[i+1];
        }
    }
    else{
      arr->baseAddress[index] = arr->baseAddress[arr->size -1];
    }
    arr->size --;
}

void destroyArray(MyArray *arr){

    free(arr->baseAddress);

    arr->baseAddress = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int linearSearch(MyArray *arr , int value){
    for (int i=0 ; i<arr->size ; i++){
        if((arr->baseAddress)[i] == value){
            return i;
        }
    }
    return -1;
}
int binarySearch(MyArray *arr, int value){
    //sorting is required for binary search
    int low =0;
    int high = arr->size -1;
    while(low <=high){
        int mid = (low + high) /2;
        if (arr->baseAddress[mid] ==value){
            return mid;
        }
        else if(arr->baseAddress[mid]<value){
            low = mid +1;
        }
        else high = mid -1;
    }
   return -1;
}
void quickSort(MyArray *Array){}


