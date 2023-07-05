#
# PROGRAM:    Assign3
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DATE DUE:   3/24/2018
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
hw3.exe: hw3.o
	g++ $(CCFLAGS) -o hw3.exe hw3.o

# Rules to compile source code files to object code
hw3.o: hw3.cpp
	g++ $(CCFLAGS) -c hw3.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o hw3.exe



