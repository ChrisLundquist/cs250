#include <gtest/gtest.h>
#include "../../math.h"

TEST(Point,DefaultConstructor) {
    Point point = Point();

    EXPECT_EQ(point.x, 0);
    EXPECT_EQ(point.y, 0);
    EXPECT_EQ(point.z, 0);
    EXPECT_EQ(point.w, 1);
}

TEST(Point,NonDefaultConstructor) {
    Point point = Point(2,3,5,7);

    EXPECT_EQ(point.x, 2);
    EXPECT_EQ(point.y, 3);
    EXPECT_EQ(point.z, 5);
    EXPECT_EQ(point.w, 7);
}

TEST(Point, CopyConstructor) {
    Point point = Point(1,2,3);
    Point copy = Point(point);

    EXPECT_EQ(copy.x, point.x);
    EXPECT_EQ(copy.y, point.y);
    EXPECT_EQ(copy.z, point.z);
    EXPECT_EQ(copy.w, point.w);
}

TEST(Point, Assignment) {
    Point point = Point(1,2,3);
    Point copy = point;

    EXPECT_EQ(copy.x, point.x);
    EXPECT_EQ(copy.y, point.y);
    EXPECT_EQ(copy.z, point.z);
    EXPECT_EQ(copy.w, point.w);
}

TEST(Point, EquallityTrue ) {
    Point point = Point(1,2,3);
    Point copy = point;

    EXPECT_TRUE(copy == point);
}

TEST(Point, EquallityFalse ) {
    Point point = Point(1,2,3);
    Point copy = point;
    copy.x = 13;

    EXPECT_FALSE(copy == point);
}

TEST(Point, EquallityEpsilonTrue ) {
    Point point = Point(1,2,3);
    Point copy = point;
    copy.x += EPSILON - 0.1f * EPSILON;

    EXPECT_TRUE(copy == point);
}

TEST(Point, EquallityEpsilonFalse ) {
    Point point = Point(1,2,3);
    Point copy = point;
    copy.x += EPSILON + 0.1f * EPSILON;

    EXPECT_FALSE(copy == point);
}

TEST(Point, Minus) {
    Point point = Point(1,2,3);

    // TODO
    //EXPECT_EQ( point - point, Vector());
}
