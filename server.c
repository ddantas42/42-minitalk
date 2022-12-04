/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:42:09 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/04 20:25:35 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void handler(int sig)
{
	ft_printf("\nSig = %d\n", sig);
}

int main(int argc, char *argv[])
{
	int	pid;
	
	struct sigaction sa;
	sa.sa_handler = &handler;
	sa.sa_flags = SA_RESTART;
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	pid = getpid();

	ft_printf("Server started\nPID = %d\n", pid);
	ft_printf("Waiting signal...\n");

	while (1)
		pause();
	return (0);
}