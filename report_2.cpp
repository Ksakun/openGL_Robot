#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/glu.h>
#include <math.h>

#define PI 3.14

float theta = 60.0, s_theta = 30.0;
void Draw_Body() {
	glBegin(GL_POLYGON);
	glColor3f(0.0f,  0.0f,  0.3f);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
}
void Draw_Head() {
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.3f);
	for (int i = 0; i < 360; i++) {
		double angle = i * PI / 180;
		double x = 0.28 * cos(angle);
		double y = 0.28 * sin(angle);
		glVertex3f(x, y+0.80, 0.0);
	}
	glEnd();
}

void Draw_UpperArm() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glVertex3f(0.7, 0.3, 0.0);
	glVertex3f(0.7, 0.0, 0.0);
	glEnd();
}

void GoToShoulderCoordinates() {
	glTranslatef(0.5, 0.5, 0.0);
	glRotatef(-1*theta, 0.0, 0.0, 1.0);
	glScalef(1.0, 1.0, 1.0);
}

void Draw_L_UpperArm() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glVertex3f(-0.7, 0.3, 0.0);
	glVertex3f(-0.7, 0.0, 0.0);
	glEnd();
}

void GoToShoulderCoordinates_L() {
	glTranslatef(-0.5, 0.5, 0.0);
	glRotatef(theta, 0.0, 0.0, 1.0);
	glScalef(1.0, 1.0, 1.0);
}

void Draw_LowerArm() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.6f, 0.4f);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glVertex3f(0.7, 0.3, 0.0);
	glVertex3f(0.7, 0.0, 0.0);
	glEnd();
}

void GoToElbowCoordinates() {
	glTranslatef(0.7, 0.0, 0.0);
	glRotatef(s_theta, 0.0, 0.0, 1.0);
}

void Draw_L_LowerArm() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.6f, 0.4f);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glVertex3f(-0.7, 0.3, 0.0);
	glVertex3f(-0.7, 0.0, 0.0);
	glEnd();
}

void GoToElbowCoordinates_L() {
	glTranslatef(-0.7, 0.0, 0.0);
	glRotatef(-1*s_theta, 0.0, 0.0, 1.0);
}

void Draw_Hand() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.2f, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glVertex3f(0.3, 0.3, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glEnd();
}

void GoToWristCoordinates() {
	glTranslatef(0.71, 0.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
}

void Draw_L_Hand() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.2f, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glVertex3f(-0.3, 0.3, 0.0);
	glVertex3f(-0.3, 0.0, 0.0);
	glEnd();
}

void GoToWristCoordinates_L() {
	glTranslatef(-0.71, 0.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
}

void drawArm() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	Draw_Head();
	
	glPushMatrix();
	Draw_Body();
	
	glPushMatrix();
	GoToShoulderCoordinates();
	Draw_UpperArm();
	
	glPushMatrix();
	GoToElbowCoordinates();
	Draw_LowerArm();
	
	glPushMatrix();
	GoToWristCoordinates();
	Draw_Hand();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void drawArm_L() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	Draw_Head();
	
	glPushMatrix();
	Draw_Body();
	GoToShoulderCoordinates_L();
	Draw_L_UpperArm();
	
	glPushMatrix();
	GoToElbowCoordinates_L();
	Draw_L_LowerArm();
	
	glPushMatrix();
	GoToWristCoordinates_L();
	Draw_L_Hand();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

//keyboard ÇÔ¼ö
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q': //q
		theta = -60.0;
		break;
	case 'a': //a
		theta = 60.0;
		break;
	case 'p':// p
		s_theta = 90.0;
		break;
	case 'l':
		s_theta = 30.0;
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawArm();
	drawArm_L();
	glEnd();
	glFlush();
	}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("Computer Graphics #2");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}