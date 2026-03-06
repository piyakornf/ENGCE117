#include <stdio.h>

void TowerHanoi(int m, int i, int j);

int main() {

    TowerHanoi(3, 1, 3);

    return 0;
}

void TowerHanoi(int m, int i, int j) {

    int k;

    if(m == 1) {
        printf("Disc 1 from %d to %d\n", i, j);
        return;
    }

    k = 6 - i - j;

    TowerHanoi(m-1, i, k);

    printf("Disc %d from %d to %d\n", m, i, j);

    TowerHanoi(m-1, k, j);
}