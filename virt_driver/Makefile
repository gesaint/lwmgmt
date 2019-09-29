CC:=gcc
CFLAGS+=-c
LIBS:=-lvirt -lread_data_from_file
LIB_DIR:=-L/root/lwmgmt/lib
TARGET:=virt_test
DEPEND:=virt_test.o
DEPEND+=virt_conn.o
DEPEND+=vm_list.o
DEPEND+=vm_info.o
DEPEND+=vm_new.o
DEPEND+=vm_delete.o
DEPEND+=vm_start.o
DEPEND+=vm_shutdown.o

$(TARGET):$(DEPEND)
	$(CC) $(LIB_DIR) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) $(LIB_DIR) -o $@ $^ $(LIBS)

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)
