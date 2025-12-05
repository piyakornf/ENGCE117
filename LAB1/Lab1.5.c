#include <stdio.h>
#include <stdlib.h>


void GetMatrix(int **matrix_data_ptr, int *rows_ptr, int *cols_ptr) {
    
    
    printf("Enter number of rows and columns (e.g., 3 4): ");
    scanf("%d %d", rows_ptr, cols_ptr);

    
    *matrix_data_ptr = (int *)malloc((*rows_ptr) * (*cols_ptr) * sizeof(int));
    
    if (*matrix_data_ptr == NULL) {
        printf("Memory allocation FAILED.\n");
        exit(0);
    }

    
    printf("Enter %d elements:\n", (*rows_ptr) * (*cols_ptr));
    for (int i = 0; i < *rows_ptr; i++) {
        for (int j = 0; j < *cols_ptr; j++) {
            
            int index = i * (*cols_ptr) + j;
            scanf("%d", &(*matrix_data_ptr)[index]);
        }
    }
}

int main() {
    
    int *matrix_elements_ptr = NULL; 
    int num_rows = 0;                
    int num_cols = 0;                
    
    
    GetMatrix(&matrix_elements_ptr, &num_rows, &num_cols);

    
    printf("\nMatrix (%d x %d):\n", num_rows, num_cols);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            
            printf("%d ", matrix_elements_ptr[i * num_cols + j]);
        }
        printf("\n");
    }

    
    free(matrix_elements_ptr);
    matrix_elements_ptr = NULL;

    return 0;
}