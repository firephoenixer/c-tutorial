// show the const in c
#include <stdio.h>
#define PI 3.14159
#define MAXCONTAIN 20
#define add(x, y) x+y
#define compare(x, y) if (x > y) \
                           printf("%d is greater then %d\n", x, y);\
                      else \
                           printf("%d is not greater then %d\n", x, y);

int main()
{

   // MAXCONTAIN = 30;
   // can't do this, beacause it equal to:   20 = 30

   const int SLEEP_HOUR = 22;  // can't be changed anymore either. const makes it read-only.

    printf("%.5f\n", PI);
    printf("%d\n", SLEEP_HOUR);
    printf("%d\n", add(2, 3));    // seems this mode can make things more understandable sometimes.
    compare(5, 6);                // why I feel it also make things more compleximent sometimes.
    compare(7, 6);
    printf("5*6 + 7 = %d\n", 5*add(6,7));  // 37, not 5*13
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);


    return 0;

}






