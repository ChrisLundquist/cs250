#include <iostream>

#include "parser.h"

#define DEBUG 0

#define CAMERA "camera"
#define VERTEXES "vertexes"
#define FACES "faces"
#define FACECOLOR "facecolor"
#define TEXTURE_COORDINATES "texturecoordinates"

// DOS line endings were breaking things

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
    std::string line = std::string();
    float left = 0;
    float right = 0;
    float top = 0;
    float bottom = 0;
    float focal = 0;
    float near = 0;
    float far = 0;

    if(DEBUG)
        std::cout << "Parsing camera" << std::endl;

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
/* Looks like:
 *{
 *count = 8
 *-0.5,-0.5,+0.5,1.0
 *+0.5,-0.5,+0.5,1.0
 *+0.5,+0.5,+0.5,1.0
 *-0.5,+0.5,+0.5,1.0
 *-0.5,-0.5,-0.5,1.0
 *+0.5,-0.5,-0.5,1.0
 *+0.5,+0.5,-0.5,1.0
 *-0.5,+0.5,-0.5,1.0
 *}
 */
void Parser::parse_vertexes(std::ifstream& data) {
    int count = 0;
    float x = 0;
    float y = 0;
    float z = 0;
    float w = 0;

    std::string line = std::string();

    if(DEBUG)
        std::cout << "Parsing vertexes" << std::endl;

    getline(data, line);
    line = chomp(line);

    if( block_open(line) == false) {
        std::cerr << "Error: Did not receive block open" << std::endl;
        return;
    }

    getline(data, line);
    line = chomp(line);

    sscanf(line.c_str(), "%*s %*s %d", &count);
    if(DEBUG)
        std::cout << count << std::endl;
    vertexes.reserve(count);

    getline(data, line);
    while(! block_close(line)) {
        Vertex v = Vertex();
        if(DEBUG)
            std::cout << line << std::endl;
        sscanf(line.c_str(),"%f,%f,%f,%f",&x, &y, &z, &w);
        if(DEBUG)
            std::cout << "X: " << x << "Y: " << y << "Z: " << z << "W: " << w << std::endl;
        v.point = Point(x,y,z,w);
        vertexes.push_back(v);
        getline(data, line);
    }
}

/* Looks Like:
 *{
 * count = 12
 * 0,1,2
 * 0,2,3
 * 1,5,6
 * 1,6,2
 * 5,4,7
 * 5,7,6
 * 4,0,3
 * 4,3,7
 * 3,2,6
 * 3,6,7
 * 4,5,1
 * 4,1,0
 * }
 */
void Parser::parse_faces(std::ifstream& data) {
    int id_a, id_b, id_c;

    std::string line = std::string();
    if(DEBUG)
        std::cout << "Parsing faces" << std::endl;
    getline(data, line);
    line = chomp(line);

    if( block_open(line) == false) {
        std::cerr << "Error: Did not receive block open" << std::endl;
        return;
    }

    while(! block_close(line)) {
        getline(data, line);
        sscanf(line.c_str(), "%d,%d,%d", &id_a, &id_b, &id_c);
        Face face = Face(vertexes[id_a], vertexes[id_b], vertexes[id_c]);
        faces.push_back(face);
    }
}

/* Looks Like:
 * {
 * 0,0,0
 * 0,0,0
 * 0,0,255
 * 0,0,255
 * 255,0,0
 * 255,0,0
 * 0,255,0
 * 0,255,0
 * 100,100,100
 * 100,100,100
 * 255,255,0
 * 255,255,0
 * }
 */
void Parser::parse_face_colors(std::ifstream& data) {
    int i = 0;
    int r,g,b;
    std::string line = std::string();

    if(DEBUG)
        std::cout << "Parsing face colors" << std::endl;

    getline(data, line);
    line = chomp(line);

    if( block_open(line) == false) {
        std::cerr << "Error: Did not receive block open" << std::endl;
        return;
    }

    getline(data, line);
    while(! block_close(line)) {
        if(DEBUG)
            std::cout << line << std::endl;
        sscanf(line.c_str(), "%d,%d,%d", &r, &g, &b);

        if(DEBUG)
            std::cout << "R: " << r << " G: " << g << " B: " << b << std::endl;

        Vector color = Vector(r, g, b);
        vertexes[i].color = color;
        i++;
        getline(data, line);
    }
}

// TODO
void Parser::parse_texture_coordinates(std::ifstream& data) {
    std::string line = std::string();
    if(DEBUG)
        std::cout << "Parsing texture coordinates" << std::endl;
    getline(data, line);
    line = chomp(line);

    if( block_open(line) == false) {
        std::cerr << "Error: Did not receive block open" << std::endl;
        return;
    }

    while(! block_close(line)) {
        getline(data, line);
    }
}
