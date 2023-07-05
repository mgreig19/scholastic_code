#
# PROGRAM:    Assign8
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DATE DUE:   11/17/2016
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
Assign8: Assign8.o
	g++ $(CCFLAGS) -o Assign8 Assign8.o

# Rules to compile source code files to object code
Assign8.o: Assign8.cpp sorts.h
	g++ $(CCFLAGS) -c Assign8.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign8
