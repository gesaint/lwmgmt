CC:=gcc
CFLAGS+=-c
LIBS:=-lvirt
TARGET:=virt_test
DEPEND:=virt_test.o
DEPEND+=virt_conn.o

$(TARGET):$(DEPEND)
	$(CC) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)
