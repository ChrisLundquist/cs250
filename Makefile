#VPATH= src:test
CFLAGS= -Wall -Wextra -pedantic -g
CXX=g++
TEST_LIBS=-lgtest -lgtest_main
LIBS= -lGLEW
FRAMEWORKS = -framework GLUT -framework OpenGL
OBJECT_FILES =  frame_buffer.o vertex.o color.o point.o line.o triangle.o
OBJECT_SPEC_FILES = spec/*.o
APP = Assignment
# spec/views/*.o src/controllers/*.o src/views/*.o


test: all model_specs
	rm -f ./tests
	$(CXX) -g $(OBJECT_FILES) $(OBJECT_SPEC_FILES) $(TEST_LIBS) $(FRAMEWORKS) $(LIBS) -o tests
	./tests

model_specs: spec/triangle_spec.o

#valgrind: test
#	valgrind --leak-check=yes ./tests

models: $(OBJECT_FILES)

all: models

game: all main.o
	$(CXX) $(FRAMEWORKS) $(LIBS) $(OBJECT_FILES) main.o -o $(APP)

run: game
	./$(APP)

clean:
	rm -rf main.o $(OBJECT_FILES) $(OBJECT_SPEC_FILES) $(APP) tests

.cpp.o:
	$(CXX) -c $(CFLAGS) $< -o $@

