.DEFAULT_GOAL := lab05.exe

lab05.o: lab05.cc
	g++ -c lab05.cc -Wall -std=c++11

lab05.exe: lab05.o
	g++ -o lab05.exe lab05.o -Wall -std=c++11

clean:
	rm *.o lab05.exe