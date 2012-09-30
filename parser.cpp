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

void Parser::parse_camera(std::ifstream& data) {
    std::cout << "Parsing camera" << std::endl;
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
