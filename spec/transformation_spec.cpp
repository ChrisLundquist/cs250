#include <gtest/gtest.h>
#include "../transformation.h"


TEST(Transformation, Construct) {
    Transformation();
}

TEST(Transformation, translate) {
    Matrix translation = Transformation::translate(2,3,5);

    EXPECT_EQ(translation.m[3][0], 2);
    EXPECT_EQ(translation.m[3][1], 3);
    EXPECT_EQ(translation.m[3][2], 5);
    EXPECT_EQ(translation.m[3][3], 1);
}

TEST(Transformation, scale) {
    Matrix scale = Transformation::scale(2,3,5);

    EXPECT_EQ(scale.m[0][0], 2);
    EXPECT_EQ(scale.m[1][1], 3);
    EXPECT_EQ(scale.m[2][2], 5);
    EXPECT_EQ(scale.m[3][3], 1);
}

TEST(Transformation, RotateZero) {
    Matrix rotation = Transformation::rotate(0,0,0);
    Matrix identity = Matrix();
    identity.Identity();
    EXPECT_TRUE(identity == rotation);
}

TEST(Transformation, RotateZ90) {
    Matrix rotation = Transformation::rotate(0,0,90);

    EXPECT_NEAR(rotation.m[0][0], 0.0f, EPSILON);
    EXPECT_NEAR(rotation.m[1][0], -1, EPSILON);
    EXPECT_NEAR(rotation.m[0][1], 1, EPSILON);
    EXPECT_NEAR(rotation.m[1][1], 0.0f, EPSILON);
    EXPECT_NEAR(rotation.m[2][2], 1, EPSILON);
    EXPECT_NEAR(rotation.m[3][3], 1, EPSILON);
}

