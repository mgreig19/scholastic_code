#
# PROGRAM:    Assign4
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DATE DUE:   10/13/2016
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
Assign4: Assign4.o Vector3.o
	g++ $(CCFLAGS) -o Assign4 Assign4.o Vector3.o

# Rules to compile source code files to object code
Assign4.o: Assign4.cpp Vector3.h 
	g++ $(CCFLAGS) -c Assign4.cpp

Vector3.o: Vector3.cpp Vector3.h
	g++ $(CCFLAGS) -c Vector3.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign4


