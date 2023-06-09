# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollo <pollo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 10:24:02 by pollo             #+#    #+#              #
#    Updated: 2023/06/02 10:28:02 by pollo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LDFLAGS := ${LDFLAGS}
CPPFLAGS := ${CPPFLAGS}

CFLAGS = -Wall -Wextra -Werror $(CPPFLAGS) -I$(INCDIR) -I$(LIBFTDIR)
SRCFILES = error_msg.c main.c motion_math.c parser_map.c 
OBJFILES = $(SRCFILES:.c=.o)

SRCOBJ = $(addprefix $(OBJDIR), $(OBJFILES))

SRCDIR = src/
INCDIR = include/
OBJDIR = obj/
LIBFTDIR = libft/

all: $(NAME)

debug: CFLAGS += -g
debug: re

$(NAME): $(SRCOBJ)
	$(MAKE) -C $(LIBFTDIR)
	@gcc $^ $(LIBFTDIR)libft.a $(LDFLAGS) -o $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p obj
	gcc -c $(CFLAGS) $^ -o $@

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re