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

    float get_top();
    float get_bottom();
    float get_left();
    float get_right();
    float get_near();
    float get_far();
    float get_focal();
    private:
    float top;
    float bottom;
    float left;
    float right;

    float focal;
    float near;
    float far;
};
