#
# PROGRAM:    Assign3
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
Assign3: Assign3.o Verifier.o
	g++ $(CCFLAGS) -o Assign3 Assign3.o Verifier.o
   
# Rules to compile source code files to object code
Assign3.o: Assign3.cpp Verifier.h
	g++ $(CCFLAGS) -c Assign3.cpp
      
Verifier.o: Verifier.cpp Verifier.h
	g++ $(CCFLAGS) -c Verifier.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign3
