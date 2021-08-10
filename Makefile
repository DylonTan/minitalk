CLIENT = client
CLIENT_BONUS = client_bonus

SERVER = server
SERVER_BONUS = server_bonus

CLIENT_SRCS = srcs/ft_client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_SRCS = srcs/ft_server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_BONUS_SRCS = srcs/ft_client_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

SERVER_BONUS_SRCS = srcs/ft_server_bonus.c
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCS = includes

LIBFT = libft
LIBFT_OPTIONS = -L$(LIBFT) -lft

OPTIONS = -I$(INCS)

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	cd $(LIBFT); make re; cd ..

%.o: %.c
	$(CC) -o $@ -c $^ $(FLAGS) $(OPTIONS)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) -o $@ $(CLIENT_OBJS) $(FLAGS) $(OPTIONS) $(LIBFT_OPTIONS)

$(SERVER): $(SERVER_OBJS)
	$(CC) -o $@ $(SERVER_OBJS) $(FLAGS) $(OPTIONS) $(LIBFT_OPTIONS)

bonus: $(LIBFT) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS)
	$(CC) -o $@ $(CLIENT_BONUS_OBJS) $(FLAGS) $(OPTIONS) $(LIBFT_OPTIONS)

$(SERVER_BONUS): $(SERVER_BONUS_OBJS)
	$(CC) -o $@ $(SERVER_BONUS_OBJS) $(FLAGS) $(OPTIONS) $(LIBFT_OPTIONS)

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)
	rm -f $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	rm -f $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re
