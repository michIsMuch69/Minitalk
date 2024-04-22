/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-micheldusserre <jean-micheldusserr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:12:44 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/22 11:26:30 by jean-michel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"


char *str;

void    send_signal(int signum, int pid)
{
    
    if(kill(pid, signum) == -1)
        write(1, "Error\n", 6);
    
}

// gestionnaire de signaux.

void    handler(int signum, siginfo_t *info, void *oldact)
{
    static short    bit_pos = 7;
    static size_t   index;
  
    if (signum == SIGUSR2)
    {
        ft_printf("Message sent\n");
        kill(getpid(), SIGKILL);  
    }
    if ((str[index] >> bit_pos) & (0x01 == 1))
    {
        send_signal(SIGUSR2, info->si_pid);
    }
    else
    {
        send_signal(SIGUSR1, info->si_pid);
    }
    if (--bit_pos == -1)
    {
        bit_pos = 7;
        if (str[index] != 0)
            index++;
    }
}


int main(int argc, char **argv)
{
    int pid;
    struct sigaction act;
    
    if (argc != 3)
        return 1; //print-error
    pid = atoi(argv[1]);
    if (pid <= 0)
        return (1); //perror
    act.sa_handler = NULL;
    act.sa_sigaction = &handler; 
    act.sa_flags = SA_SIGINFO;
    str = argv[2];    
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);

    
    send_signal(SIGUSR1, pid);
    // while (i >= 0)
    //     {
    //        
    //         usleep(100);
    //         i--;
    //     }
    while(1)
    {
        pause();
        continue;
    }
    return (0);
}
