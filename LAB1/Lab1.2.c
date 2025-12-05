#include <stdio.h>
#include <stdlib.h>


void GetSet(int **array_ptr, int *size_ptr) {
    
    
    scanf("%d", size_ptr);

    
    *array_ptr = (int *)malloc(sizeof(int) * (*size_ptr));
    
   
    if (*array_ptr == NULL) {
        printf("Memory allocation FAILED.");
        exit(0);
    }

    
    for (int i = 0; i < *size_ptr; i++) {
        
        scanf("%d", &(*array_ptr)[i]);
    }
}

int main() {
    
    int *set_data = NULL;
    int set_size = 0; 

    
    GetSet(&set_data, &set_size);

    // Print the elements of the array
    printf("Elements received: ");
    for (int i = 0; i < set_size; i++) {
        printf("%d ", set_data[i]);
    }
    printf("\n");

    
    free(set_data);
    set_data = NULL; 

    return 0;
}