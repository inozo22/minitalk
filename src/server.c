/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/04/04 14:22:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	server_action(int sig, siginfo_t *info, void *context)
{

<<<<<<< HEAD
=======
	uc = (unsigned char)c;
	i = -1;
	while (++i < 8)
	{
//youcheck
//		usleep(50);
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSR1 + bit) == -1)
			fatal("kill error");
	}
>>>>>>> 4ebbf35a4c8790d7b463cc50978b1d9f2e25deb2
}

void   receiver(void action(int, siginfo_t *, void *))
{
	struct sigaction    sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_sigaction = &action;
	sigemptyset(&sa.sa_mask);
<<<<<<< HEAD
	sa.sa_flag = SA_SIGINFO;
=======
	sa.sa_flags = SA_SIGINFO;//to pass pid, uid and info in siginfo_t
    //if doesn't use this above, only I can pass is signal number
>>>>>>> 4ebbf35a4c8790d7b463cc50978b1d9f2e25deb2
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int main(void)
{

    pid_t   pid;


//output pid//
    ft_putstr_fd("pid: ", 1);
    pid = getpid();
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
//keep running this process
    receiver(server_action);
 
    while (1)
        pause ();
//when it receives the string, it has to print it (as soon as possible as it can)


//After the first string, also it has to be able to accept strings without restart

    return (0);
}
