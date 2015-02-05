CC=g++
CFLAGS=-c	-Wall
LDFLAGS=-LC:\SFML\lib	-lsfml-graphics	-lsfml-window	-lsfml-system
IFLAGS=-IC:\SFML\include	-I.
#sources contains all source .cpp files separated by blank space (use tabs)
SOURCES=main.cpp	TileMap.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=myGame

all:	$(SOURCES)	$(EXECUTABLE)

$(EXECUTABLE):	$(OBJECTS)
	$(CC)	$(OBJECTS)	-o	$@	$(LDFLAGS)	

.cpp.o:
	$(CC)	$(CFLAGS)	$<	$(IFLAGS)