#include <stdio.h>
#include <stdlib.h>


int *GetSet(int *set_size_ptr) {
    int *dynamic_array;

    
    scanf("%d", set_size_ptr);

   
    dynamic_array = (int *)malloc(sizeof(int) * (*set_size_ptr));
    
    
    if (dynamic_array == NULL) {
        printf("Memory allocation FAILED.\n");
        exit(0);
    }

    
    for(int i = 0; i < *set_size_ptr; i++) {
        scanf("%d", &dynamic_array[i]);
    }

   
    return dynamic_array;
}

int main() {
    
    int *set_data_ptr; 
    int set_size;      
    
    
    set_data_ptr = GetSet(&set_size);

    
    printf("Elements received: ");
    for (int i = 0; i < set_size; i++) {
        printf("%d ", set_data_ptr[i]);
    }
    printf("\n");


    free(set_data_ptr);
    set_data_ptr = NULL;

    return 0;
}