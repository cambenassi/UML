CC = g++
CFLAGS = -std=c++17 -c -g -Og -Wall -Werror -pedantic
OBJ =  KSGuitarSim.o CircularBuffer.o StringSound.o
DEPS =  KSGuitarSim.cpp CircularBuffer.cpp CircularBuffer.h StringSound.cpp StringSound.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
EXE = KSGuitarSim


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm $(OBJ) $(EXE)