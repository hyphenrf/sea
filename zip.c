/*
 * zip.c
 * Copyright (C) 2020 hyphen <hyphens@pm.me>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>


int main(int argc, char* argv[])
{
	char l, r;

	FILE *left = fopen(argv[1], "r");
	FILE *rigt = fopen(argv[2], "r");

	if (left && rigt) {

		while ((l = getc(left)) != EOF 
		    && (r = getc(rigt)) != EOF) {
			putchar(l); 
			putchar(r);
		}

	}

	return 0;
}
