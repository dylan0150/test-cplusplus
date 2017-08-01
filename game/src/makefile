OBJS = main.cpp

OUT = ../bin/
CC = g++
COMPILER_FLAGS = -w -I/usr/include/SDL2 -D_REENTRANT
LINKER_FLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image

OBJ_NAME = main

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUT)$(OBJ_NAME)
