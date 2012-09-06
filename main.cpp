#include "frame_buffer.h"
#include "math.h"
#include "stdlib.h"
#include <iostream>

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
