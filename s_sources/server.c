/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:23:37 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/13 17:21:21 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "libft.h"

void handler(int signum, siginfo_t *info, void *oldact)
{
    if (signum == SIGUSR1)
        ft_printf("0");
    else if (signum == SIGUSR2)
        ft_printf("1");
}

int main(int argc, char **argv)
{
    struct sigaction act;
    
    act.sa_handler = NULL;
    act.sa_sigaction = &handler; 
    //sigemptyset(&(act.sa_mask));
    act.sa_flags = SA_SIGINFO;
    if (ft_printf("PID Serveur = %d\n", getpid()) == -1)
        return (0);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    while (1)
    {
        pause();
        ft_printf("\n Ici \n");
    }
    return (0);
}
