// Online C compiler to run C program online
#include <stdio.h>
#include <ctype.h> /* for isdigit(c), etc. */

#define MAX 10

int getfloat(double *pn);

int main(void)
{
	double num[MAX];
	int val,i;

	for (i = 0; i < MAX && (val = getfloat(&num[i])) != EOF; i++)
		printf("num[%d] = %lf, \tvalue returned: %d (%d)\n", i, num[i], 
				val, val != 0 ? "number" : "not a number");

	return 0;
}

int getch(void);
void ungetch(int c);

int getfloat(double *pn){
	double point = 1.0;
	int c,sign;
	*pn = 0;
	
	// remove the blank space and alphabate from
	while((c = getch()) == ' ');

	// breaking function so if it is not a digit or sign
	if(!isdigit(c) && c != '+' && c != '-') return 0;
	
	// if there is a sign
	while(c == '+' || c == '-'){
		sign = c == '+' ? 1 : -1;
		c = getch();
	}

	// breaking function so if it is not a digit or sign
	if(!isdigit(c)){
		ungetch((sign == -1)?'-':'+');
		return 0;
	}

	// get the digit
	while(isdigit(c)){
		*pn = (*pn)*10 + (c-'0');
		c = getch();
	}
	
	// point present in the function 
	if(c == '.'){
		c = getch();
		while(isdigit(c)){
			point *= 10.0;
			*pn = (*pn)*10 + (c-'0');
			c = getch();
		}
	}

    // adding the sign to the digit
	*pn *= sign;
	*pn /= point;

	// reuse the last character which is not a digit
	ungetch(c);

	// returnig the last value becase it can be end of program
	return c;
}

int bufp = 0;
int buf[MAX];

int getch(void)
{
	return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < MAX)
		buf[bufp++] = c;
}
