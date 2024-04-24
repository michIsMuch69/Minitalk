/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:12:44 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/24 10:22:13 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"

char *str;

void    print_error(char *msg)
{
    if (write(2, msg, ft_strlen(msg)) == -1)
        return ;
}

void    send_signal(int signum, int pid)
{  
    if(kill(pid, signum) == -1)
        write(2, "Error\n", 6);   
}

void    end_msg(size_t index)
{
    if (str[index] == '\0')
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

void    handler(int signum, siginfo_t *info, void *oldact)
{
    static short    bit_pos = 7;
    static size_t   index;
    static int      pid_server;

    if (!pid_server)
        pid_server = info->si_pid;
    else if (info->si_pid != pid_server)
        return ;
    if (signum == SIGUSR2)
        end_msg(index);
    if ((str[index] >> bit_pos) & (0x01 == 1))
        send_signal(SIGUSR2, info->si_pid);
    else
        send_signal(SIGUSR1, info->si_pid);
    if (--bit_pos == -1)
    {
        bit_pos = 7;
        if (str[index] != '\0')
            index++;
    }
}


int main(int argc, char **argv)
{
    int                 pid;
    struct sigaction    act;
    
    if (argc != 3)
        return (print_error("Invalid arg\n"), 0);
    str = argv[2];
    pid = atoi(argv[1]);
    if (pid <= 0)
        return (print_error("Error\n"), 0);
    act.sa_handler = NULL;
    act.sa_sigaction = &handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    if (sigaction(SIGUSR1, &act, NULL) || \
        sigaction(SIGUSR2, &act, NULL))
        return (print_error("Init error\n"), 0);
    send_signal(SIGUSR1, pid);
    while(1)
        pause();
    return (0);
}
