CC = gcc
CFLAGS = -Wall -Wextra -g3

TARGET = jogo_da_forca
SRCS = main.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
