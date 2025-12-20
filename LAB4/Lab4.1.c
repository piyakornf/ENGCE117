#include <stdio.h>

void go(int **p, int *z){
    *p = z;
}

int main(){
    int *a, b = 10, c = 20;

    go(&a, &b);
    printf("%d %p %p\n", *a, a, &b);

    go(&a, &c);
    printf("%d %p %p\n", *a, a, &c);
    return 0;
}