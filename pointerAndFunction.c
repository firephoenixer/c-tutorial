#include <stdio.h>

void showDiff(int iNum, int *pNum);

int main () {

   int  var = 20;   /* actual variable declaration */
   int  *ip;        /* pointer variable declaration */

   ip = &var;  /* store address of var in pointer variable*/

   printf("Address of var variable: %x\n", &var  );

   /* address stored in pointer variable */
   printf("Address stored in ip variable: %x\n", ip );

   /* access the value using the pointer */
   printf("Value of *ip variable: %d\n", *ip );


   // show diff in different mode of parameters
   int anInt = 1;
   int otherInt = 1;
   int *anPointer = &otherInt;
   showDiff(anInt, anPointer);
   // otherInt's address has given to the function.
   printf("Affter function: anInt=%d, otherInt=%d\n", anInt, otherInt);

   return 0;
}

// the difference of these parameters
void showDiff(int iNum, int *pNum)
{
     iNum++;
     (*pNum)++;  // caution: Seems ++ will execute first if no brace!!!
     printf("Inside function: anInt=%d, otherInt=%d\n", iNum, *pNum);
     return;
}



