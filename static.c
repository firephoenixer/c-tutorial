#include <stdio.h>
// use "size a.exe" can see the execuble file's size in different segment of the RAM.
static int iTest, iTest2;
static int iTest3 = 1;


static int iTest5;       // seems in bss segment
static int iTest5 = 31;  // seems move to data segment when get a !0 value
static int iTest5;       // wo should aviod to do this, we test this to understand programme well.
                         // seems still in data segment with the value 31
// iTest5 = 50;  // Not allowed in globle scope!

void foo()
{
    int a = 10;
    static int sa = 10;  // seems can remmber the value for next call
                         // seems can only assign constant value not the same in c++
    a += 5;
    sa += 5;
    // show the difference 
    printf("a = %d, sa = %d\n", a, sa);
}


int main()
{
    int i;
    int iTest4;
    iTest4 = 2;
    printf("Address of iTest5: %x\n", &iTest5);
    static int iTest5;   // seems new static variable in bss segment
    printf("Address of iTest5: %x\n", &iTest5);
    for (i = 0; i < 3; ++i)
        foo();
    printf("%d%d\n", iTest,iTest2);
    printf("%d\n", iTest3);
    printf("%d\n", iTest5);    // 31 or 0? 0, Beacause iTest5 is a new bss segment variable.
    iTest5 = 50;
    printf("Address of iTest5: %x\n", &iTest5);
    printf("%d\n", iTest5);    // where is it? if move to data segment, will there has a conflict?
    return 0;
}




















