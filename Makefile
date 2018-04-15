# Masukkan semua file cpp Anda
OBJS = main.cpp src/oop.cpp src/Aquarium.cpp src/Coin.cpp src/Fish.cpp src/FishFood.cpp src/Guppy.cpp src/Piranha.cpp src/Snail.cpp src/Position.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = oopquarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
