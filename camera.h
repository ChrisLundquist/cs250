class Camera {
    public:
    Camera();
    Camera& set_top(float);
    Camera& set_bottom(float);
    Camera& set_left(float);
    Camera& set_right(float);
    Camera& set_near(float);
    Camera& set_far(float);
    Camera& set_focal(float);
    private:
    float top;
    float bottom;
    float left;
    float right;

    float focal;
    float near;
    float far;
};
