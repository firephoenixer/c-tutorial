#include <stdio.h>
// This is a C example for beginners.

int main(){

    enum point {FALSE,TRUE,c,d=30,e, f=500};
    // seems we can use enum to help local logic more strongly.
    printf("%d, %d, %d, %d, %d, %d", FALSE,TRUE,c,d,e,f);
    return 0;

}