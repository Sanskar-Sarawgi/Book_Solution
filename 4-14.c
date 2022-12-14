// Exercise 4-14.

#include <stdio.h>
#define Swap(t,x,y) t temp = x; x = y; y = temp;

int main() {
    {
        int x = 10;
        int y = 20;
        printf("value of x: %d\n value of y: %d\n",x,y);
        Swap(int,x,y);
        printf("value of x: %d\n value of y: %d\n",x,y);
    }
    
    double x = 24.5;
    double y = 21.5;
    printf("value of x: %f\n value of y: %f\n",x,y);
    Swap(double,x,y);
    printf("value of x: %f\n value of y: %f\n",x,y);
}
