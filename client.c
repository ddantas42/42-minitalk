/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:50:53 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/06 10:18:37 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	handler(int sig)
{
	ft_printf("TOU A CORRER HEHE\n");
}


void	str2bin(int pid, unsigned char *str)
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
	struct sigaction	sa2;
	
	if (argc != 3 || !(ft_strlen(argv[2])))
		return (-1);
	sa2.sa_handler = &handler;
	sa2.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa2, NULL);
	str2bin(ft_atoi(argv[1]), (unsigned char *) argv[2]);

	ft_printf("MY PID = %d\n", getpid());
	return (0);
}
