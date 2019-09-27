CC:=gcc
LIBS=-lwrite_data_to_file
LIB_DIR:=-L/root/lwmgmt/lib
CFLAGS=-c -Wall
TARGET:=example
DEPEND+=log.o
DEPEND+=example.o

$(TARGET):$(DEPEND)
	$(CC) $(LIB_DIR) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) $(LIB_DIR) -o $@ $^ $(LIBS)

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)
