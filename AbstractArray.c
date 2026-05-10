#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct myArray{
    int size;
    int capacity;
    int *baseAddress;
}MyArray;

void CreateArray(MyArray * Array, int size , int capacity){
    (*Array).size = size;// or Array->size = size;
    (*Array).capacity = capacity;
    if(capacity < size){
        printf("Capacity should be greater than size\n");
        return;
    }
    (*Array).baseAddress  =(int*)malloc(capacity*(sizeof(int)));
   
}
void showArray(MyArray *Array){//traversal
    for (int i=0 ; i< Array ->size ;i++){
        printf("%d\n" , (Array ->baseAddress)[i]);
    }
}
void setVal(MyArray * Array){
    int n;
    for (int i=0 ; i< Array -> size ; i++){
        printf("Enter value at index %d :", i);
        scanf("%d", &(Array ->baseAddress)[i]);//or scanf("%d", Array->baseAddress + i);
    }
}
int length(MyArray *Array){
    return Array -> size;
}
void resizeArray(MyArray *Array){
    int newCapacity = Array ->capacity +10;
    int *newBaseAddress = (int*)malloc(newCapacity*(sizeof(int)));
    if(!newBaseAddress){
        printf("Memory allocation failed\n");
        return;
    }
    for(int i=0 ;i<Array->size ;i++){
        newBaseAddress[i] = Array-> baseAddress[i];
    }
    free(Array->baseAddress);
    Array->baseAddress = newBaseAddress;
    Array->capacity = newCapacity;
}
void insertAt(MyArray *Array , int value, int index , bool override ,bool swapback){
    if(index < 0 || index > Array -> size){
        printf("Index out of bounds\n");
        return;
    }
    if (override){
        if(index < Array -> size){
            Array -> baseAddress[index] = value;
        }
        else{
            printf("Index out of bounds\n");
        }
    }
    else if(swapback){
       if(Array -> size >= Array -> capacity){
            printf("Array overflow! resizing...\n");
            resizeArray(Array);
       }
       else if(index > Array -> size){
            printf("Index out of bounds\n");
       }
       else{
        int temp = Array->baseAddress[index];
        Array -> baseAddress[index] =value;
        (Array ->baseAddress)[Array ->size] =temp;
        Array->size++;
       }
    }
    else{
        if(Array-> size >= Array ->capacity){
            printf("array overflow! resizing...\n");
            resizeArray(Array);
        }
        {
            Array->size++;
            for (int i = Array->size ;i>=index ; i--){
                Array->baseAddress[i] = Array->baseAddress[i-1];
            }
            Array->baseAddress[index] = value;
        }
    }
    
}
void deleteAt(MyArray *Array , int index , bool swaplast){
    if(Array->size == 0){
        printf("Array is empty\n");
        return;
    }
    if(index<0 || index >=Array->size){
        printf("index out of bounds\n");
        return;
    }
    
    if(!swaplast){
        for(int i=index ; i<Array->size-1 ; i++){
            Array ->baseAddress[i] = Array ->baseAddress[i+1];
        }
    }
    else{
        Array->baseAddress[index] = Array->baseAddress[Array->size -1];
    }
    Array->size --;

}
void linearSearch(MyArray *Array , int value){
    for (int i=0 ; i<Array->size ; i++){
        if((Array->baseAddress)[i] == value){
            printf("value found! at index %d\n", i);
            return;
        }
    }
    printf("value not found\n");
}
void binarySearch(MyArray *Array , int value,int n){
    //sorting is required for binary search
    int low =0;
    int high = Array->size -1;
    while(low <=high){
        int mid =(low +high)/2;
        if (Array->baseAddress[mid] ==value){
            printf("element found! at index %d\n" , mid);
            return;
        }
        else if(Array ->baseAddress[mid]<value){
            low = mid +1;
        }
        else high = mid -1;
    }
    printf("element not found\n");
}
void bubbleSort(MyArray *Array){}
void insertionSort(MyArray *Array){}
void selectionSort(MyArray *Array){}
void mergeSort(MyArray *Array){}
void quickSort(MyArray *Array){}
void Sort(MyArray *Array){}

