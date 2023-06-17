CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = lab04.o
EXECUTABLE = lab4_output
CFILE = lab04.c

hello: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c $(lab04.c) -o $(OBJECTS)
clean:
	rm $(EXECUTABLE) $(OBJECTS)
