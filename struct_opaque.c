#include <stdlib.h>

/* opaque pointers
 * The idea behind opaque pointers is that you can use a combination of typedef,
 * struct, and pointers to achieve encapsulation of your data structure
 * implementation. This is impoertant when designing an API. The way to do this
 * is as follows: */


/* library.h */

struct internal_string;                   // alternative 0
typedef struct internal_string string;    // alternative 1
typedef struct internal_string * stringp; // alternative 2
/* all of the above is considered opaque */


/* library.c */

struct internal_string {
	char * ptr;
	size_t len;
};


/* And with this, when someone uses your header they'll be able to pass strings,
 * but not access (or know about) individual fields of the struct.
 * It's also useful because it removes the need to recompile on layout changes,
 * as the only way to interact with fields is via API functions. Of course this
 * comes with drawbacks; namely being opaque is in itself a drawback for
 * space-conscious programmers. It's the job of the API designer to make those
 * decisions.
 * Because C is pretty flexible, you can have it both ways really.
 * Here's how: */


/* addition to library.h */

#ifndef STRICT
#warning "You're using internal representations of the API which may break between versions. This is provided without support."

struct internal_string {
	//...
};

#endif

/* note that with this you'll need to maintain the definition in two separate
 * places.
 * TODO: see if you can use CPP in a clever way to issue the warning for API
 * users but silence it for yourself as the implementor, thus only needing one
 * struct definition? but maybe actually it still won't work because the
 * definition has to exist somewhere when STRICT is defined. */

