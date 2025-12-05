#include <stdio.h>


int GetSet(int **set_ptr_to_array) {
   
    static int static_storage_array[100]; 
    int index;       
    int set_size;    

    printf("Enter number of elements: ");
    
    if (scanf("%d", &set_size) != 1) set_size = 0;

    
    if (set_size < 0) set_size = 0;
    if (set_size > 100) set_size = 100;

    
    for (index = 0; index < set_size; index++) {
        printf("Element %d: ", index + 1);
        
        if (scanf("%d", &static_storage_array[index]) != 1) static_storage_array[index] = 0;
    }

    
    *set_ptr_to_array = static_storage_array;
    
    
    return set_size;
}

int main() {
    int *received_data_ptr;
    int array_length;       
    int index;              
    
    
    array_length = GetSet(&received_data_ptr);

    printf("\nSet elements: ");
    for (index = 0; index < array_length; index++) {
        printf("%d ", received_data_ptr[index]);
    }
    printf("\n");

    return 0;
}