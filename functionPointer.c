#include <stdio.h>
// This is a C example for function pointer.
float sum(float a, float b) {return a+b;}
float min(float a, float b) {return a-b;}
float mul(float a, float b) {return a*b;}
float dev(float a, float b) {return a/b;}

int main(){
    // ordinary call
    printf("%f\n", sum(4,2));
    printf("%f\n", min(4,2));
    printf("%f\n", mul(4,2));
    printf("%f\n", dev(4,2));
    printf("\n");

    // a function pointer
    float (*pSum) (float, float) = sum;  // notice: we use (*pSum) make sure pSum a pionter, otherwise pSum will 
                                         // associate with (float, float) witch makes no sense!!!                                        
    printf("%f\n", pSum(4,2));
    printf("\n");

    float (*pMin) (float, float) = &min;  // use & + name, is the same to above
    printf("%f\n", pMin(4,2));
    printf("\n");

    float (*pMul) (float, float);  
    pMul = &mul;
    printf("%f\n", pMul(4,2));
    printf("\n");

    // When function pointers useful
    float (*pFuns[4]) (float, float) = {sum, min, mul, dev};  // (*pFuns[4]) means array content pointers
    for(int i = 0; i < 4; i++)  printf("%f\n", pFuns[i](4, 2));

    // function pointers may make programme more flexible


    return 0;

}