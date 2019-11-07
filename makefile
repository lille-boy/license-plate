CC = gcc
CFLAGS = -I.
DEPS = license.h
OBJ = main.o license.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

license: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS)
