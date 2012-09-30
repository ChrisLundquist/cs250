#include <gtest/gtest.h>
#include "../parser.h"

TEST(Parser,Load) {
    Parser p("spec/test_input.txt");
    Camera camera = p.get_camera();

    // TODO move to Camera test
    EXPECT_EQ(camera.get_top(),12);
    EXPECT_EQ(camera.get_bottom(),-12);
    EXPECT_EQ(camera.get_left(),-16);
    EXPECT_EQ(camera.get_right(),16);
    EXPECT_EQ(camera.get_far(),500);
    EXPECT_EQ(camera.get_near(),36);
    EXPECT_EQ(camera.get_focal(),24);

    // TODO move to Vertex0
    std::vector<Vertex> vertexes = p.get_vertexes();

    Vertex first = vertexes[0];
    EXPECT_EQ(first.x(), -0.5f);
    EXPECT_EQ(first.y(), -0.5f);
    EXPECT_EQ(first.z(), 0.5f);
    EXPECT_EQ(first.w(), 1.0f);

    // TODO move to VertexN
    Vertex last = vertexes.back();
    EXPECT_EQ(last.x(), -0.5f);
    EXPECT_EQ(last.y(), 0.5f);
    EXPECT_EQ(last.z(), -0.5f);
    EXPECT_EQ(last.w(), 1.0f);
}

TEST(Parser, Camera) {
    /*
     * left = -16.0
     * right = 16.0
     * top = 12.0
     * bottom = -12.0
     * focal = 24
     * near = 36
     * far = 500
     */
}


TEST(Parser, Vertex0) {
    /*
     * vertexes
     * {
     *     count = 8
     *     -0.5,-0.5,+0.5,1.0
     *     +0.5,-0.5,+0.5,1.0
     *     +0.5,+0.5,+0.5,1.0
     *     -0.5,+0.5,+0.5,1.0
     *     -0.5,-0.5,-0.5,1.0
     *     +0.5,-0.5,-0.5,1.0
     *     +0.5,+0.5,-0.5,1.0
     *     -0.5,+0.5,-0.5,1.0
     * }
     */
}

TEST(Parser, VertexN) {
}

TEST(Parser, face_color) {
    //EXPECT_FALSE(true);
}
