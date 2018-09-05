CC:=gcc
CFLAGS:=-I/usr/include/libxml2/
CFLAGS+=-c
LIBS:=-lxml2
TARGET:=data_cache_test
DEPEND:=xml_to_cache.o
DEPEND+=cache_to_xml.o
DEPEND+=data_cache.o
DEPEND+=data_cache_test.o
DEPEND+=cache_to_json.o

$(TARGET):$(DEPEND)
	$(CC) -o $@ $^ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)
