#include <stdio.h>

int main(void)
{
	int somescopedwork = 6;
	/* This is a reminder that C has subscopes which can be used to logically
	 * partition large procedures where certain blocks of code appear only once
	 * and need not be called from the outside world. In functional languages this
	 * is fine because compilers can tell, but here, it is safe to assume every
	 * function translates to a label and every call translates to a jump. */
	{
		int somescopedwork = 5;
		printf("inside the scope: %d\n", somescopedwork);
	}
	printf("outside the scope: %d\n", somescopedwork);

	return 0;
}
