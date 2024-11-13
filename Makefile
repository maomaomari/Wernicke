CC = gcc
CFLAGS = -std=c2x

SRC = $(wildcard *.c)
OBJ = ${SRC:.c=.o}

all: wr

.c.o:
	$(CC) $(CFLAGS) -c $<

wr: $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ) wr
