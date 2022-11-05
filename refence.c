#include <stdio.h>
// This is a C example for refence.

int main(){
    int iNum = 9;
    int& rNum = iNum;  // seems c hasn't refence syntax, can't pass the gcc compile. But can pass g++ compile
    printf("iNum: %d\n" , iNum);
    printf("rNum: %d\n" , rNum);

    return 0;
}


















