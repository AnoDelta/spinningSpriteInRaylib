# c compilers
CC_LINUX = gcc

# compilation flags
FLAGS_LINUX = -lraylib

# files we will be using
TARGET = main.c

# output files
OUT_LINUX = spin

all: 
	clean linux

linux:
	$(CC_LINUX) $(TARGET) $(FLAGS_LINUX) -o $(OUT_LINUX)

clean:
	rm -rf $(OUT_LINUX)
