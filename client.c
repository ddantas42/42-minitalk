/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:50:53 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/04 13:55:30 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char *argv[3])
{
	int	pid;

	if (ft_strlen(argv[2]) || argc != 3)
		return (-1);
			
	pid = atoi(argv[1]);

	ft_printf("To: %d | Sent: %s\n", pid, argv[2]);

	//signal(SIGUSR1, argv[2]);
	//signal(SIGUSR2, argv[2]);
	
	return (0);
}