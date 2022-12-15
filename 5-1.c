#include <stdio.h>
#include <ctype.h> /* for isdigit(c), etc. */

#define MAX 10

int getint(int *pn);

int main(void)
{
	int i, num[MAX];
	int val;

	for (i = 0; i < MAX && (val = getint(&num[i])) != EOF; i++)
		printf("num[%d] = %d, \tvalue returned: %d (%s)\n", i, num[i], 
				val, val != 0 ? "number" : "not a number");

	return 0;
}

int getch(void);
void ungetch(int c);

int getint(int *pn)
{
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

    // adding the sign to the digit
	*pn *= sign;

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

