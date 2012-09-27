CXX=G++
STANDARD=-std=c++98
CFLAGS=-Wall -Wextra #-pedantic


test: all
	./test.exe

.cpp.o:
	$(CXX) -c $(STANDARD) $(CFLAGS) $< -o $@


all: point.o vector.o matrix.o Driver.o
	$(CXX) $(CFLAGS) *.o -o test.exe

clean:
	rm -rf *.exe *.o

diff: all
	./test.exe > test.txt
	diff ./test.txt ./sample_output.txt

