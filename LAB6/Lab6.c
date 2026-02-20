#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);


struct studentNode *AddNode(struct studentNode **walk, char *n, int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;
    newNode->back = NULL;

    if (*walk == NULL) {
        *walk = newNode;
    } else {
        struct studentNode *temp = *walk;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->back = temp;
    }
    return newNode;
}


void InsNode(struct studentNode *now, char *n, int a, char s, float g) {
    if (now == NULL) return;
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;

    newNode->next = now;
    newNode->back = now->back;

    if (now->back != NULL) {
        now->back->next = newNode;
    }
    now->back = newNode;
}

void GoBack(struct studentNode **now) {
    if ((*now) != NULL && (*now)->back != NULL) {
        *now = (*now)->back;
    }
}


void DelNode(struct studentNode **now) {
    if (*now == NULL) return;
    struct studentNode *temp = *now;

    if (temp->back != NULL) temp->back->next = temp->next;
    if (temp->next != NULL) temp->next->back = temp->back;

    if (temp->next != NULL) {
        *now = temp->next;
    } else {
        *now = temp->back;
    }

    free(temp);
}

int main() {
    struct studentNode *start, *now;
    start = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11); ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22); ShowAll(start);

    InsNode(now, "three", 10, 'M', 3.33); ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44); ShowAll(start);

    GoBack(&now);

    DelNode(&now); ShowAll(start);
    DelNode(&now); ShowAll(start);
    DelNode(&now); ShowAll(start);

    return 0;
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}