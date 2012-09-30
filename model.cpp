#include "model.h"

Model::Model(){
    scale = Vector();
    rotation = Vector();
    translation = Vector();
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

float Model::scale_x() {
    return scale.x;
}

float Model::scale_y() {
    return scale.y;
}

float Model::scale_z() {
    return scale.z;
}

