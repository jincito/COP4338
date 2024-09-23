CC=gcc
CFLAGS=-I. -g -w
DEPS= pattern_finder.h
OBJ = pattern_finder.o check_palindrome.o check_singleton.o check_arithmetic.o check_bipartite.o check_tripartite.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
pattern_finder: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
