#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularLinkedList {
    Node* head;
    Node* tail;
    int size;
} CircularLinkedList;

// Initialize list
void initList(CircularLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Traverse and print the list
void traverse(CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = list->head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(back to head)\n");
}

// Insert node
void insert(CircularLinkedList* list, int data, int mode, int param) {
    Node* newNode = createNode(data);

    // If list is empty
    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = list->tail = newNode;
        list->size = 1;
        return;
    }

    switch (mode) {
        case 0: // Insert at beginning
            newNode->next = list->head;
            list->tail->next = newNode;
            list->head = newNode;
            break;

        case 1: // Insert at end
            newNode->next = list->head;
            list->tail->next = newNode;
            list->tail = newNode;
            break;

        case 2: { // Insert at index
            if (param < 0 || param > list->size) {
                printf("Invalid index\n");
                free(newNode);
                return;
            }
            if (param == 0) {
                insert(list, data, 0, 0);
                return;
            }
            Node* temp = list->head;
            for (int i = 0; i < param - 1; i++)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == list->tail)
                list->tail = newNode;
            break;
        }

        case 3: { // Insert after key
            Node* temp = list->head;
            int found = 0;
            do {
                if (temp->data == param) {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    if (temp == list->tail)
                        list->tail = newNode;
                    found = 1;
                    break;
                }
                temp = temp->next;
            } while (temp != list->head);
            if (!found) {
                printf("Key not found\n");
                free(newNode);
                return;
            }
            break;
        }
        default:
            printf("Invalid insert mode\n");
            free(newNode);
            return;
    }
    list->size++;
}

// Delete node
void deleteNode(CircularLinkedList* list, int mode, int param) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = list->head;
    Node* prev = list->tail;

    switch (mode) {
        case 0: // Delete from beginning
            if (list->head == list->tail) {
                free(list->head);
                list->head = list->tail = NULL;
            } else {
                list->head = list->head->next;
                prev->next = list->head;
                free(temp);
            }
            break;

        case 1: // Delete from end
            if (list->head == list->tail) {
                free(list->head);
                list->head = list->tail = NULL;
            } else {
                while (prev->next != list->tail)
                    prev = prev->next;
                temp = list->tail;
                prev->next = list->head;
                list->tail = prev;
                free(temp);
            }
            break;

        case 2: { // Delete at index
            if (param < 0 || param >= list->size) {
                printf("Invalid index\n");
                return;
            }
            if (param == 0) {
                deleteNode(list, 0, 0);
                return;
            }
            for (int i = 0; i < param - 1; i++)
                temp = temp->next;
            Node* delNode = temp->next;
            temp->next = delNode->next;
            if (delNode == list->tail)
                list->tail = temp;
            free(delNode);
            break;
        }

        case 3: { // Delete by key
            if (list->head->data == param) {
                deleteNode(list, 0, 0);
                return;
            }
            do {
                if (temp->next->data == param) {
                    Node* delNode = temp->next;
                    temp->next = delNode->next;
                    if (delNode == list->tail)
                        list->tail = temp;
                    free(delNode);
                    list->size--;
                    return;
                }
                temp = temp->next;
            } while (temp != list->head);
            printf("Key not found\n");
            return;
        }

        default:
            printf("Invalid delete mode\n");
            return;
    }
    list->size--;
}

// Test the functions
int main() {
    CircularLinkedList list;
    initList(&list);

    insert(&list, 10, 1, 0); // end
    insert(&list, 20, 1, 0);
    insert(&list, 30, 0, 0); // begin
    insert(&list, 40, 2, 1); // index 1
    insert(&list, 50, 3, 20); // after key 20
    traverse(&list);

    deleteNode(&list, 0, 0); // delete begin
    deleteNode(&list, 1, 0); // delete end
    deleteNode(&list, 2, 1); // delete index 1
    deleteNode(&list, 3, 20); // delete by key
    traverse(&list);

    return 0;
}
