#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


void reverse(char str1[], char str2[]) {
    
    int len = strlen(str1);

   
    for (int i = 0; i < len; i++) {
        
        str2[i] = str1[len - 1 - i];
    }

    
    str2[len] = '\0';
}



void explode(char str1[], char splitter, char str2[][10], int *count) {
    int str1_len = strlen(str1);
    int row_idx = 0; 
    int col_idx = 0; 

    
    for (int i = 0; i < str1_len; i++) {
        
       
        if (str1[i] == splitter) {
            
           
            str2[row_idx][col_idx] = '\0'; 
            
            
            row_idx++;
            col_idx = 0;
            
        } else {
            
            if (col_idx < 9) { 
                str2[row_idx][col_idx] = str1[i];
                col_idx++;
            }
        }
    }
    
    
    str2[row_idx][col_idx] = '\0';

    
    *count = row_idx + 1; 
}



int main() {
    
   
    printf("======================================\n");
    printf("         TESTING reverse()\n");
    printf("======================================\n");
    
    char text_in[50] = "Hello World"; 
    char text_out[50];
    
    reverse(text_in, text_out);
    
    printf("Input:  %s\n", text_in);
    printf("Output: %s\n", text_out); 
    
    
    
    printf("\n======================================\n");
    printf("         TESTING explode()\n");
    printf("======================================\n");
    
    char str1_input[] = "I/Love/You"; 
    char splitter_char = '/';
    char out_result[20][10];
    int num_count = 0;      
    
    explode(str1_input, splitter_char, out_result, &num_count);
    
    printf("Input: %s\n", str1_input);
    printf("Splitter: %c\n", splitter_char);
    printf("--- Explode Output ---\n");
    
    for(int i = 0; i < num_count; i++) {
        printf("str2[%d] = \"%s\"\n", i, out_result[i]); 
    }
    
    printf("\nFinal count = %d (Expected: 3)\n", num_count); 
    
    return 0;
}