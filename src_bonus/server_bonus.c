/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/04/27 10:04:33 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	server_action(int sig, siginfo_t *info, void *ucontext)
{
	static int				i;
	static unsigned char	uc;

	(void)ucontext;
	if (sig == SIGUSR2)
		uc |= (1 << i);
	i++;
	if (i == 8)
	{
		if (uc == 0)
			kill(info->si_pid, SIGUSR2);
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
	ft_printf("PID: %d\n", getpid());
	receiver(server_action);
	while (1)
		pause ();
	return (0);
}
