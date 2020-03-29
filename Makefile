CC = gcc
AR = ar
OBJECTS_LIB = hello_Ariel.o
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: slib dlib main1_1.out main1_2.out main1_3.out 
slib: libhello_Ariel.a
dlib: libhello_Ariel.so
libhello_Ariel.a: $(OBJECTS_LIB)
	$(AR) -rcs libhello_Ariel.a $^ 
libhello_Ariel.so: $(OBJECTS_LIB)
	$(CC) -shared -o libhello_Ariel.so $^
main1_1.out: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) -o $@ $^	-I.
main1_2.out: main1_1.o libhello_Ariel.a
	$(CC) $(FLAGS) -o $@ $^ -I.
main1_3.out: main1_3.o libhello_Ariel.so
	$(CC) $(FLAGS) -o main1_3.out main1_3.o ./libhello_Ariel.so -I.
main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c -o $@ $< -I.
main1_3.o: main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c -o $@ $< -I.
hello_Ariel.o: hello_Ariel.c
	$(CC) $(FLAGS) -c -o $@ $< -I.
	
.PHONY: clean all
	
clean:
	rm -f *.o *.a *.so *.out
