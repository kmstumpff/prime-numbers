all: 1

1:
	g++ -O2 -g -std=c++11 -o prime prime.cc
clean:
	rm -fr *.o *~
