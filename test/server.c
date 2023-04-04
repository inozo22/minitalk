/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/04/04 07:50:30 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	server_action(int sig, siginfo_t *info, void *context)
{
	static unsigned char	buf[BUFFER_SIZE];
	static int				index;
	static int				i;
	static unsigned char 	uc;

	(void)context;
	if (sig == SIGUSR2)
		uc |= (1 << i);
	i++;
	if (i == 8)
	{
		if (index > BUFFER_SIZE - 1)
			;
		if (uc == 0)
			index = ;
		else
			buf[index++] = uc;
		i = 0;
		uc = 0;
	}
}

void   receiver(void action(int, siginfo_t *, void *))
{
	struct sigaction    sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_sigaction = &action;
	sigemptyset(&sa.sa_mask);
	sa.sa_flag = SA_SIGINFO;
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
