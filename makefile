NAME	= test.nope

SRCS	= so_long.c \

DEP		= ilibmlx.a \

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror

MLXF		= -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS) $(DEP)
	@echo "COMPILANDO PERRO!"
	@sleep 0.5
	@$(GCC) $(FLAGS) $(MLXF) $(SRCS) main.c -o $(NAME)
	@echo "DONE!"
clean:
	@echo "Bye Bye EXEC!"
	@rm -f $(NAME)
$(DEP):
	@make -s minilibx/makefile
