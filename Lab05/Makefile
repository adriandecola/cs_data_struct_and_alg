CC = gcc
CFLAGS = -Wall --std=c99 -g
MAIN_OBJECT = link_list_main.o
EXECUTABLE = link_list_output
LINKED_CFILE = link_list.c
MAIN_CFILE = link_list_main.c
LINKED_OBJECT = link_list.o 

$(EXECUTABLE): $(MAIN_OBJECT) $(LINKED_OBJECT)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(MAIN_OBJECT) $(LINKED_OBJECT)
$(LINKED_OBJECT): $(LINKED_CFILE)
	$(CC) $(CFLAGS) -c $(LINKED_CFILE) -o $(LINKED_OBJECT)
$(MAIN_OBJECT): $(MAIN_CFILE) 
	$(CC) $(CFLAGS) -c $(MAIN_CFILE) -o $(MAIN_OBJECT)

clean:
	rm $(EXECUTABLE) $(MAIN_OBJECT) $(LINKED_OBJECT)
