#include <stdio.h>
#include <string.h>

struct StudentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct StudentNode *next;
};

void setStudent(struct StudentNode *node, char *name, int age, char sex, float gpa);
void goNext(struct StudentNode **cursor);

int main() {
    struct StudentNode *head, *current, **headPtr;

    head = new struct StudentNode;
    setStudent(head, "one", 6, 'M', 3.11);

    head->next = new struct StudentNode;
    setStudent(head->next, "two", 8, 'F', 3.22);
    
    head->next->next = new struct StudentNode;
    setStudent(head->next->next, "three", 10, 'M', 3.33);

    head->next->next->next = new struct StudentNode;
    setStudent(head->next->next->next, "four", 12, 'F', 3.44);

    current = head;
    headPtr = &head;

    goNext(&current);
    printf("%s\n", current->name);

    return 0;
}

void setStudent(struct StudentNode *node, char *name, int age, char sex, float gpa) {
    strcpy(node->name, name);
    node->age = age;
    node->sex = sex;
    node->gpa = gpa;
}

void goNext(struct StudentNode **cursor) {
    *cursor = (*cursor)->next;
}
