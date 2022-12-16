#include <stdio.h>
#define Size 1000

char stack[Size];
int top = -1;

int evaluate(int a,int b,char c){
	switch(c){
		case '+': return a+b;
		break;
		case '-': return a-b;
		break;
		case '/': return a/b;
		break;
		case '*': return a*b;
		break;
	}
}

int push(char ch){
	if(top == Size) return -1;  // return -1 if the stack is full;
	stack[++top] = ch;
	return 0;
}

char top_item(){
	if(top == -1) return ' ';
	return stack[top];
}

char pop(){
	if(top != -1) top--;
}

int convert_to_digit(char c){
	return c-'0';
}

int is_digit(char c){
	if(c >= '0' && c <= '9') return 1;
	return 0;
}
int expression_evaluation(char *exp){
	while(*exp != '\0'){
		char ch = *exp;
		if(is_digit(ch)) push(ch);
		else{
			int first = convert_to_digit(pop());
			int second = convert_to_digit(pop());
			int result = evaluate(first,second,ch);
			push(result);
		}
		exp++;
	}
	return top_item();
}


int main(){
	char exp[Size];
	scanf("%s",exp);
	int result = expression_evaluation(exp);
	printf("%s expression result = %d\n",exp,result);
	return 0;
}
