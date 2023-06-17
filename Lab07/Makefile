CC = gcc
CFLAGS = -Wall --std=c99 -g
MAIN_FILE = estimator.c
EXECUTABLE = estimator

$(EXECUTABLE): $(MAIN_FILE) 
	$(CC) $(CFLAGS) $(MAIN_FILE) -o $(EXECUTABLE)

clean:
	rm $(EXECUTABLE)
