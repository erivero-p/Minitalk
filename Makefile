NAME_C = client
NAME_S = server

NAME_CBONUS = client_bonus
NAME_SBONUS = server_bonus

FLAGS = -Wall -Wextra -Werror

FILE_S = server.c
OBJ_S = $(FILE_S:.c=.o)
FILE_C = client.c
OBJ_C = $(FILE_C:.c=.o)

FILE_CBONUS = client_bonus.c
OBJ_CBONUS = $(FILE_CBONUS:.c=.o)
FILE_SBONUS = server_bonus.c
OBJ_SBONUS = $(FILE_SBONUS:.c=.o)

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

bonus:  all client_bonus server_bonus
client_bonus: libft $(OBJ_CBONUS)
	@ cc $(FLAGS) -o $(NAME_CBONUS) $(OBJ_CBONUS) libft/*.o

server_bonus: libft $(OBJ_SBONUS)
	@ cc $(FLAGS) -o $(NAME_SBONUS) $(OBJ_SBONUS) libft/*.o

all: client server
server: libft $(OBJ_S)
	@ cc $(FLAGS) -o $(NAME_S) $(OBJ_S) libft/*.o

client: libft $(OBJ_C)
	@ cc $(FLAGS) -o $(NAME_C) $(OBJ_C) libft/*.o

libft:
	@ make -C libft/

clean:
	@ rm -f $(OBJ_S) $(OBJ_C) $(OBJ_SBONUS) $(OBJ_CBONUS)
	@ make -C libft/ clean

fclean: clean
	@ rm -f $(NAME_S) $(NAME_C) $(NAME_SBONUS) $(NAME_CBONUS)
	@ make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean bonus re client_bonus server_bonus client server