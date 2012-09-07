#include <gtest/gtest.h>
#include "../triangle.h"

static Triangle test_triangle() {
    Color red = Color(255, 0 ,0);
    Vertex a = Vertex(Point(100, 0), red);
    Vertex b = Vertex(Point(400, 100), red);
    Vertex c = Vertex(Point(200, 300), red);
    return Triangle(a, b, c);
}

TEST(Triangle, DoesInclude) {
    Triangle triangle = test_triangle();

    Point good1 = Point(200, 200);
    Point good2 = Point(200, 100);
    Point good3 = Point(300, 200);
    Point good4 = Point(100, 0);

    EXPECT_TRUE(triangle.includes(good1));
    EXPECT_TRUE(triangle.includes(good2));
    EXPECT_TRUE(triangle.includes(good3));
    //EXPECT_TRUE(triangle.includes(good4));
}

TEST(Triangle, DoesNotInclude) {
    Triangle triangle = test_triangle();

    Point bad1 = Point(200, 0);
    Point bad2 = Point(100, 100);
    Point bad3 = Point(400, 400);


    EXPECT_FALSE(triangle.includes(bad1));
    EXPECT_FALSE(triangle.includes(bad2));
    EXPECT_FALSE(triangle.includes(bad3));
}
