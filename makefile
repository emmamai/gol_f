CC ?= gcc
CFLAGS ?= -O2 -lSDL2

gol_f: main.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-@rm gol_f
