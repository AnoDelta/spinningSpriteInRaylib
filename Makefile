# c compilers
CC_LINUX = gcc
CC_WINDOWS = x86_64-w64-mingw32-gcc

# compilation flags
FLAGS_LINUX = -lraylib
FLAGS_WINDOWS = -Iraylib/src -Lraylib/build/windows/raylib -lraylib -lopengl32 -lgdi32 -lwinmm

# files we will be using
TARGET = main.c

# output files
OUT_LINUX = ./build/linux/spin
OUT_WINDOWS = ./build/windows/spin.exe

all: linux windows 

linux:
	$(CC_LINUX) $(TARGET) $(FLAGS_LINUX) -o $(OUT_LINUX)

windows:
	$(CC_WINDOWS) $(TARGET) $(FLAGS_WINDOWS) -o $(OUT_WINDOWS)

clean:
	rm -rf $(OUT_LINUX)
	rm -rf $(OUT_WINDOWS)

#setup for windows
	#cd ./build/windows/
	#cmake ../../raylib -DCMAKE_TOOLCHAIN_FILE=../../mingw-toolchain.cmake -DCMAKE_BUILD_TYPE=Release
	#make
	#cd ../..

#setupLinux:
	#cd ./build/linux/
	#cmake ../.. -DCMAKE_BUILD_TYPE=Release
	#make
	
