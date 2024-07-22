#include <GL/glut.h>
#include <stdlib.h>

float ex=0.0, ey=0.0, ez=5.0;
float cx=0.0, cy=0.0, cz=0.0;
float ux=0.0, uy=1.0, uz=0.0;

void drawCube(){
    glBegin(GL_QUADS);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(-1.0,1.0,1.0);

        glColor3f(0.0,1.0,0.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,1.0,-1.0);
        glVertex3f(1.0,1.0,-1.0);
        glVertex3f(1.0,-1.0,-1.0);

        glColor3f(0.0,0.0,1.0);
        glVertex3f(-1.0,1.0,-1.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(1.0,1.0,-1.0);

        glColor3f(1.0,1.0,0.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(-1.0,-1.0,1.0);

        glColor3f(1.0,0.0,1.0);
        glVertex3f(1.0,-1.0,-1.0);
        glVertex3f(1.0,1.0,-1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);

        glColor3f(0.0,1.0,1.0);
        glVertex3f(-1.0,-1.0,-1.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(-1.0,1.0,-1.0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(ex,ey,ez,cx,cy,cz,ux,uy,uz);
    drawCube();
    glutSwapBuffers();
}

void reshape(int w,int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.5,(GLfloat)w / (GLfloat)h, 1.0,20.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x,int y){
    switch(key){
        case 'x': ex += 0.1; break;
        case 'X': ex -= 0.1; break;
        case 'y': ey += 0.1; break;
        case 'Y': ey -= 0.1; break;
        case 'z': ez += 0.1; break;
        case 'Z': ez -= 0.1; break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Color cube with camera control");

    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return EXIT_SUCCESS;
}
