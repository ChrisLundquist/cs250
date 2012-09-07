#include <iostream>
struct Point {
    Point();
    Point(int,int);
    int x,y,z,t;
    Point operator-(Point&);
    Point operator+(Point&);
    Point& operator+=(Point&);
    float length();
    Point normalize();
    friend std::ostream& operator<<(std::ostream&, const Point& );
};
