#include <stdio.h>

void foo()
{
    int a = 10;
    static int sa = 10;  // seems can remmber the value for next call

    a += 5;
    sa += 5;
    // show the difference 
    printf("a = %d, sa = %d\n", a, sa);
}


int main()
{
    int i;

    for (i = 0; i < 10; ++i)
        foo();
}




















