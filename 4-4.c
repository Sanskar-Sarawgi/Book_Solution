// Exercise 4-4.

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define NUMBER '0'

int top = -1;

void push(int item,int stack[]){
    stack[++top] = item;
}

void pop(){
    top--;
}

int top_item(int stack[]){
    return stack[top];
}

void Duplicate(int stack[]){
    if(top != -1){
        push(top_item(stack),stack);
    }
}

void swap(int stack[]){
    if(top > 0){
        int temp_1 = top_item(stack);
        pop();
        int temp_2 = top_item(stack);
        pop();
        push(temp_1,stack);
        push(temp_2,stack);
    }
}

void print_stack(int stack[]){
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main() {
    int stack[MAXSIZE];
    push(10,stack);
    push(20,stack);
    push(30,stack);
    push(40,stack);
    push(50,stack);
    push(60,stack);
    print_stack(stack);
    // to print top element from the stack
    printf("Top element of stack = %d \n",top_item(stack));
    // to Duplicate the top element of the stack
    printf("Duplicate the top element \n");
    Duplicate(stack);
    print_stack(stack);
    // swaping of first two element;
    printf("swap the top element \n");
    push(70,stack);
    print_stack(stack);
    swap(stack);
    print_stack(stack);
    return 0;
}
