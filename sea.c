#include <stdio.h> 
/* anything that starts with # is processed first 
 * by the compiler. It is then replaced in the code
 * file by its respective value. <> brackets mean
 * that the compiler should search for the file inside
 * them. stdio.h should exist in the default includes
 * directory since it was provided without a path.
 * if you want a specific file included you include it by path using quotes
 * instead of carets(?). so #include "/usr/include/stdio.h"
 */

int main(void) // int is the return type, main is the function name
               // and void means no arguments
{
        printf("from sea to shining C\n"); //printf doesn't insert newlines.
        return 0; // makes the compiler happy
}
