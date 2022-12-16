#include <stdio.h>

int strc(char *s,char *t){
	// move to the end of the string
	for(;*s != '\0'; s++);
	char *start = t;
	for(;*t != '\0'; t++);
	//scan from the end of the string s
	while(t != start){
		if(*t != *s) return 0;
		t--;
		s--;
	}
	if(*t != *s) return 0;
	return 1;
}

int main(){
	char s[1000];
	char t[1000];
	printf("Enter 1 string : ");
	scanf("%s",s);
	printf("Enter 2 string : ");
	scanf("%s",t);

	int ans = strc(s,t);
	printf("%s present in the end \n",(ans == 1 ? "Yes" : "Not"));
	return 0; 
}
