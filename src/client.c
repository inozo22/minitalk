/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:33:59 by nimai             #+#    #+#             */
/*   Updated: 2023/04/02 17:33:59 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"


int	main(int ac, char **av)//accept server PID and str to send as arguments
{
	//somosomo, after execute the server, I execute client by my self?
	if (ac != 3 || !ft_strlen(av[2]))//I think PID it's necessary?
		return (0);
	//I have to send the str to server.
	//Only I can communicate between client and server throw the UNIX signal
	
	return (0);
}
