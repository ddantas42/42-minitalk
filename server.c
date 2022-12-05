/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:42:09 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/05 17:16:01 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


static	void	handler(int sig)
{
	static int n = 0;
	static unsigned char c = 0;
	//int client_pid;

	//client_pid = info -> si_pid;
	
	if (sig == 10)
		c += 128;
	n++;
	if (n == 8)
	{
		if (!c)
		{
		// Por escrever bonus
			write(1, "\n", 2);
			//kill(client_pid, SIGUSR1);
		}
		if (c >= 32 && c <= 126)
			ft_printf("%c", c);
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
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server started\nPID = %d\n", getpid());
	ft_printf("Waiting signal...\n");
	while (1)
		pause();
	return (0);
}