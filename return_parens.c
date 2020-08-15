/*
 * in the old days of C, return required parens
 * so you'd type something like return(0);
 *
 * But now return (and as a matter of fact, sizeof too) 
 * don't require parens.
 */

int main(int argc, char* argv[])
{
	int x, y;

	x = sizeof y; /* valid! */
	/* y = sizeof int; /1* Invalid! *1/ */
	y = sizeof(int); /* Required :( */

	return(0); /* Valid! */
}
