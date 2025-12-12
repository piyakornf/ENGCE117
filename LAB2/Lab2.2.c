#include <stdio.h>
#include <string.h> 


void reverse( char str1[], char str2[] );


void reverse(char str1[], char str2[]) {
    
    int len = strlen(str1);

    
    for (int i = 0; i < len; i++) {
        
        str2[i] = str1[len - 1 - i];
    }

   
    str2[len] = '\0';
}



int main() {
    char text_case1[50] = "I Love You"; 
    char out_case1[50];
    
    char text_case2[50] = "Hello World"; 
    char out_case2[50];

    printf("--- Test Case 1 ---\n");
    
    reverse(text_case1, out_case1);
    
    
    printf("Input:  %s\n", text_case1); 
    printf("Output: %s\n", out_case1);  
    
    printf("\n--- Test Case 2 ---\n");

    reverse(text_case2, out_case2);
    
    
    printf("Input:  %s\n", text_case2); 
    printf("Output: %s\n", out_case2);  
    return 0;
}