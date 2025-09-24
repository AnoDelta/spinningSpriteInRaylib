# c compilers
CC_LINUX = gcc

# compilation flags
FLAGS_LINUX = -lraylib

# files we will be using
TARGET = main.c

# output files
OUT_LINUX = ./build/linux/spin

all: 
	linux

linux:
	$(CC_LINUX) $(TARGET) $(FLAGS_LINUX) -o $(OUT_LINUX)

clean:
	rm -rf $(OUT_LINUX)

#setup for windows
	#cd ./build/windows/
	#cmake ../../raylib -DCMAKE_TOOLCHAIN_FILE=../../mingw-toolchain.cmake -DCMAKE_BUILD_TYPE=Release
	#make
	#cd ../..

#setupLinux:
	#cd ./build/linux/
	#cmake ../.. -DCMAKE_BUILD_TYPE=Release
	#make
	
