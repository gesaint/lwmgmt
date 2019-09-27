SOURCE = $(wildcard *.c)
TARGETS = $(patsubst %.c, %, $(SOURCE))
 
CC = gcc
CFLAGS = -fPIC -shared
 
all:$(TARGETS)
 
$(TARGETS):%:%.c
	$(CC) $< $(CFLAGS) -o lib$@.so
 
.PHONY:clean all
clean:
	rm -rf *.o *.so
