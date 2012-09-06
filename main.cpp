#include <math.h>
#include <stdlib.h>
#include <iostream>

#include "frame_buffer.h"
#include "triangle.h"

#ifndef VK_ESCAPE
#define VK_ESCAPE 27
#endif

static int winID;
static FrameBuffer frame(WIDTH, HEIGHT);

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case VK_ESCAPE:
            glutDestroyWindow(winID);
            exit(0);
            break;
        default:
            std::cout << "Unhandled input: Key" << key << " X: " << x << "Y: " << y << std::endl;
    }
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    default:
    std::cout << "Unhandled input: Button" << button << "State: " << state << " X: " << x << "Y: " << y << std::endl;
    }
}

void mouseMove(int x, int y)
{
    std::cout << "Unhandled input: " << " X: " << x << "Y: " << y << std::endl;
}

void loop(void)
{
    glutPostRedisplay();
}

void render(void)
{
    frame.Clear(255, 255, 255);

    //Put your rendering code here
    Color black = Color();
    Color red = Color(255, 0, 0);
    Color green = Color(0, 255, 0);

    Point p1 = Point(100, 100);
    Point p2 = Point(100, 300);
    Point p3 = Point(400, 300);
    Point p4 = Point(400, 100);
    Point p5 = Point(420, 100);
    Point p6 = Point(460, 400);
    Point p7 = Point(560, 200);

    Vertex v1 = Vertex(p1, black);
    Vertex v2 = Vertex(p2, black);
    Vertex v3 = Vertex(p3, black);
    Vertex v4 = Vertex(p4, black);
    Vertex v5 = Vertex(p5, black);
    Vertex v6 = Vertex(p6, black);
    Vertex v7 = Vertex(p7, black);

    Line l1 = Line(v1, v2);
    Line l2 = Line(v2, v3);
    Line l3 = Line(v3, v4);
    Line l4 = Line(v4, v1);
    Line l5 = Line(v5, v6);
    Line l6 = Line(v5, v7);

    l1.render(frame);
    l2.render(frame);
    l3.render(frame);
    l4.render(frame);
    l5.render(frame);
    l6.render(frame);

    v1.color = red;
    v2.color = red;
    v3.color = red;
    v4.color = red;

    Triangle red_triangle = Triangle(v1, v2, v3);

    Line l7 = Line( Vertex( Point(462, 398), red), Vertex( Point(422, 98), red));
    Line l8 = Line( Vertex( Point(564, 198), red), Vertex( Point(424, 98), red));

    l7.render(frame);
    l8.render(frame);

    v1.color = green;
    v2.color = green;
    v3.color = green;
    v4.color = green;

    Triangle green_triangle(v1, v3, v4);

    red_triangle.render(frame);
    green_triangle.render(frame);

    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, frame.buffer);
    glutSwapBuffers();
}

void init(void)
{
    //Initialize everything here
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIDTH, HEIGHT);
    winID = glutCreateWindow("CS250");

    glClearColor(0, 0, 0, 1);

    glutKeyboardFunc(keyboard);
    glutDisplayFunc(render);
    glutIdleFunc(loop);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMove);

    init();

    glutMainLoop();

    return 0;
}
