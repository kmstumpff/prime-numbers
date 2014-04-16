all: 2 clean

1:
	g++ -O2 -g -std=c++11 -o prime prime.cc
2:
	g++ -O2 -g -std=c++11 -o prime-2 prime-2.cc
clean:
	rm -fr *.o *~