// Exercise 4-12.

#include <stdio.h>
#define MAXSIZE 1000

int itoa_helper(char str[],int i){
    static int base = 1;
    if(str[i] == '\0'){  // base case to end the recursion
        return 0;
    }
    // converting char to int
    int digit = str[i]-'0';
    
    // concatinating digit to the end of the number
    int temp = itoa_helper(str,i+1) + digit*base;
    base *= 10;
    return temp;
}

int itoa(char str[]){
    return itoa_helper(str,0);
}
int main() {
    char str[MAXSIZE];
    scanf("%s",&str);
    printf("%d", itoa(str));
    return 0;
}
