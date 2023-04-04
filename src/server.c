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

void	send_char(pid_t pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = -1;
	while (++i < 8)
	{
//youcheck
//		usleep(50);
		bit = (uc >> i) & 0x01;
		if (kill(pid, SIGUSER1 + bit) == -1)
			fatal("kill error");
	}
}

void    receiver(void handler(int, siginfo_t *, void *))
{
	struct sigaction    sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flag = SA_SIGINFO;//to pass pid, uid and info in siginfo_t
    //if doesn't use this above, only I can pass is signal number
	sigaction(SIGUSER1, &sa, NULL);
	sigaction(SIGUSER2, &sa, NULL);
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
    receiver();
 
    while (1)
        pause ();
//when it receives the string, it has to print it (as soon as possible as it can)


//After the first string, also it has to be able to accept strings without restart

    return (0);
}
