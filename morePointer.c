#include <stdio.h>
// This is a C example for pointer.

int main(){
    int iNum = 10;
    int *pNum = &iNum;
    printf("iNum: %d \n", *pNum);  // usage of a pointer
    printf("pNum: %p \n", pNum);   // print the address in the storage

    int array[5] = {0,1,2,3,4};  // the name of array is a pointer, but can't be modified
    printf("array[0]: %d \n", *array);
    pNum = array;
    printf("iNum: %d \n", *pNum);  // usage of a pointer
    printf("pNum: %p \n", pNum);   // print the address in the storage

    int nLen = sizeof(array)/sizeof(array[0]);  // get the capacity of a array
    printf("The capacity of array: %d \n", nLen);
    for(int i=0; i<nLen; i++)
    {
        printf("The %d of array: %d \n", i, *pNum);
        printf("pNum: %p \n", pNum);
        if(i<nLen-1) pNum++;  // point can't piont a unknown memoery
    }

    // try to point a unknown memory, to see what will happen?
    pNum++;
    printf("Value of a unknown area: %d \n", *pNum);  // It will be a random value, makes no sense.
    printf("pNum: %p \n", pNum);
    pNum--;        // recover pNum to last time
    pNum = &iNum;  // recover pNum to iNum

    int d2Array[3][5] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int (*pA5)[5] = d2Array;  // a pointer point 5 size int array (5*4)
    printf("d2Array[2][2]: %d \n", *(*(pA5+2)+2));  // show 12


    printf("Address of pA5: %p \n", pA5);
    printf("Address pA5 +1: %p \n", pA5+1);  //  diff: 5*4

    int **ppNum = &pNum;  // pointer of a pointer
    printf("iNum by iNum : %d \n", iNum);
    printf("iNum by pNum : %d \n", *pNum);      // usage of a pointer
    printf("iNum by ppNum: %d \n", **ppNum);  
    printf("Address of pNum : %p \n", pNum);
    printf("Address of ppNum: %p \n", ppNum);


    return 0;
}

























