/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:23:37 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/29 10:53:58 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_pid_client = 0;

void	init_str(char **str, int pid)
{
	g_pid_client = pid;
	*str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!*str)
	{
		print_error("Alloc error\n");
		send_signal(SIGUSR2, pid);
		exit(EXIT_FAILURE);
	}
	send_signal(SIGUSR1, pid);
}

void	printf_msg(char **str, int pid, size_t *index, size_t *buff_size)
{
	ft_printf("%s\n", *str);
	send_signal(SIGUSR2, pid);
	reinit_var(str, NULL, index, buff_size);
	ft_printf("\nPID SERVER %d\n", getpid());
	return ;
}

void	reinit_var(char **str, short *bit_pos, size_t *i, size_t *buff_size)
{
	free(*str);
	*str = NULL;
	if (bit_pos)
		*bit_pos = 0;
	*i = 0;
	*buff_size = BUFFER_SIZE;
	g_pid_client = 0;
}

void	handler(int signum, siginfo_t *info, void *oldact)
{
	static char		*str;
	static short	bit_pos;
	static size_t	index;
	static size_t	buff_size = BUFFER_SIZE;

	(void) oldact;
	if (!str && info->si_pid > 0)
		return (init_str(&str, info->si_pid));
	if (g_pid_client != info->si_pid)
	{
		if (info->si_pid == getpid())
			reinit_var(&str, &bit_pos, &index, &buff_size);
		return ;
	}
	fill_str(str, signum, index);
	if (bit_pos++ == 7)
	{
		bit_pos = 0;
		if (str[index] == '\0')
			return (printf_msg(&str, info->si_pid, &index, &buff_size));
		index++;
		if (index == buff_size)
			expand_buffer(&str, &buff_size, info->si_pid);
	}
	return (send_signal(SIGUSR1, info->si_pid));
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (init_server(&act))
		return (1);
	if (ft_printf("PID Serveur = %d\n", getpid()) == -1)
		return (1);
	while (1)
	{
		pause();
		while (g_pid_client != 0)
		{
			if (kill(g_pid_client, 0) == -1)
			{
				print_error("\nClient not responding\n");
				kill(getpid(), SIGUSR1);
			}
		}
	}
	return (0);
}
