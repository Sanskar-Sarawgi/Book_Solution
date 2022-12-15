#include <stdio.h>

void strc(char *s,char *t){
	printf("dsf");
	for(;*s != '\0'; s++);
	while(*t != '\0'){
		*s = *t;
	}
	*s = '\0';
}

int main(){
	char s[1000];
	char t[1000];
	printf("Enter 1 string : ");
	scanf("%s",s);
	printf("Enter 2 string : ");
	scanf("%s",t);

	strc(s,t);
	printf("%s",s);
	return 0;
}
