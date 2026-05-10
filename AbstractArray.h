#ifndef ABSTRACT_ARRAY_H
#define ABSTRACT_ARRAY_H

#include <stdbool.h>

typedef struct myArray{
    int size;
    int capacity;
    int *baseAddress;
} MyArray;

/* Creation / Destruction */
void CreateArray(MyArray *arr, int size, int capacity);
void destroyArray(MyArray *arr);

/* Utility */
void showArray(MyArray *arr, bool reverse);
void setVal(MyArray *arr);
int length(MyArray *arr);

/* Memory Management */
bool resizeArray(MyArray *arr);

/* Insert / Update */
void overrideAt(MyArray *arr, int value, int index);
void swapback(MyArray *arr, int value, int index);
void insertAt(MyArray *arr, int value, int index);
void append(MyArray *arr, int value);

/* Delete */
void deleteAt(MyArray *arr, int index, bool swaplast);

/* Searching */
int linearSearch(MyArray *arr, int value);
int binarySearch(MyArray *arr, int value);

/* Sorting */
void quickSort(MyArray *arr);

#endif
