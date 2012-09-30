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

    Vertex first = vertexes.front();
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

    // TODO move to Face0
    std::vector<Face> faces = p.get_faces();

    Face first_face = faces.front();
    EXPECT_EQ(first_face.a.x(), vertexes[0].x());
    EXPECT_EQ(first_face.a.y(), vertexes[0].y());
    EXPECT_EQ(first_face.a.z(), vertexes[0].z());

    EXPECT_EQ(first_face.b.x(), vertexes[1].x());
    EXPECT_EQ(first_face.b.y(), vertexes[1].y());
    EXPECT_EQ(first_face.b.z(), vertexes[1].z());

    EXPECT_EQ(first_face.c.x(), vertexes[2].x());
    EXPECT_EQ(first_face.c.y(), vertexes[2].y());
    EXPECT_EQ(first_face.c.z(), vertexes[2].z());

    // TODO move to FaceN
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
