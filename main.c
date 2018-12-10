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

 
    GLfloat light_position[] = { 1, 20, 1, 0 };

    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1 };

    GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };

    GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };


	GLfloat igrac_coeffs[] = { 0, 0, 0, 1 };
	GLfloat zid_coeffs[] = { 0.36, 0.25, 0.26, 1 };
	GLfloat pod_coeffs[] = { 0.556863, 0.137255, 0.137255, 1 };


  
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };

   
    GLfloat shininess = 30;


  
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

   
  





	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            5, 15, 20,
            5, 0, 5,
            0, 11, 0
        );



    glPushMatrix();

    glColor3f(0.556863, 0.137255, 0.137255);
    glTranslatef(7.5, -0.5, 6.5); /*pod*/

	    glMaterialfv(GL_FRONT, GL_AMBIENT,   pod_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   pod_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specular_coeffs);
    glMaterialf(GL_FRONT,  GL_SHININESS, shininess);

    glScalef(15, 1, 13);
    glutSolidCube(1);
    
    glPopMatrix();

   glPushMatrix();

    glColor3f(0.36, 0.25, 0.26);
    glTranslatef(7.5, 0.50, 0.5); /*zid1*/

	glMaterialfv(GL_FRONT, GL_AMBIENT,   zid_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   zid_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specular_coeffs);
    glMaterialf(GL_FRONT,  GL_SHININESS, shininess);


    glScalef(15, 1, 1);
    glutSolidCube(1);
    
    glPopMatrix();

    glPushMatrix();

    glColor3f(0.36, 0.25, 0.26);
    glTranslatef(7.5, 1-0.50, 0.5+12); /*zid2*/

	glMaterialfv(GL_FRONT, GL_AMBIENT,   zid_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   zid_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specular_coeffs);
    glMaterialf(GL_FRONT,  GL_SHININESS, shininess);


    glScalef(15, 1, 1);
    glutSolidCube(1);
    
    glPopMatrix();


    glPushMatrix();

    glColor3f(0.36, 0.25, 0.26);
    glTranslatef(0+0.5, 1-0.5, 6.5); /*zid3*/

	glMaterialfv(GL_FRONT, GL_AMBIENT,   zid_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   zid_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specular_coeffs);
    glMaterialf(GL_FRONT,  GL_SHININESS, shininess);



    glScalef(1, 1, 13);
    glutSolidCube(1);
    
    glPopMatrix();


    glPushMatrix();

    glColor3f(0.36, 0.25, 0.26);
    glTranslatef(14+0.5, 1-0.5, 6.5); /*zid4*/

	glMaterialfv(GL_FRONT, GL_AMBIENT,   zid_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   zid_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specular_coeffs);
    glMaterialf(GL_FRONT,  GL_SHININESS, shininess);



    glScalef(1, 1, 13);
    glutSolidCube(1);
    
    glPopMatrix();


/*STUBOVI*/
int i,j;
for(j=0;j<11;j=j+2)
{
	for(i=0;i<13; i=i+2)
	{
		glPushMatrix();

		glColor3f(0.36, 0.25, 0.26);
		glTranslatef(i+2+0.5, 1-0.5, j+2.5); 

	glMaterialfv(GL_FRONT, GL_AMBIENT,   zid_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   zid_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specular_coeffs);
    glMaterialf(GL_FRONT,  GL_SHININESS, shininess);

		glScalef(1, 1, 1);
		glutSolidCube(1);
		
		glPopMatrix();

	}
}

    glPushMatrix();

    glColor3f(0, 0, 0);
    glTranslatef(p2updown+7+0.5, 1-0.5, p2leftright+5); /*igrac1*/
	glMaterialfv(GL_FRONT, GL_AMBIENT,   igrac_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   igrac_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specular_coeffs);
    glMaterialf(GL_FRONT,  GL_SHININESS, shininess);
    glScalef(1, 1, 1);
    glutSolidSphere(0.4,10,10);
    
    glPopMatrix();	

    glPushMatrix();

    glColor3f(0, 0, 0);
    glTranslatef(p1updown+2+0.5, 1-0.50, p1leftright+5);  /*igrac2*/
	glMaterialfv(GL_FRONT, GL_AMBIENT,   igrac_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   igrac_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  specular_coeffs);
    glMaterialf(GL_FRONT,  GL_SHININESS, shininess);
    glScalef(1, 1, 1);
    glutSolidSphere(0.4,10,10);
    
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

