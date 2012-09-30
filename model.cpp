#include "model.h"

Model::Model(){
    scale = Vector(1,1,1);
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

Matrix Model::get_scale_matrix() {
    Matrix scale = Matrix();
    scale.m[0][0] = scale_x();
    scale.m[1][1] = scale_y();
    scale.m[2][2] = scale_z();
    scale.m[3][3] = 1;

    return scale;
}

Matrix Model::get_rotation_matrix() {
    Matrix rotation = Matrix();

    //rotation.m;

    return rotation;
}

Matrix Model::get_translation_matrix() {
    Matrix translation = Matrix();

    translation.m[0][3] = this->translation.x;
    translation.m[1][3] = this->translation.y;
    translation.m[2][3] = this->translation.z;
    translation.m[3][3] = 1;

    return translation;
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

