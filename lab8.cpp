#include <GL/glut.h>
#include <stdio.h>
#include <cmath>

GLfloat angle = 0.0;
bool day = true;

void init() {
    glClearColor(0.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light0_position[] = {10.0,10.0,10.0,1.0};
    GLfloat light0_diffuse[] = {1.0,1.0,1.0,1.0};
    GLfloat light0_specular[] = {1.0,1.0,1.0,1.0};

    glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light0_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light0_specular);

    glEnable(GL_LIGHT1);
    GLfloat light1_position[] = {-10.0,-10.0,10.0,1.0};
    GLfloat light1_diffuse[] = {0.6,0.6,0.6,1.0};
    GLfloat light1_specular[] = {0.2,0.2,0.2,1.0};

    glLightfv(GL_LIGHT1,GL_POSITION,light1_position);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,light1_diffuse);
    glLightfv(GL_LIGHT1,GL_SPECULAR,light1_specular);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(5.0,-5.0,5.0,      // camera position (eye)
              0.0,0.0,0.0,
              0.0,0.0,1.0);     // up vector (upright)
    glRotatef(angle,0.0,0.0,1.0);

    glColor3f(0.2,0.8,0.2);
    glBegin(GL_QUADS);
        glVertex3f(-10.0,-10.0,0.0);
        glVertex3f(-10.0,10.0,0.0);
        glVertex3f(10.0,10.0,0.0);
        glVertex3f(10.0,-10.0,0.0);
    glEnd();

    glColor3f(0.8,0.6,0.4);
    glTranslatef(2.0,2.0,1.0);
    glutSolidCube(1.0);

    if(day){
        glColor3f(1.0,1.0,0.0);
    }
    else {
        glColor3f(0.8,0.8,1.0);
    }
    glTranslatef(-5.0,-5.0,1.0);
    glutSolidSphere(0.5,20,20);
    glutSwapBuffers();
}

void update(int value) {
    angle += 0.5;
    if(angle>360.0){
        angle -= 360.0;
    }

    if(angle < 180.0){
        day = true;
        glDisable(GL_LIGHT1);
        glEnable(GL_LIGHT0);
    }
    else {
        day = false;
        glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
    }
    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}

void reshape(int w,int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,(GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow("Day and Night Scenes");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, update,0);
    glutMainLoop();

    return 0;
}
