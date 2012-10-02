#include "model.h"

Model::Model() {
    faces = std::vector<Face>();
    children = std::vector<Model>();
    transformation = Transformation();
    scale = Vector(1,1,1);
    rotation = Vector(0,0,0);
    translation = Vector(0,0,0);
}

Model::Model(std::vector<Face> faces) {
    this->faces = faces;
    children = std::vector<Model>();
    transformation = Transformation();
    scale = Vector(1,1,1);
    rotation = Vector(0,0,0);
    translation = Vector(0,0,0);
}

Model& Model::set_scale(float x, float y, float z) {
    scale.x = x;
    scale.y = y;
    scale.z = z;
    return *this;
}

Model& Model::set_rotation(float x, float y, float z) {
    rotation.x = x;
    rotation.y = y;
    rotation.z = z;
    return *this;
}

Model& Model::set_translation(float x, float y, float z) {
    translation.x = x;
    translation.y = y;
    translation.z = z;

    return *this;
}

void Model::render(FrameBuffer& buffer,Transformation& transform) {

    // Push the model transformation to make MVP
    transform.push(transformation.transform());

    Matrix MVP = transform.transform();

    for(unsigned i = 0; i < faces.size(); i++) {

    }

    for(unsigned i = 0; i < children.size(); i++)
        children[i].render(buffer, transform);

    transform.pop();
}

Model& Model::add_child(Model child) {
    children.push_back(child);

    return *this;
}

