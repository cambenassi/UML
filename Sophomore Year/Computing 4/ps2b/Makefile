CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ = NBody.o universe.o celestial.o
DEPS = NBody.cpp celestial.h celestial.cpp universe.h universe.cpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
EXE = NBody

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
