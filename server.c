/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:42:09 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/06 10:24:54 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	handler(int sig, siginfo_t *info, void *nothing)
{
	static int				n = 0;
	static unsigned char	c = 0;
	static pid_t			client_pid = 0;

			
	(void)nothing;
	if (sig == 10)
		c += 128;
	n++;
	if (n == 8)
	{
		if (!c)
		{
			ft_printf("\n");
			client_pid = info->si_pid;
			ft_printf("client_pid = %d\n", client_pid); // PARA RETIRAR
			kill(client_pid, SIGUSR1);
		}
		else
			ft_printf("%c", c);
		n = 0;
		c = 0;
	}
	else
		c = c >> 1;
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server started\nPID = %d\n", getpid());
	ft_printf("Waiting signal...\n");
	while (1)
		pause();
	return (0);
}
