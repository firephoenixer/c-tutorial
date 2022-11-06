#include <stdio.h>
#include <string.h>
// This is a C example for struct.
// Notice: different machine may use different way to pack the struct to fit processor's circle running.
//         this ways can be switch by "#pragma pack(1)", to save memory space.

struct Books {
   char  *title;
   char  author[50];
   float price;
   int   book_id;
} book1, book2, book3; 

void show_book(struct Books *pBook)
{
    printf("Name: %s, Author: %s, Price: %f, ID: %d\n", pBook->title, pBook->author, pBook->price, pBook->book_id);
}

typedef struct IDmangement{
    char *sName;
    int iAge;
    char cSex;
    char *sOccupation;
    int id_num;
}idstruct;

void show_id(idstruct *pID)
{
    printf("Name: %s, Age: %d, Sex: %c, Occupation: %s, ID: %d\n", 
           pID->sName, pID->iAge, pID->cSex, pID->sOccupation, pID->id_num);
}

int main(){
    // can't use this mode after defined
    // book1 = {.title = "When Moon?", .author = "Changpeng Zhao", .price = 350.55, .book_id = 1001};
    book1.title = "When Moon?";
    strncpy(book1.author, "Changpeng Zhao", strlen("Changpeng Zhao"));
    // book1.author = "Changpeng Zhao";
    book1.price = 350.55; 
    book1.book_id = 1001;
    show_book(&book1);

    // only avaible when difine
    struct Books book4 = {.title = "How Defence", .author = "Zelensikay", .price = 99.9, .book_id = 1002};
    show_book(&book4);
    struct Books book5 = {"How Run", "PX", 33.3, 1003};
    show_book(&book5);

    idstruct idPerson1 = {"Sigma Phai", 36, 'M', "Police", 550501};
    show_id(&idPerson1);
    idstruct idPerson2 = {"Gamma Future", 12, 'F', "Student", 550502};
    idstruct idPerson3 = {"Zeta Kap", 21, 'M', "GamePlayer", 550503};
    idstruct idPerson4 = {"Lamda Kai", 48, 'M', "Artist", 550504};
    idstruct idPerson5 = {"Omega Delt", 76, 'F', "Retired", 550505};

    // a pointer array which point to a idstruct data 
    idstruct *arPID[5] = {&idPerson1, &idPerson2, &idPerson3, &idPerson4, &idPerson5};
    for (int i=0;i<5;i++) show_id(arPID[i]);


    return 0;
}








