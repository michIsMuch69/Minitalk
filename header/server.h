/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:27:17 by jedusser          #+#    #+#             */
/*   Updated: 2024/04/28 12:36:00 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "libft.h"

void    fill_str(char *str, int signum, size_t index);
void    send_signal(int signum, int pid);
void    expand_buffer(char **str, size_t *buffer_size, int pid);
int		init_server(struct sigaction *act);
void    handler(int signum, siginfo_t *info, void *oldact);
void    reinit_var(char **str, short *bit_pos, size_t *index, size_t *buffer_size);
void	print_error(char *msg);


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#endif


