CC:=gcc
INC_DIR:=../lib
CFLAGS=-c -Wall -I$(INC_DIR)
TARGET:=example
DEPEND:=$(INC_DIR)/write_data_to_file.o
DEPEND+=logs.o
DEPEND+=example.o

$(TARGET):$(DEPEND)
	$(CC) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)
	rm -rf $(INC_DIR)/write_data_to_file.o
