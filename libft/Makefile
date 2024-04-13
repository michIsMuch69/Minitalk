NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar -rcs
SRCS = ft_printf.c  ft_print_hex_up.c ft_print_hex_low.c ft_print_unsigned_dec.c ft_print_pointer.c ft_print_str.c ft_print_char.c ft_print_decimal.c  ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_putchar_fd.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c ft_calloc.c ft_atoi.c ft_strnstr.c ft_memcmp.c ft_memchr.c ft_strncmp.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_isalnum.c ft_isdigit.c ft_memmove.c ft_strlen.c ft_isalpha.c ft_isprint.c ft_memset.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memcpy.c ft_strlcpy.c ft_toupper.c
BONUS_SRCS = ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	clean fclean re all bonus