#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void	handle_sigtstp(int sig)
{
	printf("Stop not allowed\n");
}


int main(int ac, char **av)
{
	struct sigaction sa;
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGTSTP, &sa, NULL);
	
	int x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (0);
}


/* #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	//beginning timestamp
	struct timespec begin;
	timespec_get(&begin, TIME_UTC);
	struct timespec begin2;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin2);
	int	x = 15;
	long long i = 0;

	while (++i < 10000000)
	{
		x *= 2;
	}
	sleep(2);
	//ending timestamp
	struct timespec end;
	timespec_get(&end, TIME_UTC);
struct timespec end2;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end2);
	//display the different between the 2 timestamps
	double time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
	double time_spent2 = (end2.tv_sec - begin2.tv_sec) + (end2.tv_nsec - begin2.tv_nsec) / 1000000000.0;
	printf("Time it took to execute: %lf\n", time_spent);
	printf("Time2 it took to execute: %lf\n", time_spent2);
	return (0);
}
 */




/* #include <signal.h>
#include <stdio.h>
#include <strings.h>

// Signal handler for SIGINT
void	sigint_handler(int signal)
{
	if (signal == SIGINT)
		printf("\nIntercepted SIGINT!\n");
}

void set_signal_action(void)
{
	// Declare the sigaction structure
	struct sigaction	act;

	// Set all of the structure's bits to 0 to avoid errors
	// relating to uninitialized variables...
	bzero(&act, sizeof(act));
	// Set the signal handler as the default action
	act.sa_handler = &sigint_handler;
	// Apply the action in the structure to the
	// SIGINT signal (ctrl-c)
	sigaction(SIGINT, &act, NULL);
}

int	main(void)
{
	// Change SIGINT's associated action
	set_signal_action();
	// Infinite loop to give us time to do ctrl-c
	// as much as we want!
	while(1)
		continue ;
	return (0);
} */