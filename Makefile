SERVER = server
CLIENTE = client

SRC_SERVER = utils.c server.c
SRC_CLIENTE = utils.c client.c

GCC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIE
LDFLAGS = -pie

OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENTE = $(SRC_CLIENTE:.c=.o)

all: $(SERVER) $(CLIENTE)

$(SERVER): $(OBJS_SERVER)
	$(GCC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(LDFLAGS)

$(CLIENTE): $(OBJS_CLIENTE)
	$(GCC) $(CFLAGS) -o $(CLIENTE) $(OBJS_CLIENTE) $(LDFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(SERVER) $(CLIENTE)

re: fclean all
