CC = g++
CFLAGS = -std=c++11 -c -g -Og -Werror -pedantic
OBJ = main.o edClass.o
DEPS = main.cpp edClass.cpp edClass.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
EXE = ED


all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)