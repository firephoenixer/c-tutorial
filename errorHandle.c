#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
// This file show you how to handle a error in c.

extern int errno;  // use errno in errno.h

int main () {

   FILE *pf;
   int errnum;
   pf = fopen ("unexist.txt", "rb");  // make a file open error
	
   if (pf == NULL) {
      errnum = errno;
      // use stderr file stream to Output all the errors.
      fprintf(stderr, "Value of errno: %d\n", errno);
      // Show the error text.
      perror("Error printed by perror");
      // using strerror() to show errno present what meaning
      fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
   } else {
   
      fclose (pf);
   }

   // manage a error by user
   int dividend = 20;
   int divisor = 5;
   int quotient;
 
   if( divisor == 0) {
      fprintf(stderr, "Division by zero! Exiting...\n");
      exit(EXIT_FAILURE);
   }
	
   quotient = dividend / divisor;
   fprintf(stderr, "Value of quotient : %d\n", quotient );
   exit(EXIT_SUCCESS);
   
   return 0;
}














