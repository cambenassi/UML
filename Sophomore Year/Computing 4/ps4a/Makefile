CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ =  test.o CircularBuffer.o
DEPS =  test.cpp CircularBuffer.cpp CircularBuffer.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
EXE = test


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm $(OBJ) $(EXE)