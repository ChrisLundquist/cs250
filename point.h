#include <iostream>
struct Point {
    Point();
    Point(int,int);
    int x,y,z,t;
    Point operator-(const Point&);
    Point operator+(const Point&);
    Point& operator+=(const Point&);
    bool operator==(const Point&);
    float length();
    Point normalize();
    friend std::ostream& operator<<(std::ostream&, const Point& );
};
