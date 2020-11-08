CC=gcc
CFLAGS=-Wall -Wextra -std=c99

TARGETS=ninel vectsecv codeinvim nomogram

build: $(TARGETS)

ninel: ninel.c
	$(CC) $(CFLAGS) ninel.c -o ninel

vectsecv: vectsecv.c
	$(CC) $(CFLAGS) vectsecv.c -o vectsecv

codeinvim: codeinvim.c
	$(CC) $(CFLAGS) codeinvim.c -o codeinvim

nomogram: nomogram.c
	$(CC) $(CFLAGS) nomogram.c -o nomogram

clean:
	rm -f $(TARGETS)