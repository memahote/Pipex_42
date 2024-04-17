################################## VARIABLES ###################################

NAME			= pipex
# NAME_BONUS     	= pipex_bonus

# ----- FOLDERS ----- #

INC_DIR		= 	include/
LIB_DIR		= 	libft/
SRC_DIR		=	source/
OBJ_DIR		= 	obj/


# ----- FILES ----- #

LIST_SRC	= 	do_cmd.c close_and_free.c get_path_from_envp.c \
				get_path.c pipex.c process.c 

LIST_SRC_B	= 	pipex_bonus.c do_cmd_bonus.c close_and_free.c \
				get_path_from_envp.c get_path.c 

# ----- SHORTCUTS ----- #

INC			= $(addprefix $(INC_DIR), pipex.h)
LIBFT       = $(addprefix $(LIB_DIR), libft.a)
SRC			= $(addprefix $(SRC_DIR), $(LIST_SRC))
SRC_B       = $(addprefix $(SRC_DIR), $(LIST_SRC_B))
OBJ         = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
OBJ_B       = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_B))
DEP			= $(patsubst %.c, $(OBJ_DIR)%.d, $(SRC))

# ----- Compiler -----

CC				= cc
RM				= rm -rf
FLAG			= -Wall -Wextra -Werror -g3
DEP_FLAGS		= -MMD -MP
MKDIR           = mkdir -p
MAKE            = make -C

################################## RULES ###################################

all:	$(NAME)

# bonus: $(NAME_BONUS)

$(NAME):	$(LIBFT) $(OBJ)
			$(CC) $(FLAG) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft

bonus: 	$(LIBFT) $(OBJ_B)
				$(CC) $(FLAG) -o $(NAME) $(OBJ_B) -L $(LIB_DIR) -lft

$(LIBFT):	FORCE
		$(MAKE) $(LIB_DIR)

-include $(DEP)

$(OBJ_DIR)%.o: %.c 
	$(MKDIR) $(@D)
	$(CC) $(FLAG) $(DEP_FLAGS) -I $(INC_DIR) -c $< -o $@

clean:		
			$(MAKE) $(LIB_DIR) clean
			${RM} $(OBJ_DIR)

fclean:		clean
			$(MAKE) $(LIB_DIR) fclean
			${RM} ${NAME}
			${RM} ${NAME_BONUS}

re:			fclean all

FORCE:

.PHONY:         all bonus clean fclean FORCE re 
