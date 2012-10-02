#include <vector>
#include "transformation.h"
#include "face.h"
#include "graphics.h"

class Model {
    public:
    Model();
    Model(std::vector<Face>);
    Transformation& get_transform();
    Model& set_scale(float,float,float);
    Model& set_rotation(float,float,float);
    Model& set_translation(float,float,float);
    void render(FrameBuffer&, Transformation&);
    Model& add_child(Model);

    private:
    Transformation transformation;
    Vector scale, rotation, translation;
    std::vector<Face> faces;
    std::vector<Model> children;
};
