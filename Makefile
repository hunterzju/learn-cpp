CC=g++
CFLAGS=-g

all: stack inheritstack templatestack

stack: stack.cc stack.h
	$(CC) $(CFLAGS) -o $@ $^

inheritstack: list.cc list.h inheritstack.cc inheritstack.h
	$(CC) $(CFLAGS) -o $@ $^

templatestack: templatestack.cc templatestack.h
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -rf stack inheritstack templatestack