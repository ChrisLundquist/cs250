#include <vector>
#include "math.h"
#include "face.h"

class Model {
    public:
    Model();
    Model& set_scale(float, float, float);
    Model& set_rotation(float, float, float);
    Model& set_translation(float, float, float);
    float scale_x();
    float scale_y();
    float scale_z();
    Matrix get_transform();
    Matrix get_scale_matrix();
    Matrix get_rotation_matrix();
    Matrix get_translation_matrix();

    private:
    Vector scale;
    Vector rotation;
    Vector translation;
    std::vector<Face> faces;
};
