/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:33:59 by nimai             #+#    #+#             */
/*   Updated: 2023/04/11 11:38:29 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
//Retention of header files needs to be considered.

static void	send_char(pid_t srv_pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = -1;
	while (++i < 8)
	{
		usleep(60);
		bit = (uc >> i) & 0x01;
		if (kill(srv_pid, SIGUSR1 + bit) == -1)
			_exit (0);
	}
}

static void	send_str(pid_t srv_pid, char *str)
{
	while (*str)
	{
		send_char(srv_pid, *str++);
	}
	send_char(srv_pid, '\0');
}

static void	client_action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR2)
		ft_putendl_fd("Successfull\n", 1);
	_exit (0);
}

void	receiver(void action(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_sigaction = &client_action;
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
