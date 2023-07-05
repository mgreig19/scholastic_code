# makefile w/ two targets

# Compiler variables
CCFLAGS = -ansi -Wall

# Top rule

all: hello1.exe hello2.exe

# Rules to combine object code files to create executable files
hello1.exe: hello1.o
	g++ $(CCFLAGS) -o hello1.exe hello1.o

hello2.exe: hello2.o
	g++ $(CCFLAGS) -o hello2.exe hello2.o

# Rule to compile source code files to object code
hello1.o: hello1.cpp
	g++ $(CCFLAGS) -c hello1.cpp

hello2.o: hello2.cpp
	g++ $(CCFLAGS) -c hello2.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o hello1.exe hello2.exe
