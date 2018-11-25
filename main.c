#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>


/* global variables */


/* function declarations */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);



int main(int argc, char** argv)
{
    /* initialize glut */
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	/* initialize window */
	glutInitWindowSize(750,750);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Nuclear Balkan Zombies");

	/* callback functions */
	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	/* other */
	glClearColor(0.1, 0.1,0.1,0);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(1.25);	

	glutMainLoop();
	
	return 0;

}

static void on_keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(EXIT_SUCCESS);
			break;
	}
}


static void on_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            14, 20, 19,
            0, 0, 0,
            0, 1, 0
        );

    glPushMatrix();

    glColor3f(0.66, 0.66, 0.88);
    glTranslatef(5, 0-0.50, 5); /*pod*/
    glScalef(10, 1, 10);
    glutWireCube(1);
    
    glPopMatrix();

    glPushMatrix();

    glColor3f(0.66, 0.66, 0.66);
    glTranslatef(5, 1-0.50, 0.5); /*zid1*/
    glScalef(10, 1, 1);
    glutWireCube(1);
    
    glPopMatrix();

    glPushMatrix();

    glColor3f(0.66, 0.66, 0.66);
    glTranslatef(5, 1-0.50, 0.5+9); /*zid2*/
    glScalef(10, 1, 1);
    glutWireCube(1);
    
    glPopMatrix();


    glPushMatrix();

    glColor3f(0.66, 0.66, 0.66);
    glTranslatef(0+0.5, 1-0.5, 5); /*zid3*/
    glScalef(1, 1, 10);
    glutWireCube(1);
    
    glPopMatrix();


    glPushMatrix();

    glColor3f(0.66, 0.66, 0.66);
    glTranslatef(9+0.5, 1-0.5, 5); /*zid4*/
    glScalef(1, 1, 10);
    glutWireCube(1);
    
    glPopMatrix();

	glBegin(GL_LINES);

		glColor3f (0,0,1);
		glVertex3f(0,0,0);
		glVertex3f(50,0,0);

		glColor3f (0,1,0);
		glVertex3f(0,0,0);
		glVertex3f(0,50,0);

		glColor3f (1,0,0);
		glVertex3f(0,0,0);
		glVertex3f(0,0,50);

	glEnd();


	glutSwapBuffers();

}

static void on_reshape(int width, int height)
{
	
	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(float)width/height, 1, 100);
}

