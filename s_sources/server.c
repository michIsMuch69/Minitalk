/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:23:37 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/20 16:13:23 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "libft.h"
#include "server.h"

void    send_signal(int signum, int pid)
{
    if(kill(pid, signum) == -1)
        write(1, "Error\n", 6);
    
}
char    *init_str(int pid)
{
    char *str;
    
    str = NULL;
    str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!str)
        return (send_signal(SIGUSR2, pid), NULL); //voir gestion d'erreur
    send_signal(SIGUSR1, pid);
    return (str);
}



void handler(int signum, siginfo_t *info, void *oldact)
{
    static char     *str;
    static short    bit_pos;
    static size_t   index;
    static size_t   buffer_size = BUFFER_SIZE;
    char            *tmp;

    if (!str && info->si_pid > 0)
    {
        str = init_str(info->si_pid);
        if(!str)
            return ; // crash serveur ? gestion erreur
        return ; // retour au main
    } 
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
        {
            ft_printf("%s\n ", str);
            // for (int i = 0; i < 5; i++)
            //     ft_printf("%d\n", str[i]);
            send_signal(SIGUSR2, info->si_pid);
            index = 0;
            buffer_size = BUFFER_SIZE;
            free(str);
            str = NULL;
            return ;
        }
        index++;
        if(index == buffer_size)
        {
            tmp = ft_realloc(str, (buffer_size + BUFFER_SIZE + 1), ft_strlen(str));
            if (!tmp)
            {
                free(str);
                send_signal(SIGUSR2, info->si_pid);
                return ; //perror gestion
            }
            str = tmp;
            buffer_size += BUFFER_SIZE;
        }
    }  
    send_signal(SIGUSR1, info->si_pid);
    return ;
}


int main(int argc, char **argv)
{
    struct sigaction act;           
    
    act.sa_handler = NULL;
    act.sa_sigaction = &handler; 
    act.sa_flags = SA_SIGINFO;
    //sigemptyset(&(act.sa_mask));

    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    if (ft_printf("PID Serveur = %d\n", getpid()) == -1)
        return (1);
    while (1)
    {
        pause();
    }
    return (0);
}
