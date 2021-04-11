CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ =  TFractal.o Triangle.o
DEPS =  TFractal.cpp Triangle.cpp Triangle.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
EXE = TFractal


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm $(OBJ) $(EXE)