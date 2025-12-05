#include <stdio.h>
#include <stdlib.h>


int *GetMatrix(int *matrix_rows_ptr, int *matrix_cols_ptr) {
    int *allocated_memory_ptr; 

    
    printf("Enter number of rows and columns (e.g., 3 4): ");
    scanf("%d %d", matrix_rows_ptr, matrix_cols_ptr);

    
    allocated_memory_ptr = (int *)malloc((*matrix_rows_ptr) * (*matrix_cols_ptr) * sizeof(int));
    
    if (allocated_memory_ptr == NULL) {
        printf("Memory allocation FAILED.\n");
        exit(0);
    }

  
    printf("Enter %d elements:\n", (*matrix_rows_ptr) * (*matrix_cols_ptr));
    for (int r = 0; r < *matrix_rows_ptr; r++) { 
        for (int c = 0; c < *matrix_cols_ptr; c++) { 
           
            scanf("%d", &allocated_memory_ptr[r * (*matrix_cols_ptr) + c]);
        }
    }

    
    return allocated_memory_ptr;
}

int main() {
    
    int *matrix_elements_ptr; 
    int rows;                 
    int cols;                 

    
    matrix_elements_ptr = GetMatrix(&rows, &cols);

   
    printf("\nMatrix (%d x %d) Elements:\n", rows, cols);
    for (int r = 0; r < rows; r++) { // Renamed rowIndex to r
        for (int c = 0; c < cols; c++) { 
            
            printf("%d ", matrix_elements_ptr[r * cols + c]);
        }
        printf("\n");
    }

    
    free(matrix_elements_ptr);
    matrix_elements_ptr = NULL;

    return 0;
}