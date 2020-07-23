LIBRARIES = -lSDL2 -lSDL2_image
CPP_FILES = ImageLoaderEntry.cpp
OBJ = ile.o
main:
	g++ -std=c++17 -Wall -o $(OBJ) $(CPP_FILES) $(LIBRARIES)
