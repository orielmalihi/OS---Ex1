CC = gcc
AR = ar
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: task1 task2 task3 task4

task1: main2_1.o 
	$(CC) $(FLAGS) -o $@ $<	-I.
task2: main2_2.o 
	$(CC) $(FLAGS) -o $@ $< -I.
task3: main2_3.o 
	$(CC) $(FLAGS) -o $@ $< -I.
task4: main2_4.o 
	$(CC) $(FLAGS) -o $@ $< -I.
main2_1.o: main2_1.c 
	$(CC) $(FLAGS) -c -o $@ $< -I.
main2_2.o: main2_2.c 
	$(CC) $(FLAGS) -c -o $@ $< -I.
main2_3.o: main2_3.c 
	$(CC) $(FLAGS) -c -o $@ $< -I.
main2_4.o: main2_4.c 
	$(CC) $(FLAGS) -c -o $@ $< -I.
	
.PHONY: clean all
	
clean:
	rm -f *.o task*
