#
# PROGRAM:    Assign5
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DATE DUE:   10/25/2016
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
Assign5: Assign5.o VectorN.o
	g++ $(CCFLAGS) -o Assign5 Assign5.o VectorN.o

# Rules to compile source code files to object code
Assign5.o: Assign5.cpp VectorN.h
	g++ $(CCFLAGS) -c Assign5.cpp

VectorN.o: VectorN.cpp VectorN.h
	g++ $(CCFLAGS) -c VectorN.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign5

