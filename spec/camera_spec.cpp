#include <gtest/gtest.h>
#include "../camera.h"

Camera get_camera() {
    Camera c = Camera();
    c.set_left(-16.0);
    c.set_right(16.0);
    c.set_top(12.0);
    c.set_bottom(-12.0);
    c.set_focal(24);
    c.set_near(36);
    c.set_far(500);

    return c;
}


TEST(Camera, ProjectionMatrix) {
    Camera camera = get_camera();
    Matrix projection = camera.get_projection();

    EXPECT_EQ(projection.m[0][0], (2 * camera.get_near()) / (camera.get_right() - camera.get_left()));
    EXPECT_EQ(projection.m[1][1], (2 * camera.get_near()) / (camera.get_top() - camera.get_bottom()));
    EXPECT_EQ(projection.m[2][2], -(camera.get_far() + camera.get_near()) / (camera.get_far() - camera.get_near()));
    EXPECT_EQ(projection.m[3][2], -1);
}
