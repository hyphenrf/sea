/*
 * test.c
 * counts digits of an int.
 *
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	long int num = strtol(argv[1], NULL, 10);
	//strtol from stdlib.h turns str to long int
	//see: https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm
	int c;
	c = 0;

	while( num != 0 )
	{
		num /= 10;
		c++;
	}

	printf("%d\n", c);
	return 0;
}
