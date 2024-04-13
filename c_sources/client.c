/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:12:44 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/13 17:20:04 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft.h"


char str;
int pid;
// gestionnaire de signaux.

void    handler(int signum)
{
    
    if(signum == SIGUSR1)
    {
        
    }
    else if (signum == SIGUSR2)
        ft_printf("sigusr2\n");
}


int main(int argc, char **argv)
{
    int pid;
    int     i;

    i = 7;
    str = 'l';
    
    pid = atoi(argv[1]);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (i >= 0)
        {
            if((str >> i) & 0x01 == 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(100);
            i--;
        }
    // while(1)
    // {
    //     pause();
    //     continue;
    // }
    return (0);
}
