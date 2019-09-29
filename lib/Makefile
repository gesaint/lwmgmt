SOURCE = $(wildcard *.c)
TARGETS = $(patsubst %.c, %, $(SOURCE))
 
CC = gcc
CFLAGS = -fPIC -shared
LIBS = -lpthread
 
all:$(TARGETS)
 
$(TARGETS):%:%.c
	$(CC) $< $(CFLAGS) $(LIBS) -o lib$@.so
 
.PHONY:clean all
clean:
	rm -rf *.o *.so
