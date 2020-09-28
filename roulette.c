#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/random.h>


bool
isnum(char *numstr) 
{
	int len = strlen(numstr);
	for (int i=0; i<len; i++) {
		if (numstr[i] < 0x30 || numstr[i] > 0x39)
			return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	unsigned short upto = 6, rndm;

	if (argc > 1) {	
		if (isnum(argv[1]))
			upto = (upto = atoi(argv[1])) ? upto : 1; //Never be zero
		else 
			goto err;
	}

	FILE *urand = fopen("/dev/urandom", "r");
	fread(&rndm, sizeof(rndm), 1, urand);

	printf("%d\n", rndm % upto);
	return EXIT_SUCCESS;

err:
	fputs("This is not a valid number.\n", stderr);
	return EXIT_FAILURE;
}
