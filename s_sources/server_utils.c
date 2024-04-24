/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:38:52 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/24 13:46:37 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void    fill_str(char *str, int signum, size_t index)
{
    if (signum == SIGUSR1)
        str[index] = str[index] <<= 1;
    else if (signum == SIGUSR2)
    {
        str[index] = str[index] <<= 1;
        str[index] = str[index] |= 1;
    }    
}

void    send_signal(int signum, int pid)
{
    if (kill(pid, signum) == -1)
        write(2, "Error\n", 6);
}

void    expand_buffer(char **str, size_t *buffer_size, int pid)
{
    char *tmp;

    tmp = ft_realloc(*str, (*buffer_size + BUFFER_SIZE + 1), ft_strlen(*str));
    if (!tmp)
    {
        free(*str);
        send_signal(SIGUSR2, pid);
        return ; //perror gestion
    }
    *str = tmp;
    *buffer_size += BUFFER_SIZE;
}

int init_server(struct sigaction *act)
{
    act->sa_handler = NULL;
    act->sa_sigaction = &handler; 
    act->sa_flags = SA_SIGINFO;
    sigemptyset(&act->sa_mask);
    if (sigaction(SIGUSR1, act, NULL) || sigaction(SIGUSR2, act, NULL))
        return (1);
    return (0);
}
