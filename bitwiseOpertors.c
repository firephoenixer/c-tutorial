// C Program to demonstrate use of bitwise operators
#include <stdio.h>
int main()
{
	// a = 5(00000101), b = 9(00001001)
    // b = 9(00001001)
	unsigned char a = 5, b = 9;

	// The result is 00000001
	printf("a = %d, b = %d\n", a, b);
	printf("a&b = %d\n", a & b);  // & : bitwise and

	// The result is 00001101
	printf("a|b = %d\n", a | b);  // | : bitwise or 

	// The result is 00001100
	printf("a^b = %d\n", a ^ b);  // ^ : bitwise xor

	// The result is 11111010
	printf("~a = %d\n", a = ~a);  // ~ ：bitwise not

	// The result is 00010010
	printf("b<<1 = %d\n", b << 1);  // << : bitwise left shift (new bit filled by 0)

	// The result is 00000100
	printf("b>>1 = %d\n", b >> 1);  // >> : bitwise right shift

	return 0;

}
