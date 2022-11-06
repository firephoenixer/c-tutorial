#include <stdio.h>
#include <string.h>
 
union Data {
   int i;
   float f;
   char str[20];
};

// one occation union is useful, imagine in supermarket management system
struct item{
    char *name;
    float price;

    // use union to share space
    union{
        struct{
            char *author;
            int nPage;
        }book;

        struct{
            char *style;
            int nSize;
        }shirt;
    }attr;

}aBook, aShirt;


int main( ) {

    union Data data; 
    printf( "Memory size occupied by data : %d\n", sizeof(data));
    // They share the same memory space, be careful!
    data.f = 3.14;
    printf("data.i:%d ,  data.f:%f,  data.str:%s\n", data.i, data.f, data.str);
    data.i = 5;    
    printf("data.i:%d ,  data.f:%f,  data.str:%s\n", data.i, data.f, data.str);   

    // show how to use item to save space
    aBook.name = "When Moon";
    aBook.price = 8999.99;
    aBook.attr.book.author = "Changpeng Zhao";
    aBook.attr.book.nPage = 730;

    aShirt.name = "Summer shirt";
    aShirt.price = 79.9;
    aShirt.attr.shirt.style = "Long very style";
    aShirt.attr.shirt.nSize = 180;

    // I think it does save some space
    printf("Book name: %s, Book page: %d\n", aBook.name, aBook.attr.book.nPage) ;
    printf("Shirt name: %s, Shirt size: %d\n", aShirt.name, aShirt.attr.shirt.nSize) ;


   return 0;
}