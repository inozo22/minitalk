/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:33:59 by nimai             #+#    #+#             */
/*   Updated: 2023/04/17 10:06:19 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <time.h>//

void	send_char(pid_t srv_pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = -1;
	while (++i < 8)
	{
		bit = (uc >> i) & 0x01;
		if (kill(srv_pid, SIGUSR1 + bit) == -1)
		{
			_exit (0);
		}
		usleep(100);
	}
}

void	send_str(pid_t srv_pid, char *str)
{
	struct timespec begin;
	timespec_get(&begin, TIME_UTC);
	while (*str)
	{
		send_char(srv_pid, *str++);
	}
	struct timespec end;
	timespec_get(&end, TIME_UTC);
	double time_spent = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
	printf("Time it took to execute: %lf\n", time_spent);
	send_char(srv_pid, '\0');
}

void	client_action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR2)
		ft_putendl_fd("Success\n", 1);
	_exit (0);
}

void	receiver(void client_action(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_sigaction = client_action;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int ac, char **av)
{
	pid_t	srv_pid;

	if (ac != 3)
		return (0);
	errno = 0;
	srv_pid = (pid_t)ft_atoi(av[1]);
	if (errno != 0 || srv_pid < 1)
		return (0);
	receiver(client_action);
	send_str(srv_pid, av[2]);
	return (0);
}
