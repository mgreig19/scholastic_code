#
# PROGRAM:    Assign2
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DATE DUE:   3/2/2018
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
hw2.exe: hw2.o
	g++ $(CCFLAGS) -o hw2.exe hw2.o

# Rules to compile source code files to object code
hw2.o: hw2.cpp
	g++ $(CCFLAGS) -c hw2.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o hw2.exe



