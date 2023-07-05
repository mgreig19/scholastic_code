assign11.exe: assign11.o
	g++ -Wall -std=c++11 -o assign11.exe assign11.o `mysql_config --cflags --libs`
assign11.o: assign11.cc
	g++ -Wall -std=c++11 -c assign11.cc `mysql_config --cflags --libs`

clean:
	-rm assigg11.o assign11.exe

