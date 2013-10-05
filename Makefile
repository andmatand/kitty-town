CXX=g++
CXXFLAGS=-std=c++11 -Wall -ggdb
LIBS=`sdl2-config --libs`
TARGET=kitty-town
SRC_DIR=src/
OBJ=$(SRC_DIR)animationplayer.o $(SRC_DIR)assetloader.o $(SRC_DIR)camera.o \
    $(SRC_DIR)character.o $(SRC_DIR)characterskin.o $(SRC_DIR)collisionmask.o \
    $(SRC_DIR)dynamicskin.o $(SRC_DIR)fixture.o $(SRC_DIR)game.o \
    $(SRC_DIR)globals.o $(SRC_DIR)kitty.o $(SRC_DIR)main.o \
    $(SRC_DIR)physicsbody.o $(SRC_DIR)room.o $(SRC_DIR)skin.o \
    $(SRC_DIR)staticskin.o $(SRC_DIR)sprite.o

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^ $(LIBS) 

clean:
	rm -f $(SRC_DIR)*.o
	rm -f $(TARGET)
