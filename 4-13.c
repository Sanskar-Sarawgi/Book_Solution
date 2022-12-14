// Exercise 4-13.
#include <stdio.h>
#define MAXSIZE 1000

int reverse_helper(char str[],int i){
    if(str[i] == '\0'){  // base case to end the recursion
        return 0;
    }
    char ch = str[i]; // storing the char so that the char can be use after returning the recursion
    int count = reverse_helper(str,i+1);
    str[count] =  ch;
    return ++count;
}

void reverse(char str[]){
    reverse_helper(str,0);
}

int main() {
    char str[MAXSIZE];
    scanf("%s",&str);
    reverse(str);
    printf("%s", str);
    return 0;
}
