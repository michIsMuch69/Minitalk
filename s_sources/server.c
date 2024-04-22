/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:23:37 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/22 11:16:09 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "libft.h"
#include "server.h"

void    send_signal(int signum, int pid)
{
    if (kill(pid, signum) == -1)
        write(2, "Error\n", 6);
}

void    init_str(char **str, int pid)
{
    *str = NULL;
    *str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!*str)
    {
        send_signal(SIGUSR2, pid); //voir gestion d'erreur
        return ; // gestion d'erreur
    }
    send_signal(SIGUSR1, pid);
}

int init_server(struct sigaction *act)
{
    act->sa_handler = NULL;
    act->sa_sigaction = &handler; 
    act->sa_flags = SA_SIGINFO;
    sigemptyset(act->sa_mask);
    if (sigaction(SIGUSR1, act, NULL) || sigaction(SIGUSR2, act, NULL))
        return (1);
    return (0);
}

void    printf_msg(char **str, int pid, size_t *index, size_t *buffer_size)
{
    ft_printf("%s\n", *str);
    send_signal(SIGUSR2, pid);
    *index = 0;
    *buffer_size = BUFFER_SIZE;
    free(*str);
    *str = NULL;
    return ;
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
void    handler(int signum, siginfo_t *info, void *oldact)
{
    static char     *str;
    static short    bit_pos;
    static size_t   index;
    static size_t   buffer_size = BUFFER_SIZE;

    if (!str && info->si_pid > 0)
        init_str(&str, info->si_pid);
    if (signum == SIGUSR1)
        str[index] = str[index] <<= 1;
    else if (signum == SIGUSR2)
    {
        str[index] = str[index] <<= 1;
        str[index] = str[index] |= 1;
    }
    if (bit_pos++ == 7)
    {
        bit_pos = 0;
        if(str[index] == '\0')
           return (printf_msg(&str, info->si_pid, &index, &buffer_size));
        index++;
        if(index == buffer_size)
           expand_buffer(&str, &buffer_size, info->si_pid);
    }  
    send_signal(SIGUSR1, info->si_pid);
    return ;
}



int main(int argc, char **argv)
{
    struct sigaction act;           
    
    if(init_server(&act))
        return (1);
    if (ft_printf("PID Serveur = %d\n", getpid()) == -1)
        return (1);
    while (1)
        pause();
    return (0);
}
