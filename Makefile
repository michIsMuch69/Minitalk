# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 11:12:19 by jedusser          #+#    #+#              #
#    Updated: 2024/05/01 09:18:23 by jedusser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NAME = client
S_NAME = server
HDR_PATH = ./header/

C_SRCS_DIR = ./c_sources/
S_SRCS_DIR = ./s_sources/

OBJS_PATH = .obj

C_SRCS = client.c client_utils.c
S_SRCS = server.c server_utils.c

LIBFT_PATH = ./libft/

LIBFT = $(LIBFT_PATH)libft.a

FLAGS = -g3 -Ilibft -Iheader -Wall -Wextra -Werror

C_OBJS = $(C_SRCS:%.c=$(OBJS_PATH)/%.o)
S_OBJS = $(S_SRCS:%.c=$(OBJS_PATH)/%.o)

C_HDRS = $(HDR_PATH)/client.h
S_HDRS = $(HDR_PATH)/server.h

default : all

all : $(LIBFT) $(C_NAME) $(S_NAME)

$(C_NAME) : $(C_OBJS) $(LIBFT) 
	$(CC) $(FLAGS) $^ -o $@
	
$(S_NAME) : $(S_OBJS) $(LIBFT)
	$(CC) $(FLAGS) $^ -o $@

$(LIBFT) :
	$(MAKE) -C libft/ all 	

$(OBJS_PATH)/%.o : $(C_SRCS_DIR)/%.c $(C_HDRS)
	mkdir -p .obj
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_PATH)/%.o : $(S_SRCS_DIR)/%.c $(S_HDRS)
	mkdir -p .obj
	$(CC) $(FLAGS) -c $< -o $@

clean    :
	@rm -rf $(OBJS_PATH)
	$(MAKE) -C $(LIBFT_PATH)/ clean

fclean    : 
	$(MAKE) -C $(LIBFT_PATH)/ fclean
	@rm -rf $(OBJS_PATH) $(C_NAME) $(S_NAME)

re        : fclean all

.PHONY    : clean fclean re default all
