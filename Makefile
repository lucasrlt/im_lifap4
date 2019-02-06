EXEC_NAME = bin/test
OBJ_FILES = bin/Image.o bin/Pixel.o
CC = g++
CFLAGS = -Wall -ggdb 
INCLUDES = -I/usr/include 
LIBS = -L/usr/lib -lm

all: bin/exemple

bin/exemple: bin/mainExemple.o $(OBJ_FILES)
	$(CC) -o bin/exemple bin/mainExemple.o $(OBJ_FILES) $(LIBS)

bin/test: bin/mainTest.o $(OBJ_FILES)
	$(CC) -o bin/test bin/mainTest.o $(OBJ_FILES) $(LIBS)

bin/mainExemple.o: src/mainExemple.cpp src/Image.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/mainExemple.cpp -o bin/mainExemple.o

bin/mainTest.o: src/mainTest.cpp src/Image.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/mainTest.cpp -o bin/mainTest.o

bin/Image.o: src/Image.cpp src/Image.h src/Pixel.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c src/Image.cpp -o bin/Image.o

bin/Pixel.o: src/Pixel.cpp src/Pixel.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/Pixel.cpp -o bin/Pixel.o

clean:
	rm bin/*.o

veryclean:
	rm bin/*

