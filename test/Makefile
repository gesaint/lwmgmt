CC:=gcc
INC_DIR:=../log
CFLAGS=-c -Wall -I$(INC_DIR)
TARGET:=test
DEPEND:=../log/logs.o
DEPEND+=../lib/write_data_to_file.o
DEPEND+=test.o
DEPEND+=log_test.o

$(TARGET):$(DEPEND)
	$(CC) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY:clean
clean:
	rm -rf $(DEPEND) $(TARGET)
