/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:33:59 by nimai             #+#    #+#             */
/*   Updated: 2023/04/02 16:17:54 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
//Retention of header files needs to be considered.



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
		bit = (uc >> i) & 0x01;
		if (kill(srv_pid, SIGUSR1 + bit) == -1)
			return (0);//
	}
}

static void	send_str(pid_t srv_pid, char *str)
{
	if (ft_strlen(str) > BUFFER_SIZE - 1)
		return (0);//
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
		return (0);//
	exit(0);//
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

int	main(int ac, char **av)//accept server PID and str to send as arguments
{
	pid_t	srv_pid;
	//somosomo, after execute the server, I execute client by my self?
	if (ac != 3 || !ft_strlen(av[2]))//I think PID it's necessary?
		return (0);
	//I have to send the str to server.
	//Only I can communicate between client and server throw the UNIX signal
	errno = 0;
	srv_pid = (pid_t)ft_atoi(av[1]);
	receiver(client_action);
	send_str(srv_pid, av[2]);
	return (0);
}
