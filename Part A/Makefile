CC = gcc
AR = ar
OBJECTS_LIB = hello_Ariel.o
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: slib dlib task1 main1_2.out main1_3.out 
slib: libhello.a
dlib: libhello.so
libhello.a: $(OBJECTS_LIB)
	$(AR) -rcs libhello.a $^ 
libhello.so: $(OBJECTS_LIB)
	$(CC) -shared -o libhello.so $^
main1_1.out: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) -o $@ $^	-I.
main1_2.out: main1_1.o libhello.a
	$(CC) $(FLAGS) -o $@ $^ -I.
main1_3.out: main1_3.o libhello.so
	$(CC) $(FLAGS)  -o main1_3.out main1_3.o ./libhello.so -I. -ldl
main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c -o $@ $< -I.
main1_3.o: main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c -o $@ $< -I.
hello_Ariel.o: hello_Ariel.c
	$(CC) $(FLAGS) -c -o $@ $< -I.
	
.PHONY: clean all
	
clean:
	rm -f *.o *.a *.so *.out
