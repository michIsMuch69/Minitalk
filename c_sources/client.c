/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:12:44 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/30 14:12:55 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*g_str;

int	init_client(struct sigaction *act)
{
	act->sa_handler = NULL;
	act->sa_sigaction = &handler;
	act->sa_flags = SA_SIGINFO;
	sigemptyset(&act->sa_mask);
	if (sigaction(SIGUSR1, act, NULL) || sigaction(SIGUSR2, act, NULL))
		return (print_error("Init error\n"), 1);
	return (0);
}

void	send_signal(int signum, int pid)
{
	if (kill(pid, signum) == -1)
		write(2, "Error\n", 6);
}

void	end_msg(size_t index)
{
	if (g_str[index] == '\0')
	{
		ft_printf("Message sent\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Crash Server\n");
		exit(EXIT_FAILURE);
	}
}

void	handler(int signum, siginfo_t *info, void *oldact)
{
	static short	bit_pos = 7;
	static size_t	index;
	static int		pid_server;

	(void) oldact;
	if (!pid_server)
		pid_server = info->si_pid;
	else if (info->si_pid != pid_server)
		return ;
	if (signum == SIGUSR2)
		end_msg(index);
	if ((g_str[index] >> bit_pos) & (0x01 == 1))
		send_signal(SIGUSR2, info->si_pid);
	else
		send_signal(SIGUSR1, info->si_pid);
	if (--bit_pos == -1)
	{
		bit_pos = 7;
		if (g_str[index] != '\0')
			index++;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	if (init_client(&act))
		return (1);
	if (argc != 3)
		return (print_error("Invalid arg\n"), 0);
	g_str = argv[2];
	pid = atoi(argv[1]);
	if (pid <= 0)
		return (print_error("Error\n"), 0);
	send_signal(SIGUSR1, pid);
	//ft_printf("pid client = %d\n", getpid());
	while (1)
	{
		if (kill(pid, 0) == -1)
		{
			print_error("\nServer is not responding\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
