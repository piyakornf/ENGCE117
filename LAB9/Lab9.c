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

struct studentNode *head = NULL;

void Add() {
    struct studentNode *newNode = malloc(sizeof(struct studentNode));

    printf("Name: ");
    scanf("%s", newNode->name);
    printf("Age: ");
    scanf("%d", &newNode->age);
    printf("Sex: ");
    scanf(" %c", &newNode->sex);
    printf("GPA: ");
    scanf("%f", &newNode->gpa);

    newNode->next = head;
    head = newNode;
}

void Show() {
    struct studentNode *temp = head;

    while (temp != NULL) {
        printf("%s %d %c %.2f\n",
        temp->name,
        temp->age,
        temp->sex,
        temp->gpa);

        temp = temp->next;
    }
}

void Find() {
    char name[20];
    printf("Find name: ");
    scanf("%s", name);

    struct studentNode *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found: %s %d %c %.2f\n",
            temp->name,
            temp->age,
            temp->sex,
            temp->gpa);
            return;
        }
        temp = temp->next;
    }

    printf("Not found\n");
}

void Delete() {
    char name[20];
    printf("Delete name: ");
    scanf("%s", name);

    struct studentNode *temp = head;
    struct studentNode *prev = NULL;

    while (temp != NULL) {

        if (strcmp(temp->name, name) == 0) {

            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Deleted\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Not found\n");
}

int main() {

    int menu;

    do {
        printf("\nMenu\n");
        printf("1 Add\n");
        printf("2 Delete\n");
        printf("3 Find\n");
        printf("4 Show\n");
        printf("0 Exit\n");

        scanf("%d",&menu);

        switch(menu) {
            case 1: Add(); break;
            case 2: Delete(); break;
            case 3: Find(); break;
            case 4: Show(); break;
        }

    } while(menu != 0);

}
