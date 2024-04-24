/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:23:37 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/24 14:54:27 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int pid_client = 0;

void    init_str(char **str, int pid)
{
    pid_client = pid;
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
    reinit_var(str, NULL, index, buffer_size);
    ft_printf("\nPID SERVER %d\n", getpid());
    return ;
}
void    reinit_var(char **str, short *bit_pos, size_t *index, size_t *buffer_size)
{   
    free(*str);
    *str = NULL;
    if(bit_pos)
        *bit_pos = 0;
    *index = 0;
    *buffer_size = BUFFER_SIZE;
    pid_client = 0;
}

void    handler(int signum, siginfo_t *info, void *oldact)
{
    static char     *str;
    static short    bit_pos;
    static size_t   index;
    static size_t   buffer_size = BUFFER_SIZE;

    if (!str && info->si_pid > 0)
        return (init_str(&str, info->si_pid));
    if (pid_client != info->si_pid)
    {
        if (info->si_pid == getpid())
           reinit_var(&str, &bit_pos, &index, &buffer_size);
        return ;
    }
    fill_str(str, signum, index);
    // check char traite entierement
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
                kill(getpid(), SIGUSR1); //perror
        }
    }
    return (0);
}
