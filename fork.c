/* To run: gcc -march=native -o fork fork.c; ./fork; sleep 1 | sort */

/* Notes on the fork() syscall:
 * 	successive forks behave like a balanced binary tree
 * 	conditional forks cut subtrees from said tree
 *	forked code continues execution from where it was forked (that is, program
 *		counter doesn't reset)
 *	a fork() call returns pid-of-child on parent, and 0 on child
 *	a getpid() call returns current process id
 *	a getppid() call returns parent process id
 *	a wait() call is necessary for the child process to not turn into a zombie
 *		and be adopted by PID1
 *	on multiple fork() calls, the number of 0 values can be a sign on the
 *		process origins. If c1 and c2 are 0, c3 is a value, then you're on the
 *		process created by c1, that is c2, which calls fork and stores that in c3
 *
 *	the tree for the three successive unconditional fork() calls below is like
 *	so:
 *	-------- p ------------ 1st call to fork()
 *	       /   \
 *	----  p     c1 -------- 2nd call
 *	    /  \    /  \
 *	-- p   c2  c1   c2 ---- 3rd call
 *	 / |  / |  | \   | \
 *	p c3 c2 c3 c1 c3 c2 c3  rest of the program
 *
 */

#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <wait.h>

typedef uint64_t u64;
typedef uint32_t u32;

// timing: rdtscp is a post-pentium opcode that returns the number of cpu cycles
// since a ref point in time.
inline u64 rdtsc(void) {
	struct {u32 lo; u32 hi;} out;
	asm volatile ("rdtscp": "=a"(out.lo), "=d"(out.hi));
	return *(u64*)&out;
}


int main()
{
	pid_t c1, c2, c3;

	/* fork() && fork() || fork() */
	/* fork() && (fork() || fork()) */

	c1 = fork();
	wait(NULL); // we have to wait so getppid doesn't return PID1
	c2 = fork();
	wait(NULL);
	c3 = fork();
	wait(NULL);

	printf("cycle: %lu\t", rdtsc());
	printf("| my PID: %05d, my Parent: %05d\t", getpid(), getppid());
	printf("| values:: c1: %05d, c2: %05d, c3: %05d\n", c1, c2, c3);

	return 0;
}
