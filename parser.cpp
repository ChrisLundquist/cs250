#include <iostream>

#include "parser.h"

#define CAMERA "camera"
#define VERTEXES "vertexes"
#define FACES "faces"
#define FACECOLOR "facecolor"
#define TEXTURE_COORDINATES "texturecoordinates"

// DOS line endings were breaking things
inline static std::string chomp(std::string string) {
    return string.substr(0,string.find("\r"));
}

void Parser::parse_data(const char *fileName) {
    std::string line = std::string();

    std::ifstream file(fileName);
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            line = chomp(line);
            if( line.compare(CAMERA) == 0) {
                parse_camera(file);
            } else if ( line.compare(VERTEXES) == 0) {
                parse_vertexes(file);
            } else if ( line.compare(FACES) == 0) {
                parse_faces(file);
            } else if ( line.compare(FACECOLOR) == 0) {
                parse_face_colors(file);
            } else if ( line.compare(TEXTURE_COORDINATES) == 0) {
                parse_texture_coordinates(file);
            }
        }
        file.close();
    }
}

static bool block_open(std::string& line) {
    line = chomp(line);
    return line.compare("{") == 0;
}

static bool block_close(std::string& line) {
    line = chomp(line);
    return line.compare("}") == 0;
}


/* Looks like:
 *{
 * left = -16.0
 * right = 16.0
 * top = 12.0
 * bottom = -12.0
 * focal = 24
 * near = 36
 * far = 500
 * }
*/
void Parser::parse_camera(std::ifstream& data) {
    float left = 0;
    float right = 0;
    float top = 0;
    float bottom = 0;
    float focal = 0;
    float near = 0;
    float far = 0;


    std::cout << "Parsing camera" << std::endl;
    std::string line = std::string();

    getline(data, line);
    line = chomp(line);

    if( block_open(line) == false) {
        std::cerr << "Error: Did not receive block open" << std::endl;
        return;
    }

    //TODO make me more robust so things can be in any order
    getline(data, line);
    sscanf(line.c_str(), "%*s %*s %f", &left);
    getline(data, line);
    sscanf(line.c_str(), "%*s %*s %f", &right);
    getline(data, line);
    sscanf(line.c_str(), "%*s %*s %f", &top);
    getline(data, line);
    sscanf(line.c_str(), "%*s %*s %f", &bottom);
    getline(data, line);
    sscanf(line.c_str(), "%*s %*s %f", &focal);
    getline(data, line);
    sscanf(line.c_str(), "%*s %*s %f", &near);
    getline(data, line);
    sscanf(line.c_str(), "%*s %*s %f", &far);

    while(! block_close(line)) {
        getline(data, line);
    }

    camera.set_top(top);
    camera.set_bottom(bottom);
    camera.set_left(left);
    camera.set_right(right);
    camera.set_near(near);
    camera.set_far(far);
    camera.set_focal(focal);
}

void Parser::parse_vertexes(std::ifstream& data) {
    std::cout << "Parsing vertexes" << std::endl;
}

void Parser::parse_faces(std::ifstream& data) {
    std::cout << "Parsing faces" << std::endl;
}

void Parser::parse_face_colors(std::ifstream& data) {
    std::cout << "Parsing face colors" << std::endl;
}

void Parser::parse_texture_coordinates(std::ifstream& data) {
    std::cout << "Parsing texture coordinates" << std::endl;
}

Parser::Parser(char* filename) {
    camera = Camera();
    faces = std::vector<Face>();
    vertexes = std::vector<Vertex>();
    texture_coordinates = std::vector<Vector>();
    parse_data(filename);
}

Camera Parser::get_camera() {
    return camera;
}

std::vector<Face> Parser::get_faces() {
    return faces;
}
