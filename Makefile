# -*- MakeFile -*-
INCLUDE_DIR = include

CPP = g++
CFLAGS = -Wall -fexceptions -g -std=c++11
CLINK = -mwindows
RM = del

all: bin\keywatcher.exe

# Linking all object file to create executable
bin\keywatcher.exe: obj\main.o obj\keywatcher.o
	$(CPP) $(CLINK) $^ -o $@

# Compilation for main.cpp
obj\main.o: src\main.cpp
	$(CPP) $(CFLAGS) $(CLINK) -c $^ -o $@

# Compilation for keywatcher.cpp
obj\keywatcher.o: src\keywatcher.cpp
	$(CPP) $(CFLAGS) $(CLINK) -c $^ -o $@

clean:
	$(RM) obj\*.o
	$(RM) bin\keywatcher.exe
