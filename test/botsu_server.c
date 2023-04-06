/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/04/06 13:39:40 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

/* static int	put_str(unsigned char *buf, int index, siginfo_t *info)
{
//	printf("Line: %d, index: %d\n", __LINE__, index);
	ft_putendl_fd((char *)buf, 1);
	ft_bzero(buf, index);
	kill(info->si_pid, SIGUSR2);
//	printf("Line: %d, info->si_pid: %d\n", __LINE__, info->si_pid);
	return (0);
} */

void	char_printer(int bit, int c_pid)
{
	static int i;
	static unsigned char uc;

	i = 0;
	uc = 0;
	if (i <= 7)
	{
		uc |= (bit << i);
		i++;
		kill(c_pid, SIGUSR1);
	}
	if (i > 7)
	{
		if (uc)
			write (1, &uc, 1);
		uc = 0;
		i = 0;
	}
}

/* static void	server_action(int sig, siginfo_t *info, void *context)
{
//	static unsigned char	buf[BUF_SIZE];
//	static int				index;
	static int				i;
	static unsigned char	uc;

	(void)context;
	if (sig == SIGUSR2)
	{
		uc |= (1 << i);
		kill(info->si_pid, SIGUSR1);
	}
	i++;
	if (i == 8)
	{
		if (index > BUF_SIZE - 1)
			_exit (0);
		if (uc == 0)
			index = put_str(buf, index, info);
		else
			buf[index++] = uc;
		if (uc)
			write(1, &uc, 1);
		i = 0;
		uc = 0;
	}
} */


void	server_action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	char_printer(sig == SIGUSR1, info->si_pid);
}

void	receiver(void action(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_sigaction = &server_action;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	pid_t	pid;

	ft_putstr_fd("pid: ", 1);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	receiver(server_action);
	while (1)
		pause ();
//	return (0);
}
