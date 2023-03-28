CC=gcc
CFLAGS=-I.
DEPS = include/imobiliare.h
OBJ = src/main.o

src/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: main
	main.exe