NAME := minishell
CC := clang
OBJ_DIR := obj

LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

CFLAGS := -Wall -Wextra -Werror -g
CPPFLAGS := -I$(LIBFT_DIR) -MMD
S_FLAGS := -fsanitize=address
LDFLAGS := -L$(LIBFT_DIR) -lreadline
LDLIBS := -lft

SRC_C :=	
			
SRC_M :=	main.c		eclown_func1.c		ft_split_new.c

SRC_B :=	main.c

SRC := 		$(SRC_C) $(SRC_M)
SRC_B :=	$(SRC_B) $(SRC_C)

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_B := $(SRC_B:%.c=$(OBJ_DIR)/%.o)

DEP := $(OBJ:.o=.d)
DEP_B := $(OBJ_B:.o=.d)

.PHONY: all clean fclean re bonus

all:	$(NAME)
bonus:
	@make OBJ="$(OBJ_B)" DEP="$(DEP_B)" all

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) $(S_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(S_FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT_LIB): libft1

libft1:
	@$(MAKE) -C $(LIBFT_DIR)

-include $(DEP) $(DEP_B)

clean:
	@rm -f $(OBJ) $(DEP) $(OBJ_B) $(DEP_B)
	

fclean: clean
	@rm -f $(NAME) $(NAME_B)
	make fclean -C libft

re: fclean all
