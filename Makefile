CC=gcc
CFLAGS=-Wall -g -I ./lex/
#LDLIBS= -pthread
DEPS = $(wildcard ./lex/*.h)
SOURCES= $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, ${SOURCES})

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
