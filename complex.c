#include <complex.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
	complex double x = 16+2i;
	complex double y = -9+1i;
	
	printf("% .3f,  % .3fi\n", creal(x), cimag(x));
	printf("% .3f,  % .3fi\n", creal(y), cimag(y));
	printf("% .3f,  % .3fi\n", creal(x+y), cimag(x+y));
	printf("% .3f,  % .3fi\n", creal(x-y), cimag(x-y));
	printf("% .3f, % .3fi\n", creal(x*y), cimag(x*y));
	printf("% .3f, % .3fi\n", creal(x/y), cimag(x/y));
	printf("% .3f\n", creal(x)-creal(y));

	return 0;
}
