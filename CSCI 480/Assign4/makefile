#
# PROGRAM:    Assign4
# PROGRAMMER: Mason Greig
# LOGON ID:   z1768935
# DATE DUE:   5/03/2018
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11 -lpthread

# Rule to link object code files to create executable file
hw4.exe: hw4.o Street.o
	g++ $(CCFLAGS) -o hw4.exe hw4.o Street.o

# Rules to compile source code files to object code
hw4.o: hw4.cpp Street.h
	g++ $(CCFLAGS) -c hw4.cpp

Street.o: Street.cpp Street.h
	g++ $(CCFLAGS) -c Street.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o hw4.exe
