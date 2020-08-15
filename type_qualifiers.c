/* Types are read from right to left.
 * const can be put to the right of a type or the left of it interchangeably
 * The more consistent style is the "East Const" style, because it more strictly
 * follows the rtl rule for when pointers are involved (a constant pointer can
 * only be declared if const qualifier is to the right of it).
 */

const int a; /* west const style constant integer */
int const b; /* east const equivalent */

int const * c; /* pointer to const int */
int * const d; /* const pointer to (mutable) int */
const int * e; /* not as readable because it breaks the rtl rule */

/* base types, qualifiers, and declarators */
/*
 * 1- there can only be one base type
 * 2- qualifiers (and storage classes) alter the behaviour of the type
 * 3- declarators alter the identity of the type
 *
 * [], (), * --> declarators, attached to the NAME
 * static, volatile, extern, const, etc.. --> attached to the TYPE
 * int, bool, etc.. --> base types
 *
 * union, enum, struct are not Types, but can be typedeffed to act like ones.
 * They're in fact Tags.
 */

int const x[], *y, z(); /* a function z that returns const int, 
                         * pointer y to const int, 
                         * and array x of const ints in unknown size */
