CC:=gcc
CFLAGS+=-c
LIBS:=-lvirt
TARGET:=virt_test
DEPEND:=virt_test.o
DEPEND+=virt_conn.o
DEPEND+=vm_list.o
DEPEND+=vm_info.o

$(TARGET):$(DEPEND)
	$(CC) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)
