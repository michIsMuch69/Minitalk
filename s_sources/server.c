/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:23:37 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/24 13:46:42 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int pid_client = 0;

void    init_str(char **str, int pid)
{
    *str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!*str)
    {
        send_signal(SIGUSR2, pid);
        exit(EXIT_FAILURE) ; // msg d'erreur
    }
    send_signal(SIGUSR1, pid);
}

void    printf_msg(char **str, int pid, size_t *index, size_t *buffer_size)
{
    ft_printf("%s\n", *str);
    send_signal(SIGUSR2, pid);
    *index = 0;
    *buffer_size = BUFFER_SIZE;
    free(*str);
    pid_client = 0;
    *str = NULL;
    return ;
}

void    handler(int signum, siginfo_t *info, void *oldact)
{
    static char     *str;
    static short    bit_pos;
    static size_t   index;
    static size_t   buffer_size = BUFFER_SIZE;

    if (!str && info->si_pid > 0)
    {
        init_str(&str, info->si_pid);
        pid_client = info->si_pid;
        return ;
    }
    if (pid_client != info->si_pid)
    {
        if (info->si_pid == getpid())
        {
            free(str);
            str = NULL;
            bit_pos = 0;
            index = 0;
            buffer_size = BUFFER_SIZE;
            pid_client = 0;
        }
        return ;
    }
    fill_str(str, signum, index);
    if (bit_pos++ == 7)
    {
        bit_pos = 0;
        if (str[index] == '\0')
           return (printf_msg(&str, info->si_pid, &index, &buffer_size));
        index++;
        if (index == buffer_size)
           expand_buffer(&str, &buffer_size, info->si_pid);
    }  
    send_signal(SIGUSR1, info->si_pid);
    return ;
}

int main(int argc, char **argv)
{
    struct sigaction act;
      
    
    if(init_server(&act))
        return (1); //perror        
    if (ft_printf("PID Serveur = %d\n", getpid()) == -1)
        return (1);
    while (1)
    {
        pause();
        while(pid_client != 0)
        {
            if (kill(pid_client, 0) == -1)
            {
                printf("OK ca marche\n");
                kill(getpid(), SIGUSR1);
            }
        }
        
    }
    return (0);
}
