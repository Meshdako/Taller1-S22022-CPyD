CXX= g++
CXXFLAGS= -g3 -Wall
MKDIR= mkdir -p

LIBS= -lm

directorios:
	$(MKDIR) build dist

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

funciones.o: directorios funciones.cpp funciones.h
	$(CXX) $(CXXFLAGS) -c funciones.cpp -o build/funciones.o

all: clean main.o funciones.o
	$(CXX) $(CXXFLAGS) -o dist/taller1g1 build/main.o build/funciones.o $(LIBS)

clean:
	rm -fr *.o a.out core taller1g1 dist build

.DEFAULT_GOAL:= all