#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLinkedList
{
    Node *head;
    Node *tail;
    int size;
} DoublyLinkedList;

void initList(DoublyLinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void Traversal(DoublyLinkedList list, bool reverse)
{
    if (list.head == NULL)
    {
        printf("list empty\n");
        return;
    }
    if (!reverse)
    {
        while (list.head != NULL)
        {
            printf("%d \n", list.head->data);
            list.head = list.head->next;
        }
    }
    else
    {
        while (list.tail != NULL)
        {
            printf("%d\n", list.tail->data);
            list.tail = list.tail->prev;
        }
    }
}

void createNode(DoublyLinkedList *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else
    {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
        newNode->next = NULL;
    }
    list->size++;
}
void insertNode(DoublyLinkedList *list, int data, int index, bool insertInBegin)
{
    if (insertInBegin || index == 0)
    {
        if (list->head == NULL)
        {
            createNode(list, data);
        }
        else
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = data;
            newNode->next = list->head;
            newNode->prev = NULL;
            list->head->prev = newNode;
            list->head = newNode;
            list->size++;
        }
    }
    else
    {
        if (index == list->size)
        {
            createNode(list, data);
            return;
        }
        if (index < 0 || index >= list->size)
        {
            printf("invalid index\n");
            return;
        }

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        int i = 0;
        Node *p = list->head;
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        newNode->next = p->next;
        p->next = newNode;
        newNode->prev = p;
        newNode->next->prev = newNode;
        list->size++;
    }
}

void deleteNode(DoublyLinkedList *list, int index)
{
    if (list->head == NULL)
    {
        printf("List empty!\n");
        return;
    }

    if (index < 0 || index >= list->size)
    {
        printf("Invalid index\n");
        return;
    }

    if (list->size == 1)
    {
        // Only one node in the list
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return;
    }

    if (index == 0)
    {
        // Delete head
        Node *temp = list->head;
        list->head = temp->next;
        list->head->prev = NULL;
        free(temp);
        list->size--;
        return;
    }

    if (index == list->size - 1)
    {
        // Delete tail
        Node *temp = list->tail;
        list->tail = temp->prev;
        list->tail->next = NULL;
        free(temp);
        list->size--;
        return;
    }

    // Delete from middle
    Node *p = list->head;
    int i = 0;
    while (i < index)
    {
        p = p->next;
        i++;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    list->size--;
}

int main()
{
    DoublyLinkedList list;
    initList(&list);
    createNode(&list, 10);
    // createNode(&list ,20);
    // createNode(&list ,30);
    printf("traversing the list\n");
    Traversal(list, false);
    printf("traversing the list in reverse\n");
    Traversal(list, true);
    // insertNode(&list  ,5 , 3, false);
    // insertNode(&list , 18 ,1 ,false);
    // insertNode(&list, 12 , 0 ,true);
    printf("traversing the list after inserting\n");
    Traversal(list, false);
    printf("reverse traversing after inserting \n");
    Traversal(list, true);
    deleteNode(&list, 0);
    printf("traversal after deleting node\n");
    Traversal(list, false);
}
