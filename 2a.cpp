#include <GL/glut.h>

//Global Variables
GLuint hand,foot,body,head,neck,robot;

//Variables for checking the movement of the parts of the robot.
GLfloat bodyRotate= 0.0, LeftHandRotate = 15.0,RightHandRotate = 15.0, headRotate=0.0;

void init(void)
{
	glEnable(GL_LIGHTING);
  	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	
	head = glGenLists(1);
	body = glGenLists(1);
	hand = glGenLists(1);
	foot = glGenLists(1);
	neck = glGenLists(1);
	robot = glGenLists(1);

	
	//Head için liste
	glNewList(head, GL_COMPILE);
	glShadeModel(GL_SMOOTH);
	// Küre çizme
	glPushMatrix();
	glScalef(1.8f, 1.8f, 1.8f); 
	glutSolidSphere(0.75, 50, 50);
	//sol göz
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glScalef(0.100f, 0.1009f, 0.100f); 
	glTranslatef(-3.0f,0,0); //Büyük kürenin yani kafanýn merkezine göre translate iþlemi
	glutSolidSphere(0.75, 50, 50); 
	//sað göz
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glScalef(0.10f, 0.10f, 0.10f); 
	// Ayný matrisin içinde tanýmlandýklarý için sað göz sol gözün merkezini merkez kabul eder ve ona göre translate iþlemi gerçekleþtirilir.
	glTranslatef(50,0,0);  
	glutSolidSphere(7, 50, 50); 
	glPopMatrix();
	glEndList();
	 
	//Neck için liste
	glNewList(neck, GL_COMPILE);
	glPushMatrix();
	glScalef(2.0f, 2.0f, 2.0f);	
	glTranslatef(0.01f,-2.25,0);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glScalef(2.0f, 1.5f, 0.5f); 
	gluCylinder(quadratic,0.1f,0.1f,0.80f,32,32);
	glPopMatrix();
	glEndList();
	
	//Generating List for Body
	glNewList(body, GL_COMPILE);
	glPushMatrix();
	glColor4f(0.0, 0.0, 1.0, 1.0);
	glScalef(2.5f, 5.5f, 1.0f);
	GLUquadricObj *quadratic2;
	quadratic2 = gluNewQuadric();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glScalef(2.0f, 1.5f, 0.5f);
	
	glBegin;
	
	gluCylinder(quadratic2,0.270f,0.270f,2.0f,50,50);
	glEnd();
	glPopMatrix();
	glEndList();

	//Generating List for Hand
	glNewList(hand, GL_COMPILE);
	glPushMatrix();
	glTranslatef(0.0f, -1.5f, 0.0f);
	glScalef(1.0f, 2.0f, 1.0f);
	glutSolidCube(1.0);
	glPopMatrix();
	glEndList();

	//Generating List for Foot
	glNewList(foot, GL_COMPILE);
	glPushMatrix();
	glTranslatef(0.0f, -1.975f, 0.0f);
	glScalef(1.0f, 5.0f, 1.0f);
	GLUquadricObj *quadratic3;
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glScalef(1.8f, 1.5f, 0.5f);
	glBegin;
	gluCylinder(quadratic2,0.270f,0.270f,2.0f,50,50);
	glEnd();
	glPopMatrix();
	glEndList();
}

void display(void)
{
	 GLfloat position[] =
  {2.5, 2.5, 0.0, 0.0};

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
	
//	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();  /*clear the matrix */

	/*viewing transformation*/
	gluLookAt(0.5,0, 10, 0.0, 3.0, 0.0, 0.0, 1.0, 0.0);
	
	
		glPushMatrix(); ///
	glLightfv(GL_LIGHT0, GL_POSITION, position);
		glRotatef(bodyRotate, 0.0, 1.0, 0.0);
	 glEnable(GL_LIGHTING);
	// Making Foots

		glColor3f(0.1, 0.7, 0.1);
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, 0.0f);
		//Making and Rotating Left Foot
		glPushMatrix();
		glTranslatef(1.0f, 0.0f, 0.0f);
		//Calling callList function to draw Left Foot
		glCallList(foot);
		glPopMatrix();

		//Making and Rotating Right Foot
		glPushMatrix();
		glTranslatef(-1.0f, 0.0f, 0.0f);
		
		//Calling callList function to draw Right Foot
		glCallList(foot);
		glPopMatrix();	
	glPopMatrix();
	
	// Making Hands
	glColor3f(0.45, 0.0, 1.0);

	glPushMatrix();
	glTranslatef(0.0f, 4.5f, 0.0f);
		//Making and Rotating Left Hand
		glPushMatrix();
		glTranslatef(2.0f, 0.0f, 0.0f);
		//Calling callList function to draw Left Hand
		glRotatef(LeftHandRotate, 1.0, 0.0, 0.0);
		glCallList(hand);
		glTranslatef(0.0f, -2.2f, 0.0f);
		glCallList(hand);
		glPopMatrix();
		//Making and Rotating Right Hand
		glPushMatrix();
		glTranslatef(-2.0f, 0.0f, 0.0f);
		glRotatef(RightHandRotate, 1.0, 0.0, 0.0);
		//Calling callList function to draw Right Hand
		glCallList(hand);
		glTranslatef(0.0f, -2.2f, 0.0f);
		glCallList(hand);
		glPopMatrix();
	glPopMatrix();

	// Body
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0f, 4.70f, 0.0f);
	//Calling callList function to draw Body
	glCallList(body);
	glPopMatrix();
	
	//Neck
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0f, 10.0f, 0.0f);
	glCallList(neck);
	glPopMatrix();
	
	// Head
	glColor3f(0.9, 0.8, 0.0);
	glPushMatrix();
	glTranslatef(0.0f, 6.75f, 0.0f);
	glRotatef(headRotate, 0.0, 1.0, 0.0);
	//Calling callList function to draw Head
	glCallList(head);
	glPopMatrix();

glPopMatrix(); ///
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -20.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y)
{
	if(key == 'a')
	{
	RightHandRotate = RightHandRotate + 20.0;
	if (RightHandRotate> 360.0)
		RightHandRotate = 0.5;
	}
	if(key == 'A') 
	{
		LeftHandRotate += 20.0;
		if(LeftHandRotate > 360.0)
		LeftHandRotate = 0.5;
	}
	if(key == 'x')
	{
		bodyRotate += 20.0;
	}
	if(key == 'X')
	{
		bodyRotate -= 20.0;
	}
	if(key == 'h')
	{
		headRotate += 20.0;
	}
	if(key == 'H')
	{
		headRotate -= 20.0;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
