CC = gcc
CFLAGS =-g -Wall --std=c99
OBJECTS = main.o my_string.o generic_vector.o avl.o
TEST = test_def.o unit_test.o my_string.o

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c my_string.h status.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
generic_vector.o: generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o
avl.o: avl.c
	$(CC) $(CFLAGS) -c avl.c -o avl.o
unit_test: $(TEST)
	$(CC) $(CFLAGS) -o unit_test $(TEST)
test_def.o: test_def.c unit_test.h
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o
unit_test.o: unit_test.c unit_test.h
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
my_string.o: my_string.c my_string.h status.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

clean_string_driver:
	rm string_driver $(OBJECTS)
clean_unit_test:
	rm unit_test $(TEST)
