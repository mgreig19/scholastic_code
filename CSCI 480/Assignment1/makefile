#
# PROGRAM:    Assign1
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DATE DUE:   1/20/2018
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
hw1.exe: hw1.o Processor.o
	g++ $(CCFLAGS) -o hw1.exe hw1.o Processor.o

# Rules to compile source code files to object code
hw1.o: hw1.cpp Processor.h
	g++ $(CCFLAGS) -c hw1.cpp

Processor.o: Processor.cpp Processor.h
	g++ $(CCFLAGS) -c Processor.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o hw1.exe



