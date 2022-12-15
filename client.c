/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:50:53 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/15 17:46:07 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	handler(int sig, siginfo_t *id, void *nada)
{
	(void)id;
	(void)nada;
	if (sig == SIGUSR1)
	{
		write(1, "********************\n", 22);
		write(1, "* Message received *\n", 22);
		write(1, "********************\n", 22);
	}
	else
		return ;
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
			usleep(300);
		}
	}
	b = 8;
	while (b--)
	{
		kill(pid, SIGUSR2);
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa2;

	sa2.sa_sigaction = handler;
	sa2.sa_flags = SA_SIGINFO;
	sigemptyset(&sa2.sa_mask);
	sigaction(SIGUSR1, &sa2, NULL);
	if (argc != 3 || !(ft_strlen(argv[2])))
		return (-1);
	str2bin(ft_atoi(argv[1]), (unsigned char *) argv[2]);
	return (0);
}
