#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[50];
};


struct student (*GetStudent(int *room))[10];

struct student (*GetStudent(int *room))[10] {
    int i, j;

    printf("Enter number of rooms: ");
    scanf("%d", room);

    
    struct student (*data)[10] =
        (struct student (*)[10])malloc(sizeof(struct student) * (*room) * 10);

    for (i = 0; i < *room; i++) {
        printf("Room %d\n", i + 1);
        for (j = 0; j < 10; j++) {
            printf(" Student %d ID: ", j + 1);
            scanf("%d", &data[i][j].id);

            printf(" Student %d Name: ", j + 1);
            scanf("%s", data[i][j].name);
        }
    }

    return data;
}

int main() {
    struct student (*children)[10];
    int group;

    children = GetStudent(&group);

    printf("\n=== Student List ===\n");
    for (int i = 0; i < group; i++) {
        printf("Room %d\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf(" ID: %d Name: %s\n",
                   children[i][j].id,
                   children[i][j].name);
        }
    }

    free(children);
    return 0;
}
