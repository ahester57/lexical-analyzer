CC=gcc
CFLAGS=-Wall -g
#LDLIBS= -pthread
# or perhaps SOURCES= $(wildcard *.c)
DEPS = scanner.h parsertest.h readfile.h
# change to patsubt
OBJECTS = main.o scanner.o parsertest.o readfile.o 

.PHONY: all clean

default: all

all: scanner

%.o: %.c $(DEPS)

scanner: $(OBJECTS)
	gcc -o $@ $^ $(CFLAGS)

clean:
	$(RM) $(OBJECTS)

destroy:
	$(RM) $(OBJECTS) scanner