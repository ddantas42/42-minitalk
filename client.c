/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:50:53 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/07 08:55:13 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	handler(int sig)
{
	write(1, "TOU A CORRER HEHE\n", 18);
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

int	main(int argc, char **argv)
{
	if (argc != 3 || !(ft_strlen(argv[2])))
		return (-1);
	ft_printf("MY PID = %d\n", getpid());
	str2bin(ft_atoi(argv[1]), (unsigned char *) argv[2]);
	return (0);
}
