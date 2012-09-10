struct Color {
    int r,g,b,a;
    Color();
    Color(int,int,int);
    Color(int,int,int,int);
    Color operator*(const float&) const;
    Color operator+(const Color&) const;
};
