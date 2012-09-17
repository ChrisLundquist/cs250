CXX=G++
STANDARD=-std=c++98
CFLAGS=-Wall -Wextra #-pedantic


test: all
	./test.exe

.cpp.o:
	$(CXX) -c $(STANDARD) $(CFLAGS) $< -o $@


all: Point4.o Vector4.o Matrix4.o Driver.o
	$(CXX) $(CFLAGS) *.o -o test.exe

clean:
	rm -rf *.exe *.o

diff: all
	./test.exe > test.txt
	diff ./test.txt ./sample_output.txt

