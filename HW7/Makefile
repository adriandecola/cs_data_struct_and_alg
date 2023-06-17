CC = gcc
CFLAGS = -Wall --std=c99 -g
MAIN_OBJECT = priority_queue_main.o
EXECUTABLE = priority_queue_output
LINKED_CFILE = priority_queue.c
MAIN_CFILE = priority_queue_main.c
LINKED_OBJECT = priority_queue.o 

$(EXECUTABLE): $(MAIN_OBJECT) $(LINKED_OBJECT)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(MAIN_OBJECT) $(LINKED_OBJECT)
$(LINKED_OBJECT): $(LINKED_CFILE)
	$(CC) $(CFLAGS) -c $(LINKED_CFILE) -o $(LINKED_OBJECT)
$(MAIN_OBJECT): $(MAIN_CFILE) 
	$(CC) $(CFLAGS) -c $(MAIN_CFILE) -o $(MAIN_OBJECT)

clean:
	rm $(EXECUTABLE) $(MAIN_OBJECT) $(LINKED_OBJECT)
