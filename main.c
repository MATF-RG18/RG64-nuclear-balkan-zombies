#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define TIMER_ID_P1 (0)
#define TIMER_ID_P2 (6)
#define TIMER_INTERVAL (10)
#define DEFAULT (5)
#define UP (1)
#define DOWN (2)
#define LEFT (3)
#define RIGHT (4)

/* global variables */
float p1updown, p1leftright = 0;
float p2updown, p2leftright = 0;
int arrow=DEFAULT;
/* function declarations */
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void ontimer(int value);


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


        case 's':
        case 'S':case GLUT_KEY_UP:
            arrow=DOWN;
            glutTimerFunc(TIMER_INTERVAL,ontimer,TIMER_ID_P1);

            break;

        case 'w':
        case 'W':
            arrow=UP;
            glutTimerFunc(TIMER_INTERVAL,ontimer,TIMER_ID_P1);

            break;

        case 'a':
        case 'A':
            arrow=LEFT;
            glutTimerFunc(TIMER_INTERVAL,ontimer,TIMER_ID_P1);

            break;

        case 'd':
        case 'D':
            arrow=RIGHT;
            glutTimerFunc(TIMER_INTERVAL,ontimer,TIMER_ID_P1);

            break;

		case 'i':
		case 'I': 
			arrow=UP;
            glutTimerFunc(TIMER_INTERVAL,ontimer,TIMER_ID_P2);		
			break;

		case 'k':
		case 'K':
			arrow=DOWN;
            glutTimerFunc(TIMER_INTERVAL,ontimer,TIMER_ID_P2);
			break;

		case 'j':
		case 'J':
			arrow=LEFT;
            glutTimerFunc(TIMER_INTERVAL,ontimer,TIMER_ID_P2);		
			break;

		case 'l':
		case 'L':
			arrow=RIGHT;
            glutTimerFunc(TIMER_INTERVAL,ontimer,TIMER_ID_P2);		
			break;

	}
}

static void ontimer(int value)
{



    if(value==TIMER_ID_P1) 
	{

        if(arrow==DOWN) 
		{
			p1updown=p1updown+0.2;
            
        }
        else if(arrow==LEFT) 
		{
			p1leftright=p1leftright-0.2;
            
        }
        else if(arrow==UP) 
		{
			p1updown=p1updown-0.2;
            
        }
        else if(arrow==RIGHT) 
		{
			p1leftright=p1leftright+0.2;
            
        }
          
    }

    if(value==TIMER_ID_P2) 
	{

        if(arrow==DOWN) 
		{
			p2updown=p2updown+0.2;
            
        }
        else if(arrow==LEFT) 
		{
			p2leftright=p2leftright-0.2;
            
        }
        else if(arrow==UP) 
		{
			p2updown=p2updown-0.2;
            
        }
        else if(arrow==RIGHT) 
		{
			p2leftright=p2leftright+0.2;
            
        }
          
    }



    glutPostRedisplay();


}

static void on_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            5, 10, 15,
            5, 0, 5,
            0, 11, 0
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


    glPushMatrix();

    glColor3f(0, 0, 0);
    glTranslatef(p2updown+7+0.5, 1-0.5, p2leftright+5); /*igrac1*/
    glScalef(1, 1, 1);
    glutWireSphere(0.4,10,10);
    
    glPopMatrix();	

    glPushMatrix();

    glColor3f(0, 0, 0);
    glTranslatef(p1updown+2+0.5, 1-0.50, p1leftright+5);  /*igrac2*/
    glScalef(1, 1, 1);
    glutWireSphere(0.4,10,10);
    
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

