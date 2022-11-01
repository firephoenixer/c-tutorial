#include <stdio.h>

int main(){

    int a=2,b=3,c;
    c = a+++b;
    // compiler has a lexical analysis way to analysis sentence.
    // this sentence will be analysised as |c| |=| |a| |++| |+| |b| |;|   
    // equal to : c = (a++) + b;
    // Known about this will help we understand codes.
    // But personally, we must avoid to use sentence like this. So we can keep codes easy to read.
    // Unless you have some special reasons. 

    printf("c:%d, a:%d, b:%d\n", c,a,b);
    
    c = a + ++b;
    
    printf("c:%d, a:%d, b:%d\n", c,a,b);

    return 0;
}