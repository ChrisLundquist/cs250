#VPATH= src:test
CFLAGS= -Wall -Wextra -pedantic
CXX=g++
TEST_LIBS=-lgtest -lgtest_main
LIBS= -lGLEW
FRAMEWORKS = -framework GLUT -framework OpenGL
OBJECT_FILES =  *.o
OBJECT_SPEC_FILES = spec/models/*.o spec/controllers/*.o
APP = Assignment
# spec/views/*.o src/controllers/*.o src/views/*.o


#test: all model_specs controller_specs view_specs
#	rm -f ./tests
#	$(CXX) -g $(OBJECT_FILES) $(OBJECT_SPEC_FILES) $(TEST_LIBS) $(FRAMEWORKS) $(LIBS) -o tests
#	./tests

#valgrind: test
#	valgrind --leak-check=yes ./tests

models: frame_buffer.o main.o vertex.o color.o point.o

all: models

game: all main.o
	$(CXX) $(FRAMEWORKS) $(LIBS) $(OBJECT_FILES) -o $(APP)

run: game
	./$(APP)

clean:
	rm -rf $(OBJECT_FILES) $(OBJECT_SPEC_FILES) $(APP)

.cpp.o:
	$(CXX) -g -c $(CFLAGS) $< -o $@

