/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:33:59 by nimai             #+#    #+#             */
/*   Updated: 2023/05/08 09:29:58 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Only works for macOS

//20230507 This function is for test if it works on Linux
/* void	send_char(pid_t srv_pid, char c)
{
	int				bit;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = -1;
	while (++i < 8)
	{
		usleep(500);
		bit = (uc >> i) & 0x01;
		if (bit == 0)
		{
			if (kill(srv_pid, SIGUSR1) == -1)
			{
				exit (1);
			}
		}
		else if (bit == 1)
		{
			if (kill(srv_pid, SIGUSR2) == -1)
			{
				exit (1);
			}
		}
		usleep(500);
	}
} */
//20230507 This function is for test if it works on Linux

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
			exit (1);
		}
		usleep(100);
	}
}

void	send_str(pid_t srv_pid, char *str)
{
	while (*str)
	{
		send_char(srv_pid, *str++);
	}
	send_char(srv_pid, '\0');
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
	send_str(srv_pid, av[2]);
}
