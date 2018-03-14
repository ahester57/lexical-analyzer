CC=gcc
CFLAGS=-Wall -g
#LDLIBS= -pthread
DEPS = $(wildcard *.h)
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