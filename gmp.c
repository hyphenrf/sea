/* Playing with arbitrary percision ints */

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
	char *line = NULL;
	{ /* init a scope because we don't care about len */
		size_t len = 0;
		getline(&line, &len, stdin); /* read a decimal */
	}

	mpz_t num;
	mpz_init_set_ui(num,0); /* Init our MultiPrecisionZ(Integer) */
	                        /* and Set it as Unsigned Int. */
	
	mpz_set_str(num, line, 10); /* 10 is the base; set num from str (atoi) */
	free(line);
	
	line = mpz_get_str(NULL, 16, num); /* 16 is the base; get str from num */
	{ /* scoped because of disposable vars like p, buf */
		char *p = line;
		char buf[3];
		/* Comma is a sequencing operator. Computes then discards left value. */
		while((buf[0] = *p++, buf[1] = *p++, *buf)) {
			printf("%s", buf);
		}
		puts("");
	}

	/* Free your resources, make valgrind happy :) */
	mpz_clear(num);
	free(line);
	return 0;
}
