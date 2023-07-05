#May-Myo Khine
#Zid : z1785954
#Course and section number: CSCI340-2

#I certify that this is my own work and where appropriate an extension
#of the starter code provided for the assignment.

.DEFAULT_GOAL := assignment9.exe

assignment9.cc:

assignment9.o: assignment9.cc
	g++ -c assignment9.cc -Wall -std=c++11 -I.

assignment9.exe: assignment9.o
	g++ -o assignment9.exe assignment9.o -Wall -std=c++11 -I.

clean:
	rm *.o assignment9.exe
