/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/04/21 10:50:16 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_action(int sig, siginfo_t *info, void *uncontext)
{
	static int				i;
	static unsigned char	uc;

	(void)uncontext;
	if (sig == SIGUSR2)
		uc |= (1 << i);
	i++;
	if (i == 8)
	{
		if (uc == 0)
		{
			kill(info->si_pid, SIGUSR2);
		}
		else
			write (1, &uc, 1);
		i = 0;
		uc = 0;
	}
}

void	receiver(void server_action(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_sigaction = server_action;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	receiver(server_action);
	while (1)
		pause ();
}
