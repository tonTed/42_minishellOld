# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tonted <tonted@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 19:00:35 by tonted            #+#    #+#              #
#    Updated: 2022/04/28 08:06:50 by tonted           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Configuration of paths
SRCDIR := src
OBJDIR := obj
INCDIR := include
LIBFTDIR := libraries/libft

# Name of the final executable
NAME = minishell

# Decide whether the commands will be shwon or not
VERBOSE = TRUE

# Create the list of directories
DIRS = $(shell find $(SRCDIR) -type d | sed 's/$(SRCDIR)\///g' | sed -n '1!p')
SRCDIRS	= $(foreach dir, $(DIRS), $(addprefix $(SRCDIR)/, $(dir)))
OBJDIRS = $(foreach dir, $(DIRS), $(addprefix $(OBJDIR)/, $(dir)))

# Create a list of *.c sources in DIRS
SRCS = $(wildcard src/*.c)
SRCS += $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

# Define objects for all sources
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Name the compiler & flags
CC = clang

CFLAGS = -iquote$(INCDIR)
# CFLAGS += -Wall -Wextra -Werror

LIBS = -L./libraries/libft -lft -L./libraries/readline -lreadline -lncurses

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(HIDE)$(CC) $(CFLAGS) -c  $< -o $@

all			: buildrepo $(NAME)

$(NAME)		: $(OBJS)
	$(HIDE)$(MAKE) -C $(LIBFTDIR)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@printf $(GREEN)"[$@] program created\n"$(RESET)

clean		:
	$(HIDE)rm -rf $(OBJDIR)
	$(HIDE)$(MAKE) clean -C $(LIBFTDIR)
	@printf $(YELLOW)"[$(NAME)] objects removed\n"$(RESET)

fclean		: clean
	$(HIDE)rm -f $(NAME)
	$(HIDE)$(MAKE) fclean -C $(LIBFTDIR)

re			: fclean all

buildrepo	:
	$(HIDE)$(call make-repo)

print	:
	@echo $(DIRS)
	@echo $(SRCS)


# Test
leak = 
leak = -valgrind --leak-check=full

test	: all
	$(leak) ./minishell

docker	:
	docker build . -t 42:minishell
	docker run --rm -it --name minishell -v /Users/tonted/42/minishell:/minishell 42:minishell


.PHONY		: clean fclean all re $(OBJDIR) buildrepo print

LIBRLINE = readline-8.1
readline	:
	curl -O ftp://ftp.cwru.edu/pub/bash/$(LIBRLINE).tar.gz
	tar -xf $(LIBRLINE).tar.gz
	rm -rf $(LIBRLINE).tar.gz
	cd $(LIBRLINE) && bash configure && make
	mv ./$(LIBRLINE)/libreadline.a ./libraries/readline
	rm -rf $(LIBRLINE)
	
	
# Create
define make-repo
	$(HIDE)mkdir -p $(OBJDIR)
	$(HIDE)for dir in $(DIRS); \
   	do \
	mkdir -p $(OBJDIR)/$$dir; \
   	done
endef

# Color
BLACK := "\e[0;30m"
RED := "\e[0;31m"
GREEN := "\e[0;32m"
YELLOW := "\e[0;33m"
BLUE := "\e[0;34m"
MAGENTA := "\e[0;35m"
CYAN := "\e[0;36m"
RESET :="\e[0m"

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
    HIDE =
else
    HIDE = @
endif