/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:50:53 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/04 12:34:54 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char *argv[3])
{
	int	pid;

	if (!argv[1] || argc == 1)
		return (-1);
		
	pid = atoi(argv[1]);

	ft_printf("To: %d | Sent: %s\n", pid, argv[2]);

	//signal(SIGUSR1, action);
	//signal(SIGUSR2, action);
	kill(pid, SIGUSR1);
	return (0);
}