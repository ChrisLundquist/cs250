#include <math.h>
#include <stdlib.h>
#include <iostream>

#include "frame_buffer.h"
#include "parser.h"
#include "model.h"

#define INPUT_FILE "input.txt"

#ifndef VK_ESCAPE
#define VK_ESCAPE 27
#endif

static int winID;
static FrameBuffer frame(WIDTH, HEIGHT);
static Model tank;
static Camera camera;

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
    Transformation VP = Transformation();
    VP.push(camera.get_projection());
    frame.Clear(255, 255, 255);

    tank.render(frame, VP);

    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, frame.buffer);
    glutSwapBuffers();
}

void init(void)
{
    Parser p(INPUT_FILE);
    camera = p.get_camera();

//    - Body dimensions or scale values: Sx=30,Sy=25, Sz=80
//        - Body Initial Position: Anywhere along the Negative z-axis
//        - Body rotation axis: Y-axis
//        - Body initial angle: 0 degrees
//        - Turret dimensions or scale values: Sx=25, Sy=15, Sz=25
//        - Turret Initial position: (0, 20, 0)
//        - Turret rotation axis: Y-axis
//        - Turret initial angle: 0 degrees
//        - Gun dimensions or scale values: Sx=5, Sy=5, Sz=40
//        - Gun Initial position: (0, 0, 12.5)
//        - Gun rotation axis: X-axis
//        - Gun initial angle: 0 degrees
//        - Wheel dimensions or scale values: Sx=5, Sy=20, Sz=20
//        - Wheel 1 Initial position: (17.5, -12.5, -25)
//        - Wheel 2 Initial position: (-17.5, -12.5, -25)
//        - Wheel 3 Initial position: (17.5, -12.5, 25)
//        - Wheel 4 Initial position: (-17.5, -12.5, 25)
//        - Wheel rotation axis: X-axis
//        - Wheels initial angle: 0 degrees


    tank = Model();

    Model body = Model(p.get_faces());
    body.set_scale(30,25,80);

    Model turret = Model(p.get_faces());
    turret.set_scale(25,15,25).set_translation(0,20,0);

    Model gun = Model(p.get_faces());
    gun.set_scale(5,5,50).set_translation(0,0,12.5);

    Model wheel1 = Model(p.get_faces());
    wheel1.set_scale(5,20,20).set_translation(17.5, -12.5, -25);

    Model wheel2 = Model(p.get_faces());
    wheel2.set_scale(5,20,20).set_translation(-17.5, -12.5, -25);

    Model wheel3 = Model(p.get_faces());
    wheel3.set_scale(5,20,20).set_translation(17.5, -12.5, 25);

    Model wheel4 = Model(p.get_faces());
    wheel4.set_scale(5,20,20).set_translation(-17.5, -12.5, 25);

    turret.add_child(gun);
    body.add_child(turret);

    body.add_child(wheel1);
    body.add_child(wheel2);
    body.add_child(wheel3);
    body.add_child(wheel4);

    tank.add_child(body);
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

    render();

    glutMainLoop();

    return 0;
}
