#ifdef TRIGRAPH
// gcc -trigraphs -DTRIGRAPH
??=include <stdio.h>

int main()
??<
	int a = 5; //stuff??/
	int b = 6; //     ^-- this (??/) is a trigraph, a common typo.
	// a trigraph is also a different repr of backslash\
		it is a line continuation character understood by most c compilers\
		which makes int b = 6 (effectively) a comment. Gcc is smart enough\
		to ignore this with a warning. but if you pass the -trigraphs option,\
		your program will not compile!

	printf("%d\n", a+b);
	return 0;
??>
#endif

#ifdef DIGRAPH
// gcc -digraphs -DDIGRAPH
%:include <stdio.h>
int main()
<%
	puts("imo digraphs look way nicer");
%>
#endif
