CC = gcc
CFLAGS = -Wall --std=c99 -g
MAIN_OBJECT = student_vector_main_ood.o
EXECUTABLE = student_vector_main_output
LINKED_CFILE = studentvector_ood.c
MAIN_CFILE = student_vector_main_ood.c
LINKED_OBJECT = studentvector_ood.o 

$(EXECUTABLE): $(MAIN_OBJECT) $(LINKED_OBJECT)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(MAIN_OBJECT) $(LINKED_OBJECT)
$(LINKED_OBJECT): $(LINKED_CFILE)
	$(CC) $(CFLAGS) -c $(LINKED_CFILE) -o $(LINKED_OBJECT)
$(MAIN_OBJECT): $(MAIN_CFILE) 
	$(CC) $(CFLAGS) -c $(MAIN_CFILE) -o $(MAIN_OBJECT)

clean:
	rm $(EXECUTABLE) $(MAIN_OBJECT) $(LINKED_OBJECT)
