#include <stdio.h>
// This is a C example for files.

int main(){

    FILE *fTxt;
    /* Mode：r   --  for reading only, must existing
             w   --  for writing, if not existing then create. start writing from the beginning
             a   --  for appending, if not existing then create.
             r+  --  for reading and writing
             w+  --  for reading and writing, if existing delete the content, or create new file
             a+  --  for reading and writing, if existing read at the beginning but only can writing for 
                     appending, or create new file
    for binary files mode: rb, wb, ab, rb+, r+b, wb+, w+b, ab+, a+b
    */

    fTxt = fopen("./src/test.txt", "w+");
    // These two functions actually the same.
    fprintf(fTxt, "This is line01.\n");
    fputs("This is line02.\n", fTxt);

    fclose(fTxt);


    printf("Hello world!");
    return 0;

}

















