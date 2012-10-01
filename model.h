#include <vector>
#include "transformation.h"
#include "face.h"

class Model {
    public:
    Model();
    Transformation& get_transform();

    private:
    Transformation transformation;
    std::vector<Face> faces;
};
