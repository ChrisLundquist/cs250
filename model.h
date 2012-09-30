#include <vector>
#include "math.h"
#include "faces.h"

class Model {
    public:
    Model();
    Model& set_scale(float, float, float);
    Model& set_rotation(float, float, float);
    Model& set_translation(float, float, float);
    float scale_x();
    float scale_y();
    float scale_z();

    private:
    Vector scale;
    Vector rotation;
    Vector translation;
    std::vector<Faces> faces;
};
