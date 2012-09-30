#include <gtest/gtest.h>
#include "../model.h"

TEST(Model, Construct) {
    Model m = Model();
    EXPECT_EQ(m.scale_x(), 1);
    EXPECT_EQ(m.scale_y(), 1);
    EXPECT_EQ(m.scale_z(), 1);
}

TEST(Model, SetScale) {
    Model m = Model();
    m.set_scale(2,3,5);

    EXPECT_EQ(m.scale_x(), 2);
    EXPECT_EQ(m.scale_y(), 3);
    EXPECT_EQ(m.scale_z(), 5);
}

TEST(Model, GetScaleMatrix) {
    Model m = Model();
    m.set_scale(2,3,5);

    Matrix scale = m.get_scale_matrix();

    EXPECT_EQ(scale.m[0][0], 2);
    EXPECT_EQ(scale.m[1][1], 3);
    EXPECT_EQ(scale.m[2][2], 5);
    EXPECT_EQ(scale.m[3][3], 1);
}

TEST(Model, GetTranslationMatrix) {
    Model m = Model();
    m.set_translation(-2,3,5);

    Matrix translation = m.get_translation_matrix();

    EXPECT_EQ(translation.m[0][3], -2);
    EXPECT_EQ(translation.m[1][3], 3);
    EXPECT_EQ(translation.m[2][3], 5);
    EXPECT_EQ(translation.m[3][3], 1);
}

TEST(Model, GetRotationMatrix) {
    Model m = Model();
    m.set_rotation(30,45,60);

    Matrix rotation = m.get_rotation_matrix();

    EXPECT_EQ(rotation.m[0][0], 1);
    EXPECT_EQ(rotation.m[1][1], 1);
    EXPECT_EQ(rotation.m[2][2], 1);
    EXPECT_EQ(rotation.m[3][3], 1);
}
