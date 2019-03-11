CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =
DEBUG = 0
EXECUTABLES = bogo bubble insertion

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

all: $(EXECUTABLES)

shared.o:
	$(CC) $(CFLAGS) -c src/shared.c

$(EXECUTABLES): %: src/%.c src/shared.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f src/*.o
	rm -f $(EXECUTABLES)
