LIB_NAME = libmycalc.a

SRC_FILES = add.c sub.c mul.c div.c
OBJ_FILES = $(SRC_FILES:.c=.o)

HEADER_FILES = add.h sub.h mul.h div.h

CC = gcc

all: mycalc

mycalc: mycalc.o $(LIB_NAME)
	$(CC) mycalc.o -L. -lmycalc -o mycalc

$(LIB_NAME): $(OBJ_FILES)
	ar rcs $(LIB_NAME) $(OBJ_FILES)

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

mycalc.o: mycalc.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c mycalc.c -o mycalc.o

clean:
	rm -f *.o $(LIB_NAME) mycalc

.PHONY: all clean
