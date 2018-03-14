CC=gcc
CFLAGS=-Wall -g
#LDLIBS= -pthread
# or perhaps SOURCES= $(wildcard *.c)
DEPS = scanner.h testscanner.h token.h alphabet.h find.h metafile.h
# change to patsub
OBJECTS = main.o scanner.o testscanner.o token.o alphabet.o find.o metafile.o

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