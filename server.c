/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:42:09 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/09 16:02:33 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	handler(int sig, siginfo_t *id, void *nada)
{
	static int				n = 0;
	static unsigned char	c = 0;
	int						client_pid;

	(void)nada;
	if (sig == 10)
		c += 128;
	n++;
	if (n == 8)
	{
		if (!c)
		{
			client_pid = id->si_pid;
			write(1, "\n", 1);
			kill(client_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		n = 0;
		c = 0;
	}
	else
		c = c >> 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server started\nPID = %d\n", getpid());
	ft_printf("Waiting signal...\n");
	while (1)
		pause();
	return (0);
}
