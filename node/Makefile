CC:=gcc
CFLAGS+=-c
TARGET:=init
DEPEND:=init.o

$(TARGET):$(DEPEND)
	$(CC) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)
