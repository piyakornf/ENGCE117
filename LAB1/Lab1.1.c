#include <stdio.h>

int main() {
    int N, i;

    printf("Enter a non-negative integer N: ");
    
    
    if (scanf("%d", &N) != 1) {
        printf("Error: Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (N == 0) {
        printf("N is 0. The loop will not execute.\n");
    } else {
        printf("Starting loop for N = %d:\n", N);
        for (i = 0; i < N; i++) {
            printf("%d. Hello Loop!\n", i + 1);
        }
    }

    return 0; 
}