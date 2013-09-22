CC=g++ -Wall -ggdb
LIBS=`sdl2-config --libs`
TARGET=kitty-town
SRC=src/main.cpp

default:
	$(CC) $(SRC) $(LIBS) -o $(TARGET) 
