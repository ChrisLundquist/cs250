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
    std::vector<Vertex> get_vertexes();
    private:
    void parse_data(const char *fileName);
    void parse_camera(std::istream&);
    void parse_vertexes(std::istream&);
    void parse_faces(std::istream&);
    void parse_face_colors(std::istream&);
    void parse_texture_coordinates(std::istream&);
    std::string data;
    Camera camera;
    std::vector<Face> faces;
    std::vector<Vertex> vertexes;
    std::vector<Vector> texture_coordinates;
};
