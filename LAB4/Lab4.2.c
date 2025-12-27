#include <stdio.h>

void go(int ***triplePtr, int **doublePtr) {
    *triplePtr = doublePtr;
}

int main() {
    int *numPtr1 = new int; 
    *numPtr1 = 10;

    int *numPtr2 = new int; 
    *numPtr2 = 20;

    int **ptrToPtr;

    go(&ptrToPtr, &numPtr1);
    printf("%d %p %p %p", **ptrToPtr, *ptrToPtr, ptrToPtr, &ptrToPtr);

    go(&ptrToPtr, &numPtr2);
    printf("\n%d %p %p %p", **ptrToPtr, *ptrToPtr, ptrToPtr, &ptrToPtr);

    return 0;
}
