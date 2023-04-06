/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:33:59 by nimai             #+#    #+#             */
/*   Updated: 2023/04/06 13:36:43 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
//Retention of header files needs to be considered.

sig_atomic_t	volatile	flag;

void	send_char(pid_t srv_pid, char c)
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
		flag = 0;
		if (uc & 1)
			kill(srv_pid, SIGUSR1);
		else
			kill(srv_pid, SIGUSR2);
		i++;
		uc = uc >> 1;
		while (!flag)
			pause();
/* 		bit = (uc >> i) & 0x01;
		if (kill(srv_pid, SIGUSR1 + bit) == -1)
			_exit (0); */
	}
	flag = 0;
}

void	send_str(pid_t srv_pid, char *str)
{
/* 	if (ft_strlen(str) > BUF_SIZE - 1)
		_exit (0); */
	while (*str)
	{
		send_char(srv_pid, *str);
		str++;
	}
	send_char(srv_pid, '\0');
}

void	client_action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		flag = 1;
	if (sig == SIGUSR2)
		ft_putendl_fd("Successfull\n", 1);
//	_exit (0);
}

void	receiver(void action(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_sigaction = &client_action;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaddset(&sa.sa_mask, SIGUSR1);
//	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
//	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int ac, char **av)//accept server PID and str to send as arguments
{
	pid_t	srv_pid;
	//kokokara kesu
	pid_t	c_pid;


	c_pid = getpid();
	printf("c_pid: %d\n", c_pid);
	//

	if (ac != 3)
		return (0);
	errno = 0;
	srv_pid = (pid_t)ft_atoi(av[1]);
	if (errno != 0 || srv_pid < 1)
		return (0);
	receiver(client_action);
	send_str(srv_pid, av[2]);
//	return (0);
}
