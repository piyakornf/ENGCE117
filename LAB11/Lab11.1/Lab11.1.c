#include <stdio.h>

int BinSearch(int *data, int m, int find) {
    int left = 0;
    int right = m - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (data[mid] == find) {
            return mid;      
        }
        else if (data[mid] < find) {
            left = mid + 1; 
        }
        else {
            right = mid - 1; 
        }
    }

    return -1;  
}

int main() {
    int m = 6;
    int data[] = {1, 2, 3, 4, 5, 7};  
    int find = 5;

    int pos = BinSearch(data, m, find);

    if (pos != -1)
        printf("Found %d at index %d\n", find, pos);
    else
        printf("Not Found\n");

    return 0;
}