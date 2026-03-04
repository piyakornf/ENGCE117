#include <stdio.h>

void mergesort(int t[], int temp[], int left, int right);
void merge(int t[], int temp[], int left, int mid, int right);

void mergesort(int t[], int temp[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergesort(t, temp, left, mid);
    mergesort(t, temp, mid + 1, right);

    merge(t, temp, left, mid, right);
}

void merge(int t[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (t[i] <= t[j])
            temp[k++] = t[i++];
        else
            temp[k++] = t[j++];
    }

    while (i <= mid)
        temp[k++] = t[i++];

    while (j <= right)
        temp[k++] = t[j++];

    for (int x = left; x <= right; x++)
        t[x] = temp[x];
}

int main() {
    int data[] = {4, 6, 1, 2, 5, 1, 8};
    int k = sizeof(data) / sizeof(data[0]);
    int temp[k];

    mergesort(data, temp, 0, k - 1);

    printf("Sorted: ");
    for (int i = 0; i < k; i++)
        printf("%d ", data[i]);

    return 0;
}