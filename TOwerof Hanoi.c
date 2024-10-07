
#include <stdio.h>
void toh(int n,char a,char b, char c){
    if (n==1){
        printf("\n %c -> %c \t",a,b);
       
    }
    else{
        toh(n-1,a,c,b);// A to cmove with help of B
        printf("\n %c -> %c\t" ,a,b);// // print the movement A to B
        toh(n-1,c,b,a);// C to B move with help of A;
 
        
    }
}

int main() {
    // Write C code here
    int n=3;

    toh(n,'a','b','c');

    return 0;
}
