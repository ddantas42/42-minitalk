/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiper <hiper@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:50:53 by ddantas-          #+#    #+#             */
/*   Updated: 2022/12/04 20:26:36 by hiper            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*void str2bin(char *str)
{
	int n;
	char c;
	int b;

	n = 0;
	while (str[n])
	{
		c = str[n];
		b = 8;
		while (b--)
		{
			
		}
		n++;
	}
}*/

int main(int argc, char *argv[3])
{
	int	pid;

	if (argc != 3 || !(ft_strlen(argv[2])))
		return (-1);
			
	pid = atoi(argv[1]);

	ft_printf("To: %d | Sent: %s\nchar = %c | binary = %d\n", pid, argv[2], 'a', 'a'<<1);

	//str2bin(argv[2]);

	kill(pid, SIGUSR1); // 10
	sleep(1);
	kill(pid, SIGUSR2); // 12

	
	return (0);
}