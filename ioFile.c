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

    // Then we try to read the file just created
    FILE *fpRead;
    char buff[255] = {0};
    fpRead = fopen("./src/test.txt", "r");
    fscanf(fpRead, "%s", buff);  // seems stop when seen spacebar or \n , not included spacebar or \n
    printf("1 : %s\n", buff);

    fgets(buff, 255, fpRead);  // seems stop when seen \n, inclued \n
    printf("2 : %s\n", buff);

    fgets(buff, 255, fpRead);
    printf("3 : %s\n", buff);

    fclose(fpRead);
    return 0;

    /*Binary files are usually used for storage of prgramme data.
      for example arrays or structures.
      if programme running next time, can reload some data easily.
      
      size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
      size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
    */ 

}

















