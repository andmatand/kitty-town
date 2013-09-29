CC=g++ -Wall -ggdb
LIBS=`sdl2-config --libs`
TARGET=kitty-town
SRC_DIR=src/
OBJ=$(SRC_DIR)animation.o $(SRC_DIR)camera.o $(SRC_DIR)character.o \
    $(SRC_DIR)game.o $(SRC_DIR)globals.o $(SRC_DIR)kitty.o $(SRC_DIR)main.o \
    $(SRC_DIR)room.o $(SRC_DIR)scenery.o $(SRC_DIR)skin.o $(SRC_DIR)sprite.o

kitty-town: $(OBJ)
	$(CC) -o $(TARGET) $^ $(LIBS) 

%.o: $(SRC_DIR)%.cpp
	$(CC) -c $<

clean:
	rm $(SRC_DIR)*.o
