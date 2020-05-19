/* This program converts the distance of a marathon in miles and yards
 * to kilometers.
 *
 * A marathon is 26 miles and 385 yards
 * 1 mile = 1.609 km
 * 1 yard = 1.609/1760.0 km
 *
 */

#include <stdio.h>

int main(void)
{
        int miles, yards; // vars are declared before they are used
        float kilometers;

        miles = 26;
        yards = 385;

        kilometers = (miles + yards/1760.0) * 1.609;
        // dividing should be over floats

        printf("A marathon is %f kilometers.\n", kilometers);
        // %f is a format paramiter. It looks for its value by type and
        // precedence.

        return 0;
}
