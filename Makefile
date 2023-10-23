# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 15:37:53 by victgonz          #+#    #+#              #
#    Updated: 2023/10/23 13:18:59 by victgonz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################# VARIABLES PROJECT #################

PROJECT = MINITALK

EXECUTABLE_SERVER = server

EXECUTABLE_CLIENT = client


################# COMPILATION #################

CC = gcc

CFLAGS = ##-Wall -Wextra -Werror -std=c99


################# FILES AND OBJECTS #################

SRC_DIR = src/

OBJ_DIR = obj/

SERVER_FILES	=	server_file

CLIENT_FILES	=	client_file

OBJECTS_SERVER = 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SERVER_FILES)))

OBJECTS_CLIENT = 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLIENT_FILES)))

OBJF		=	.cache_exists

################# LIBRARIES #################

INCLUDES = -I./include

LIBRARIES_DIR = libraries

INCLUDES_LIBRARIES = -I./$(LIBRARIES_DIR)/libft

LIBRARIES = -L./$(LIBRARIES_DIR)/libft

################# COLORS #################

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

################# STD MSG #################

START_COMPILATION = "$(MAGENTA)======>$(GREEN) STARTING COMPILATION: $(YELLOW)$(DEF_COLOR)";

CREATE_EXECUTABLE_SERVER = "$(MAGENTA)======>$(YELLOW) CREATING EXECUTABLE_SERVER: $(EXECUTABLE_SERVER). $(MAGENTA)<======$(DEF_COLOR)"

CREATE_EXECUTABLE_CLIENT = "$(MAGENTA)======>$(YELLOW) CREATING EXECUTABLE_CLIENT: $(EXECUTABLE_CLIENT). $(MAGENTA)<======$(DEF_COLOR)"

################# ACTION MAKEFILE #################

all: libraries $(EXECUTABLE_SERVER) $(EXECUTABLE_CLIENT) write_name

$(EXECUTABLE_SERVER): $(OBJECTS_SERVER)
	@echo $(CREATE_EXECUTABLE_SERVER)
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDES_LIBRARIES) $(LIBRARIES) $(OBJECTS_SERVER) -o $(EXECUTABLE_SERVER)

$(EXECUTABLE_CLIENT): $(OBJECTS_CLIENT)
	@echo $(CREATE_EXECUTABLE_CLIENT)
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDES_LIBRARIES) $(LIBRARIES) $(OBJECTS_CLIENT) -o $(EXECUTABLE_CLIENT)
	

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo $(START_COMPILATION)
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDES_LIBRARIES) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

write_name:
		@echo "$(MAGENTA)╔═════════════════════════════════════════╗$(DEF_COLOR)"
		@echo "$(MAGENTA)║                 $(CYAN)$(PROJECT)$(MAGENTA)                ║$(DEF_COLOR)"
		@echo "$(MAGENTA)╚═══════════════╦═════════╦═══════════════╝$(DEF_COLOR)"
		@echo "$(MAGENTA)                ║  $(GREEN)VIC'S$(MAGENTA)  ║$(DEF_COLOR)"
		@echo "$(MAGENTA)                ╚═════════╝     $(DEF_COLOR)"

clean:
	rm -f $(OBJECTS_SERVER)
	rm -f $(OBJECTS_CLIENT)
	make -C $(LIBRARIES_DIR)/libft clean
	@echo "$(MAGENTA)======>$(BLUE)$(EXECUTABLE_SERVER) object files cleaned!$(DEF_COLOR)"
	@echo "$(MAGENTA)======>$(BLUE)$(EXECUTABLE_CLIENT) object files cleaned!$(DEF_COLOR)"

fclean: clean
	rm -f $(EXECUTABLE_SERVER)
	rm -f $(EXECUTABLE_CLIENT)
	make -C $(LIBRARIES_DIR)/libft fclean
	@echo "$(MAGENTA)======>$(CYAN)$(EXECUTABLE_SERVER) executable files cleaned!$(DEF_COLOR)"
	@echo "$(MAGENTA)======>$(CYAN)$(EXECUTABLE_CLIENT) executable files cleaned!$(DEF_COLOR)"

re: fclean all

libraries:
	make -C $(LIBRARIES_DIR)/libft

.PHONY:		all clean fclean re