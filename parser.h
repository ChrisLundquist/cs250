#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "camera.h"
#include "vertex.h"
#include "face.h"

class Parser {
    public:
    Parser(char* filename);
    Camera get_camera();
    std::vector<Face> get_faces();
    private:
    void parse_data(const char *fileName);
    void parse_camera(std::ifstream&);
    void parse_vertexes(std::ifstream&);
    void parse_faces(std::ifstream&);
    void parse_face_colors(std::ifstream&);
    void parse_texture_coordinates(std::ifstream&);
    std::string data;
    Camera camera;
    std::vector<Face> faces;
    std::vector<Vertex> vertexes;
    std::vector<Vector> texture_coordinates;
};
