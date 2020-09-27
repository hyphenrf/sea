#include <stdio.h>
/* 
 * Static fields in C retain their value across the program's runtime. We can
 * use them the same way we'd use python generators for example:
 */
	
int
num_generator(void)
{
	static int arthur = -1;
	           arthur++;
	return arthur;
}

int main(int argc, char* argv[])
{
	printf("%d\n", num_generator()); //0
	printf("%d\n", num_generator()); //1
	printf("%d\n", num_generator()); //2
	printf("%d\n", num_generator()); //3
	printf("%d\n", num_generator()); //4
	//...
	//upto INT_MAX
	
	return 0;
}
