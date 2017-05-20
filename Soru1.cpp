#include <GL/glut.h>
#include <stdio.h> 

void display()
{
glClear(GL_COLOR_BUFFER_BIT); 
glColor3f(1,0,0);
//1.þekil için x=100 y=100 noktalarý orjin kabul edilmiþtir.
//Y ekseni
glBegin(GL_LINES);
glVertex2f(100,300);
glVertex2f(100,100);
glEnd(); 

//X ekseni 
glBegin(GL_LINES);
glVertex2f(100,100);
glVertex2f(300,100);
glEnd();

glColor3f(0,0,1);

//Kare Çizimi 
glBegin(GL_LINE_LOOP);
glVertex2f(50, 100); 
  glVertex2f(100, 150); 
  glVertex2f(150, 100); 
  glVertex2f(100, 50);  
glEnd();
//---------------------------------------------

// 2.þekil için x=400 y=100 noktalarý orjin kabul edilmiþtir.

glColor3f(1,0,0);
// Y ekseni
glBegin(GL_LINES);
glVertex2f(400,300);
glVertex2f(400,100);
glEnd(); 

//X ekseni 
glBegin(GL_LINES);
glVertex2f(400,100);
glVertex2f(600,100);
glEnd();

glColor3f(0,0,1);

//Kare Çizimi 
glPushMatrix();

//Kendi ekseninde döndürmek için
 
glTranslatef(385,75,0); //Merkezini ekledik
glRotatef(45.0,0.0,0.0,1.0); //Döndürme iþlemini gerçekleþtirdik
glTranslatef(-385,-75,0); //Merkezinin tekrar çýkardýk

//Öteleme yapmak için

glTranslatef(120.0f,-30.0f,0.0f);

//Nesnenin büyüklüðünü iki katýna çýkarmak için

glTranslatef(385,75,0);
glScalef(1.5,1.5,1.5);
glTranslatef(-385,-75,0);

//Kare Çizimi
glBegin(GL_LINE_LOOP);
glVertex2f(350, 100); 
  glVertex2f(400, 150); 
  glVertex2f(450, 100); 
  glVertex2f(400, 50);  
  

glEnd();

glPopMatrix();

glFlush();
glutSwapBuffers(); 

}

int main(int argc, char** argv)
{ 
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowSize(650,650);
glutCreateWindow("SORU1");
glutDisplayFunc(display);
gluOrtho2D(0,650,0,650);
glClearColor(1,1,1,0);
glutMainLoop();
return 0;
}
