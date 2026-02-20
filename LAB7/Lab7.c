#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};


typedef struct LinkedList {
    struct studentNode *start;
    struct studentNode **now;
    

    void (*InsNode)(struct LinkedList*, const char*, int, char, float);
    void (*DelNode)(struct LinkedList*);
    void (*GoNext)(struct LinkedList*);
    void (*ShowNode)(struct LinkedList*);
} LinkedList;


void InsNode_Impl(LinkedList *self, const char n[], int a, char s, float g) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    
    newNode->next = *(self->now);
    *(self->now) = newNode;
}

void DelNode_Impl(LinkedList *self) {
    if (*(self->now) == NULL) return;
    struct studentNode *temp = *(self->now);
    *(self->now) = temp->next;
    free(temp);
}

void GoNext_Impl(LinkedList *self) {
    if (*(self->now) != NULL) {
        self->now = &((*(self->now))->next);
    }
}

void ShowNode_Impl(LinkedList *self) {
    struct studentNode *walk = self->start;
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}


void initLinkedList(LinkedList *list) {
    list->start = NULL;
    list->now = &(list->start);
    list->InsNode = InsNode_Impl;
    list->DelNode = DelNode_Impl;
    list->GoNext = GoNext_Impl;
    list->ShowNode = ShowNode_Impl;
}



typedef struct NewList {
    LinkedList base; 
    void (*GoFirst)(struct NewList*);
} NewList;

void GoFirst_Impl(NewList *self) {
    self->base.now = &(self->base.start);
}

void initNewList(NewList *newList) {
    initLinkedList(&(newList->base)); 
    newList->GoFirst = GoFirst_Impl;
    
}



int main() {
    LinkedList listA;
    initLinkedList(&listA);
    
    NewList listB;
    initNewList(&listB);
    
    LinkedList *listC;

    
    listA.InsNode(&listA, "one", 1, 'A', 1.1);
    listA.InsNode(&listA, "two", 2, 'B', 2.2);
    listA.InsNode(&listA, "three", 3, 'C', 3.3);
    listA.GoNext(&listA);
    listA.ShowNode(&listA);

    
    listB.base.InsNode(&(listB.base), "four", 4, 'D', 4.4);
    listB.base.InsNode(&(listB.base), "five", 5, 'E', 5.5);
    listB.base.InsNode(&(listB.base), "six", 6, 'F', 6.6);
    listB.base.GoNext(&(listB.base));
    listB.base.DelNode(&(listB.base));
    listB.base.ShowNode(&(listB.base));

    
    listC = &listA;
    listC->ShowNode(listC);

    listC = &(listB.base);
    listC->ShowNode(listC);

    return 0;
}