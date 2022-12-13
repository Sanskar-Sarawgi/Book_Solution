// Exercise 4-2.

#include <stdio.h>

int Size_of_array(char str[]){
    return sizeof(str)/sizeof(str[0]); 
}

double atof(char str[]){

    double value = 0; //set the defult value of index
    int point_position = 10;
    int size = Size_of_array(str);
    for(int i=0;i<=size;i++){
        if(str[i] == '.'){
            point_position = point_position*10;
        }
        else {
            value *= 10;
            value += str[i]-'0';   // adding value at the last of the value;
        }
    }
    
    value /= point_position; // pacing pointer to the correct position.
    
    return value;
}
int main() {
    printf("%f",atof("102345.46"));
    return 0;
}
