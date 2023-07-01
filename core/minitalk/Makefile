CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: client server

client: client/client.c
    $(CC) $(CFLAGS) -o $@ $^

server: server/server.c
    $(CC) $(CFLAGS) -o $@ $^

clean:
    rm -f client server
