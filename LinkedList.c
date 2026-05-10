#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AbstractArray.c"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
typedef struct LinkedList
{
    Node *head; // points to the head of the linked list;
    Node *tail; // points to the last node of the list;
    int size;   // size of the linked list;
} LinkedList;

void initList(LinkedList *list)
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

void traversal(LinkedList list, bool reverse)
{
    if (!reverse)
    {
        Node *current = list.head;
        while (current != NULL)
        {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
    else
    {
        MyArray array;
        CreateArray(&array, list.size, list.size);
        int i = list.size - 1;
        Node *current = list.head;
        while (current != NULL)
        {
            insertAt(&array, current->data, i, true, false);
            current = current->next;
            i--;
        }
        showArray(&array);
        free(array.baseAddress);
    }
}

void createNode(LinkedList *list, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    if (list->head == NULL)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}
void insertNode(LinkedList *list, int data, int index, bool insertAtBegin)
{
    if (index == 0 && !insertAtBegin)
    {
        printf("cannot perform operation! turn insertAtBegin true\n");
        return;
    }
    if (index < 0 || index > list->size)
    {
        printf("invalid index\n");
        return;
    }
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    ptr->data = data;
    if (insertAtBegin)
    {
        ptr->next = list->head;
        list->head = ptr;
        if (list->tail == NULL)
        {
            list->tail = ptr;
        }
    }
    else
    {
        Node *p = list->head;
        int i = 0;
        while (i != index - 1 && p != NULL)
        {
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next = ptr;
        if (ptr->next == NULL)
        {
            list->tail = ptr;
        }
    }
    list->size++;
}
void deleteNode(LinkedList *list, bool deleteWithKey)
{
    if (list->head == NULL)
    {
        printf("list empty");
        return;
    }
    if (deleteWithKey)
    {
        int data;
        printf("enter key\n");
        scanf("%d", &data);
        Node *p = list->head;

        if (list->head->data == data)
        {
            list->head = p->next;
            free(p);
            list->size--;
        }
        else
        {
            while (p->next != NULL && p->next->data != data)
            {
                p = p->next;
            }
            if (p->next == NULL)
            {
                printf("key not found\n");
            }
            else
            {
                Node *q = p->next;

                p->next = q->next;
                free(q);
                list->size--;
                printf("node with key %d removed\n", data);
                if (p->next == NULL)
                { // i.e., last node was removed
                    list->tail = p;
                }
            }
        }
    }
    else
    {
        int index;
        printf("enter index\n");
        scanf("%d", &index);
        if (index < 0 || index >= list->size)
        {
            printf("invalid index");
            return;
        }

        if (index == 0)
        {
            Node *p = list->head;

            list->head = list->head->next;
            free(p);
            list->size--;
        }
        else if (index > 0 && index <= list->size - 1)
        {
            Node *p = list->head;
            int i = 0;
            while (i != index - 1)
            {
                p = p->next;
                i++;
            }
            Node *q = p->next;
            p->next = q->next;
            free(q);
            list->size--;
            if (p->next == NULL)
            {
                list->tail = p;
            }
        }
    }
}
int main()
{
    LinkedList list;
    initList(&list);

    createNode(&list, 10);
    createNode(&list, 20);
    createNode(&list, 30);
    insertNode(&list, 40, 0, true);
    insertNode(&list, 50, list.size, false);
    traversal(list, false);

    deleteNode(&list, false);
    traversal(list, false);

    deleteNode(&list, false);
    traversal(list, false);

    deleteNode(&list, false);
    traversal(list, false);

    deleteNode(&list, true);
    traversal(list, false);

    printf("Normal Traversal:\n");
    traversal(list, false);

    printf("Reverse Traversal:\n");
    traversal(list, true);

    // Freeing linked list memory
    Node *temp;
    while (list.head != NULL)
    {
        temp = list.head;
        list.head = list.head->next;
        free(temp);
    }

    return 0;
}
