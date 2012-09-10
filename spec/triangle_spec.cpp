#include <gtest/gtest.h>
#include "../triangle.h"

static Color red() {
    return Color(255, 0, 0);
}

static Vertex vertex_a() {
    return Vertex(Point(100, 0), red());
}

static Vertex vertex_b() {
    return Vertex(Point(400, 100), red());
}

static Vertex vertex_c() {
    return Vertex(Point(200, 300), red());
}

static Triangle test_triangle() {
    Vertex a = vertex_a();
    Vertex b = vertex_b();
    Vertex c = vertex_c();
    return Triangle(a, b, c);
}

TEST(Triangle, Alpha) {
    Triangle triangle = test_triangle();
    Vertex a = vertex_a();
    Vertex b = vertex_b();
    Vertex c = vertex_c();

    EXPECT_EQ(triangle.alpha(a.point), 1.0);
    EXPECT_EQ(triangle.alpha(b.point), 0);
    EXPECT_EQ(triangle.alpha(c.point), 0);
}

TEST(Triangle, Beta) {
    Triangle triangle = test_triangle();
    Vertex a = vertex_a();
    Vertex b = vertex_b();
    Vertex c = vertex_c();

    EXPECT_EQ(triangle.beta(a.point), 0);
    EXPECT_EQ(triangle.beta(b.point), 1.0);
    EXPECT_EQ(triangle.beta(c.point), 0);
}

TEST(Triangle, Gamma) {
    Triangle triangle = test_triangle();
    Vertex a = vertex_a();
    Vertex b = vertex_b();
    Vertex c = vertex_c();

    EXPECT_EQ(triangle.gamma(a.point), 0);
    EXPECT_EQ(triangle.gamma(b.point), 0);
    EXPECT_EQ(triangle.gamma(c.point), 1.0);
}

TEST(Triangle, DoesInclude) {
    Triangle triangle = test_triangle();

    Point good1 = Point(200, 200);
    Point good2 = Point(200, 100);
    Point good3 = Point(100, 0);

    EXPECT_TRUE(triangle.includes(good1));
    EXPECT_TRUE(triangle.includes(good2));
    EXPECT_TRUE(triangle.includes(good3));
}

TEST(Triangle, DoesNotInclude) {
    Triangle triangle = test_triangle();

    Point bad1 = Point(200, 0);
    Point bad2 = Point(100, 100);
    Point bad3 = Point(400, 400);
    Point bad4 =  Point(300, 200);


    EXPECT_FALSE(triangle.includes(bad1));
    EXPECT_FALSE(triangle.includes(bad2));
    EXPECT_FALSE(triangle.includes(bad3));
    EXPECT_FALSE(triangle.includes(bad4));
}
