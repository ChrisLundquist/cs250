#include <vector>
#include "math.h"

class Transformation {
    public:
        static Matrix scale(float, float, float);
        static Matrix rotate(float, float, float);
        static Matrix translate(float, float, float);

        Transformation();

        // Compound a transformation
        Transformation& push(Matrix);

        // Remove the most recent transformation
        Transformation& pop();

        // Get the effective transform
        Matrix transform();
    private:
        static Matrix rotate_x(float);
        static Matrix rotate_y(float);
        static Matrix rotate_z(float);
        std::vector<Matrix> stack;
        Matrix current;
};
