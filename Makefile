CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_LIB = hello_Ariel.o
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: slib dlib main1_1 main1_2 main1_3 
slib: libhello_Ariel.a
dlib: libhello_Ariel.so
libhello_Ariel.a: $(OBJECTS_LIB)
	$(AR) -rcs libhello_Ariel.a $^ 
libhello_Ariel.so: $(OBJECTS_LIB)
	$(CC) -shared -o libhello_Ariel.so $^
main1_1: main.o hello_Ariel.o
	$(CC) $(FLAGS) -o $@ $^	-I.
main1_2: main.o libhello_Ariel.a
	$(CC) $(FLAGS) -o main1_2 $^ -I.
main1_3: main.o libhello_Ariel.so
	$(CC) $(FLAGS) -o main1_3 $(OBJECTS_MAIN) ./libhello_Ariel.so -I.
main.o: main.c hello_Ariel.h
	$(CC) $(FLAGS) -c -o $@ $< -I.
hello_Areil.o: hello_Ariel.c
	$(CC) $(FLAGS) -c -o $@ $< -I.
	
.PHONY: clean all
	
clean:
	rm -f *.o *.a *.so main1_1 main1_2 main1_3
