#include <stdio.h>
#include "defines.h"

/* nonstandard includes are quoted instead of using angle
 * brackets. Those header files are expected to be found
 * in the working directory where the compilation happens
 * you may include headers in subdirs as well.
 */

int globalVariable = 10; // globals must be assigned at declaration
// assigning is often referred to as initialization when done first time


int main()
{
    int declaredLocal; // only local variables can be declared empty
    declaredLocal = 5;

    printf("PI, imported from defines.h: %.2f\n\
globalVariable, accessed by all funcs: %d\n\
another way to assign vars is declare in a \n\
line then assign in another. Like declaredLocal: %d\n", PI, globalVariable, declaredLocal);

    int x = 5/2.0; // type int to float will discard any fractions

    printf("%.2f\n",(float) x); // (type) casting
    return 0;
}

