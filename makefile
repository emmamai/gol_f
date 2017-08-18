CC ?= gcc
CFLAGS ?= -g -Og -lSDL2

gol_f: main.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-@rm gol_f
