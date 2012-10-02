#VPATH= src:test
CFLAGS= -Wall -Wextra
CXX=g++
TEST_LIBS=-lgtest -lgtest_main
LIBS= -lGLEW
FRAMEWORKS = -framework GLUT -framework OpenGL
OBJECT_FILES =  frame_buffer.o vertex.o line.o triangle.o math/point.o math/vector.o math/matrix.o camera.o parser.o model.o transformation.o
OBJECT_SPEC_FILES = spec/*.o spec/math/*.o
APP = Assignment
STANDARD = -std=c++98
# spec/views/*.o src/controllers/*.o src/views/*.o


test: all model_specs
	rm -f ./tests
	$(CXX) -g $(STANDARD) $(OBJECT_FILES) $(OBJECT_SPEC_FILES) $(TEST_LIBS) $(FRAMEWORKS) $(LIBS) -o tests
	./tests

model_specs: spec/triangle_spec.o \
	spec/math/point_spec.o \
	spec/parser_spec.o \
	spec/model_spec.o \
	spec/transformation_spec.o \
	spec/camera_spec.o



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
	$(CXX) -c $(STANDARD) $(CFLAGS) $< -o $@

