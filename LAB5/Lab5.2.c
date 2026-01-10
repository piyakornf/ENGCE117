#include <stdio.h>
#include <string.h>

struct StudentNode {
    char name[20];
    int age;
    char gender;
    float gpa;
    struct StudentNode *next;
};


typedef struct StudentNode Node;

void displayList(Node **headAddr);
void insertAt(Node **targetAddr, const char *name, int age, char gender, float gpa);
void moveNext(Node ***currentPtrAddr);
void deleteAt(Node **targetAddr);

int main() {
    Node *head = NULL;      
    Node **currentPtr;      
    
    currentPtr = &head;     

    insertAt(&head, "one", 6, 'M', 3.11);    displayList(&head);
    insertAt(&head, "two", 8, 'F', 3.22);    displayList(&head);
    
    moveNext(&currentPtr);  
    
    insertAt(currentPtr, "three", 10, 'M', 3.33); displayList(&head);
    insertAt(currentPtr, "four", 12, 'F', 3.44);  displayList(&head);
    
    moveNext(&currentPtr);
    deleteAt(currentPtr);   displayList(&head);

    return 0;
}


void insertAt(Node **targetAddr, const char *name, int age, char gender, float gpa) {
    Node *newNode = new Node;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->gender = gender;
    newNode->gpa = gpa;

    newNode->next = *targetAddr;
    *targetAddr = newNode;
}


void moveNext(Node ***currentPtrAddr) {
    if (**currentPtrAddr != nullptr) {
        *currentPtrAddr = &((**currentPtrAddr)->next);
    }
}


void deleteAt(Node **targetAddr) {
    if (*targetAddr == nullptr) return;

    Node *temp = *targetAddr;
    *targetAddr = temp->next; 
    delete temp;
}


void displayList(Node **headAddr) {
    Node **walker = headAddr;
    while ((*walker) != nullptr) {
        printf("%s ", (*walker)->name);
        walker = &(*walker)->next;
    }
    printf("\n");
}