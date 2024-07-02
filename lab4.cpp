#include<stdio.h>
#include <GL/glut.h>
#include <stdlib.h>

float tx=0.0, ty=0.0, tz=0.0;
float angleX=0.0, angleY=0.0, angleZ=0.0;
float scale=1.0;

void initOpengl() {
    glClearColor(0.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST);
}

void displayPoly() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(tx,ty,tz);
    glRotatef(angleX,1.0,0.0,0.0);
    glRotatef(angleY,0.0,1.0,0.0);
    glRotatef(angleZ,0.0,0.0,1.0);
    glScalef(scale,scale,scale);

    glBegin(GL_POLYGON); // Front face
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glEnd();

    glBegin(GL_POLYGON); // Back face
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON); // Left face
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();

    glBegin(GL_POLYGON); // Right face
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glEnd();

    glBegin(GL_POLYGON); // Top face
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON); // Bottom face
    glColor3f(0.0, 1.0, 1.0); // Cyan
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();

    glutSwapBuffers();

}


void keyboard(unsigned char key,int x,int y){
    switch(key){
        case 'w': ty += 0.1 ; break;
        case 's': ty -= 0.1 ; break;
        case 'a': tx -= 0.1 ; break;
        case 'd': tx += 0.1 ; break;
        case 'q': tz += 0.1 ; break;
        case 'e': tz -= 0.1 ; break;
        case 'i': angleX += 5.0; break;
        case 'k': angleX -= 5.0; break;
        case 'j': angleY += 5.0; break;
        case 'l': angleY -= 5.0; break;
        case 'u': angleZ += 5.0; break;
        case 'o': angleZ -= 5.0; break;
        case 'z': scale += 0.1; break;
        case 'x': scale -= 0.1; break;
        case 27: exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow("3D Geometric Transformations");

    glutDisplayFunc(displayPoly);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return EXIT_SUCCESS;
}
