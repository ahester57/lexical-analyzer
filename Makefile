CC=gcc
CFLAGS=-Wall -g
#LDLIBS= -pthread
SOURCES= $(wildcard *.c)
DEPS = $(wildcard *.h)
# change to patsub
#OBJECTS = main.o scanner.o testscanner.o token.o alphabet.o find.o metafile.o filter.o
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