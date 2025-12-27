#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct Student *next;
};

void setStudent(struct Student *node, char *name, int age, char sex, float gpa);
void moveNext(struct Student **cursor);

int main() {
    struct Student *head, *current, **headPtr;

    head = new struct Student;
    setStudent(head, (char*)"one", 6, 'M', 3.11);

    head->next = new struct Student;
    setStudent(head->next, (char*)"two", 8, 'F', 3.22);
    
    head->next->next = new struct Student;
    setStudent(head->next->next, (char*)"three", 10, 'M', 3.33);

    head->next->next->next = new struct Student;
    setStudent(head->next->next->next, (char*)"four", 12, 'F', 3.44);

    current = head;
    headPtr = &head;

    moveNext(headPtr);
    printf("%s\n", (*headPtr)->name);

    return 0;
}

void setStudent(struct Student *node, char name[], int age, char sex, float gpa) {
    strcpy(node->name, name);
    node->age = age;
    node->sex = sex;
    node->gpa = gpa;
}

void moveNext(struct Student **cursor) {
    *cursor = (*cursor)->next;
}
