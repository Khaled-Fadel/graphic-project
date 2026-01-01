#include <GL/glut.h>

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

void init(void) {
    glClearColor(0.19f, 0.19f, 0.19f, 1.2f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.2, 1.2, -1.2, 1.2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // House body
    glBegin(GL_QUADS);
    // Bottom-left
    glColor3f(0.9f, 0.3f, 0.2f);    // warm red-orange
    glVertex2f(-0.5f, -0.5f);

    // Bottom-right
    glColor3f(0.2f, 0.7f, 0.9f);    // cyan-blue
    glVertex2f(0.5f, -0.5f);

    // Top-right
    glColor3f(0.9f, 0.9f, 0.3f);    // yellow
    glVertex2f(0.5f, 0.3f);

    // Top-left
    glColor3f(0.4f, 0.9f, 0.4f);    // lime green
    glVertex2f(-0.5f, 0.3f);
    glEnd();

    // triangle
    glBegin(GL_TRIANGLES);
    // Left corner 
    glColor3f(1.0f, 0.4f, 0.8f);    // magenta + pink
    glVertex2f(-0.5f, 0.3f);

    // Right corner
    glColor3f(0.3f, 0.3f, 1.0f);    // deep blue
    glVertex2f(0.5f, 0.3f);

    // Roof peak
    glColor3f(1.0f, 1.0f, 1.0f);    // white
    glVertex2f(0.0f, 0.9f);
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Colored House - per-vertex coloring");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}