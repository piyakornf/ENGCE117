#include <stdio.h>
#include <string.h>

void reverse(char str1[], char str2[]){

    int len = strlen(str1);

    for(int i = 0; i < len; i++){
        str2[i] = str1[len - 1 - i];
    }

    str2[len] = '\0';
}

int main() {
    char text[50] = "Hello Wold";
    char out[50];

    reverse(text, out);

    printf("Input: %s\n", text);
    printf("Output: %s\n", out);

    return 0;
}