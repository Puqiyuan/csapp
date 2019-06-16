/*
	test result:
	~/.../ch2$ ./a.out 
	39 30 00 00
	00 e4 40 46
	2c 64 c5 15 fc 7f 00 00
*/

#include <stdio.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_int(int x)
{
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val)
{
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

int main(int argc, char *argv[])
{
	int x = 12345;
	test_show_bytes(x);
	
	return 0;
}

