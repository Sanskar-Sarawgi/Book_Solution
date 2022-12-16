#include <stdio.h>

int strncmp(char *s,char *t,int n){
	while(*s++ == *t++ && n--);
	if(n == 0) return 1;
	return 0;
}

void strncat(char *s,char *t,int n){
	for(;*s != '\0'; s++);
	while(n-- && *t != '\0'){
		*s = *t;
		s++;
		t++;
	}
	*s = '\0';
}

void strncpy(char *s,char *t,int n){
	while(n-- && s != '\0'){
		*t = *s;
		t++;
		s++;
	}
	t = '\0';
}

int main(){
	char s[1000];
	char t[1000];
	printf("Enter 1 string : ");
	scanf("%s",s);
	printf("Enter 2 string : ");
	scanf("%s",t);

	strncat(s,t,4);
	printf("%s\n",t);
	return 0; 
}
