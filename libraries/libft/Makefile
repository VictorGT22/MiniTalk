# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 08:43:48 by victgonz          #+#    #+#              #
#    Updated: 2023/05/11 09:06:58 by victgonz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BONUS = .bonus

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putnbr_fd.c		\
		ft_putendl_fd.c		\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_strlen.c			\
		ft_bzero.c			\
		ft_calloc.c			\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_memset.c			\
		ft_itoa.c			\
		ft_split.c			\
		ft_strcat.c			\
		ft_strchr.c			\
		ft_strdup.c			\
		ft_striteri.c		\
		ft_strjoin.c		\
		ft_strlcat.c		\
		ft_strlcpy.c		\
		ft_strmap.c			\
		ft_strrchr.c		\
		ft_strtrim.c		\
		ft_substr.c			\
		ft_tolower.c		\
		ft_toupper.c		\
		ft_strncmp.c		\
		ft_strnstr.c		\
		ft_atoi.c			\

SRCSBONUS = ft_lstadd_back.c 	\
			ft_lstadd_front.c 	\
			ft_lstclear.c 		\
			ft_lstdelone.c 		\
			ft_lstiter.c 		\
			ft_lstlast.c 		\
			ft_lstmap.c 		\
			ft_lstnew.c 		\
			ft_lstsize.c

OBJS 	= 	$(SRCS:.c=.o)

OBJSBONUS = $(SRCSBONUS:.c=.o)

INCLUDES = libft.h

CFLAGS	+=	-Wall -Werror -Wextra

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "compiling: $<"

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

bonus: $(BONUS)

$(BONUS) : $(OBJS) $(OBJSBONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJSBONUS)

clean:
			rm -f $(OBJS) $(OBJSBONUS)

fclean:		clean
			rm -f $(NAME)

re:			all clean

.PHONY:		all bonus clean fclean re