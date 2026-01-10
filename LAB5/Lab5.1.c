#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    int age;
    char gender; 
    float gpa;
    struct Student *next;
};


typedef struct Student Node;

void displayList(Node *head);
Node *appendNode(Node **head, const char *name, int age, char gender, float gpa);
void insertAfter(Node *prevNode, const char *name, int age, char gender, float gpa);
void deleteNext(Node *prevNode);

int main() {
    Node *head = nullptr; 
    Node *current;       

    current = appendNode(&head, "one", 6, 'M', 3.11);   displayList(head);
    current = appendNode(&head, "two", 8, 'F', 3.22);   displayList(head);
    insertAfter(current, "three", 10, 'M', 3.33);      displayList(head);
    insertAfter(current, "four", 12, 'F', 3.44);       displayList(head);
    deleteNext(current);                               displayList(head);

    return 0;
}


Node *appendNode(Node **head, const char *name, int age, char gender, float gpa) {
    Node *newNode = new Node;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->gender = gender;
    newNode->gpa = gpa;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return newNode;
}


void insertAfter(Node *prevNode, const char *name, int age, char gender, float gpa) {
    if (prevNode == nullptr) return;

    Node *newNode = new Node;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->gender = gender;
    newNode->gpa = gpa;
    
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}


void deleteNext(Node *prevNode) {
    if (prevNode == nullptr || prevNode->next == nullptr) return;
    
    Node *nodeToDelete = prevNode->next;
    prevNode->next = nodeToDelete->next;
    delete nodeToDelete;
}


void displayList(Node *current) {
    while (current != nullptr) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}