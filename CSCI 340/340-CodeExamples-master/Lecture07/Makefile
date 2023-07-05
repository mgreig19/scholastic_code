all: map.exe set.exe

CPP=g++
CFLAGS=-Wall -std=c++11

%.o:%.cc
	$(CPP) $(CFLAGS) -o $@ -c $<

%.exe:%.o
	$(CPP) $(CFLAGS) $< -o $@

clean:
	rm map.exe set.exe