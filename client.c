/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:50:53 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/05 16:37:40 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	handler(int sig)
{
	ft_printf("TOU A CORRER HEHE\n");
}


static void	str2bin(int pid, char *str)
{
	int	n;
	int	c;
	int	b;

	n = 0;
	while (str[n])
	{
		c = (int)str[n++];
		b = 8;
		while (b--)
		{
			if (c % 2)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c /= 2;
			usleep(100);
		}
	}
	b = 8;
	while (b--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char *argv[3])
{
	struct sigaction sa;
	
	sa.sa_handler = &handler;
	sa.sa_flags = SA_RESTART;
	
	if (argc != 3 || !(ft_strlen(argv[2])))
		return (-1);
	ft_printf("To: %d | Sent: %s\n", atoi(argv[1]), argv[2]);
	str2bin(atoi(argv[1]), argv[2]);
	sigaction(SIGUSR1, &sa, NULL);
	return (0);
}
