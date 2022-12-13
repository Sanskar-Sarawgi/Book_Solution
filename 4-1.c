// Exercise 4-1.

#include <stdio.h>
#define Default -1

int Size_of_array(char s[]){
    return sizeof(s)/sizeof(s[0]); // sizeof will get the sizeof that variable so (total/one unit value)
}

int strrindex(char s[],char t){

    int index = Default; //set the defult value of index
    int size = Size_of_array(s);
    for(int i=0;i<size;i++){
        if(s[i] == t){
            index = i;   // index will overwrite again and again till the last value
        }
    }
    
    return index;
}
int main() {
    printf("the Right most occurance of %c is %d",'d',strrindex("mobicip",'i'));
    return 0;
}
