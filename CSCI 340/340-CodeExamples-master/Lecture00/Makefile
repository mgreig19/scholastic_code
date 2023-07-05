all: lecture00a.exe lecture00b.exe lecture00c.exe lecture00d.exe lecture00e.exe lecture00f.exe lecture00g.exe lecture00h.exe

CPP=g++
CFLAGS=-Wall -std=c++11

%.o:%.cc
	$(CPP) $(CFLAGS) -o $@ -c $<

%.exe:%.o
	$(CPP) $(CFLAGS) $< -o $@

clean:
	rm lecture00*.exe