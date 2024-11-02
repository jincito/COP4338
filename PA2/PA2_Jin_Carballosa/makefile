CC=gcc
CFLAGS=-I. -w -lm
DEPS= railcipher.h
OBJ = main.o encrypt.o decrypt.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
railcipher: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY: clean