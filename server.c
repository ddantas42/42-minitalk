/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:42:09 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/05 16:49:51 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


static	void	handler(int sig, siginfo_t *client_pid)
{
	static int n = 0;
	static unsigned char c = 0;
	
	 // client_pid -> something like this
	if (sig == 10)
		c += 128;
	n++;
	if (n == 8)
	{
		if (!c)
		{
		// Por escrever bonus
			write(1, "\n", 2);
		
		}
		write(1, &c, 1);
		n = 0;
		c = 0;
	}
	else 
	c = c >> 1;
}

int	main(int argc, char *argv[])
{
	struct sigaction sa;
	
	sa.sa_handler = &handler;
	sa.sa_flags = SA_RESTART;
	options=ss.
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server started\nPID = %d\n", getpid());
	ft_printf("Waiting signal...\n");
	while (1)
		pause();
	return (0);
}