#include <gtest/gtest.h>
#include "../model.h"

TEST(Model, Construct) {
    Model m = Model();
}

TEST(Model, SetScale) {
    Model m = Model();
    m.set_scale(2,3,5);

    EXPECT_EQ(m.scale_x(), 2);
    EXPECT_EQ(m.scale_y(), 3);
    EXPECT_EQ(m.scale_z(), 5);
}
