#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>
#include<time.h>

#include <windows.h>

#include <GL/glut.h>
#include<math.h>>



#define PI           3.14159265358979323846

GLfloat i = 0.0f;

/*void initGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Black and opaque
}*/

/*void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}*/


GLfloat position = 0.0f;//Cloud & Aeroplane
GLfloat speed = 0.1f;
GLfloat position1 = 1.0f;//Bus1
GLfloat speed1 = 0.1f;
GLfloat position2 = 0.1f;//Bus2
GLfloat speed2 = 0.1f;
GLfloat position3 = 1.0f;//Ship
GLfloat speed3 = 0.1f;
GLfloat position4 = 0.0f;//Thunder.
GLfloat speed4 = 0.4f;
GLfloat position5 = 0.0f;//Rain.
GLfloat speed5 = 0.1f;

//Clouds:
void update(int value) {

    if(position >1.90)
        position = -1.0f;

    position += speed;

    glutPostRedisplay();


    glutTimerFunc(60, update, 0);
}
void update1(int value) {

    if(position1 <-1.90)
        position1 = 1.0f;

    position1 -= speed1;

    glutPostRedisplay();


    glutTimerFunc(100, update1, 0);
}

//arpln
void update2(int value) {

    if(position2 >1.90)
        position2 = -1.0f;

    position2 += speed2;

    glutPostRedisplay();


    glutTimerFunc(60, update2, 0);
}

//SHIP:
void update3(int value) {

    if(position3 >1.90)
        position3 = -1.0f;

    position3 += speed3;

    glutPostRedisplay();


    glutTimerFunc(160, update3, 0);
}
//Thunder

void update4(int value) {

    if(position4 <-1.60)
        position4 = 0.9f;

    position4 -= speed4;

    glutPostRedisplay();


    glutTimerFunc(930, update4, 0);
}

//Rain:
void update5(int value) {

    if(position5 <-1.60)
        position5 = 0.9f;

    position5 -= speed5;

    glutPostRedisplay();


    glutTimerFunc(400000000, update5, 10);
}




void init() {
   glClearColor(.0f, .9f, .9f, 1.0f);
}





void display() {
      //glClearColor(0.0f, 0.9f, 0.9f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    /*
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);
    glEnd();
    */



    //Thunder:
    glPushMatrix();
    glTranslatef(0.0f,   0.0f, position4);
    glTranslatef(.0,.7,.0);
    glScalef(2,.6,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(-0.7, 0.5);
    glVertex2f(-0.5, 0.3);

    glVertex2f(-0.5, 0.3);
    glVertex2f(-0.2, 0.3);

    glVertex2f(-0.2, 0.3);
    glVertex2f(0.1, 0.5);

    glVertex2f(-0.2, 0.3);
    glVertex2f(-0.1, 0.2);

    glVertex2f(-0.1, 0.2);
    glVertex2f(0.6, 0.2);

    glVertex2f(-0.1, 0.2);
    glVertex2f(0.6, -0.1);

    glEnd();
    glLoadIdentity();
    glPopMatrix();







    //Sun:

     glEnable(GL_LIGHTING);//Enable Light Effect

  GLfloat global_ambient[] = {10.0,10.0,0.0, 0.1};//ambient RGBA intensity of light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);//A lighting model parameter

    glTranslatef(0.0, .8, 0);
    int i;
    GLfloat x=.0 ;GLfloat y =.0;GLfloat radius = 0.12f;
    int triangleAmount = 10;
    GLfloat twicePi  = 2.0*PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(x,y);
    for(i=0;i<=triangleAmount;i++)
    {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
    }
    glEnd();
   //glLoadIdentity();


   glTranslatef(-0.03,0.93,0);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0,1.0,0.0);
   glVertex2f(0.0,.0);
   glVertex2f(0.08,.0);
   glVertex2f(0.04,.08);
   glEnd();
   glLoadIdentity();

   glTranslatef(0.04,0.67,0);
   glScalef(-1,-1,0);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0,1.0,0.0);
   glVertex2f(0.0,.0);
   glVertex2f(0.08,.0);
   glVertex2f(0.04,.08);
   glEnd();
   glLoadIdentity();

   glTranslatef(-0.14,0.75,0);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0,1.0,0.0);
   glVertex2f(0.0,.0);
   glVertex2f(-0.08,.04);
   glVertex2f(0.0,.08);
   glEnd();
   glLoadIdentity();

   glTranslatef(0.14,0.75,0);
   glScalef(-1,1,0);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0,1.0,0.0);
   glVertex2f(0.0,.0);
   glVertex2f(-0.08,.04);
   glVertex2f(0.0,.08);
   glEnd();
   glLoadIdentity();

   glTranslatef(.1,0.85,0);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0,1.0,0.0);
   glVertex2f(0.0,.05);
   glVertex2f(0.05,.0);
   glVertex2f(0.1,.1);
   glEnd();
   glLoadIdentity();

   glTranslatef(-.1,0.85,0);
   glScalef(-1,1,0);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0,1.0,0.0);
   glVertex2f(0.0,.05);
   glVertex2f(0.05,.0);
   glVertex2f(0.1,.1);
   glEnd();
   glLoadIdentity();

   glTranslatef(-.06,0.71,0);
   glScalef(-1,-1,0);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0,1.0,0.0);
   glVertex2f(0.0,.05);
   glVertex2f(0.05,.0);
   glVertex2f(0.1,.1);
   glEnd();
   glLoadIdentity();

   glTranslatef(.08,0.73,0);
   glScalef(1,-1,0);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0,1.0,0.0);
   glVertex2f(0.0,.05);
   glVertex2f(0.05,.0);
   glVertex2f(0.1,.1);
   glEnd();
   glLoadIdentity();

   glTranslatef(.0,0.93,0);
   glScalef(.84, .84,0);
   glBegin(GL_TRIANGLES);
   glColor3f(1.0,1.0,0.0);
   glVertex2f(0.05,.0);
   glVertex2f(-0.05,.0);
   glVertex2f(0.0,.1);
   glEnd();
   glLoadIdentity();

   glDisable(GL_LIGHTING);//Enable Light Effect






   //STARS:
   glTranslatef(-.6,.86,1);
   glScalef(.6,.6,1);
   glBegin(GL_POLYGON);
   glColor3f(0.0,0.0,0.9);
   glVertex2f(.0,.0);
   glVertex2f(-.1,-.1);
   glVertex2f(.0,.2);
   glVertex2f(.1,-.1);
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(0.0,0.0,0.9);
   glVertex2f(.0,.0);
   glVertex2f(-.2,.1);
   glVertex2f(.2,.1);
   glEnd();
   glLoadIdentity();

   glTranslatef(-.45,.7,1);
   glScalef(.6,.6,1);
   glBegin(GL_POLYGON);
   glColor3f(0.0,0.0,0.9);
   glVertex2f(.0,.0);
   glVertex2f(-.1,-.1);
   glVertex2f(.0,.2);
   glVertex2f(.1,-.1);
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(0.0,0.0,0.9);
   glVertex2f(.0,.0);
   glVertex2f(-.2,.1);
   glVertex2f(.2,.1);
   glEnd();
   glLoadIdentity();

   glTranslatef(.8,.8,1);
   glScalef(.6,.6,1);
   glBegin(GL_POLYGON);
   glColor3f(0.0,0.0,0.9);
   glVertex2f(.0,.0);
   glVertex2f(-.1,-.1);
   glVertex2f(.0,.2);
   glVertex2f(.1,-.1);
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(0.0,0.0,0.9);
   glVertex2f(.0,.0);
   glVertex2f(-.2,.1);
   glVertex2f(.2,.1);
   glEnd();
   glLoadIdentity();

   glTranslatef(0.5,.67,1);
   glScalef(.6,.6,1);
   glBegin(GL_POLYGON);
   glColor3f(0.0,0.0,0.9);
   glVertex2f(.0,.0);
   glVertex2f(-.1,-.1);
   glVertex2f(.0,.2);
   glVertex2f(.1,-.1);
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(0.0,0.0,0.9);
   glVertex2f(.0,.0);
   glVertex2f(-.2,.1);
   glVertex2f(.2,.1);
   glEnd();
   glLoadIdentity();

   glTranslatef(0.4,.88,1);
   glScalef(.6,.6,1);
   glBegin(GL_POLYGON);
   glColor3f(0.0,0.0,0.9);
   glVertex2f(.0,.0);
   glVertex2f(-.1,-.1);
   glVertex2f(.0,.2);
   glVertex2f(.1,-.1);
   glEnd();
   glBegin(GL_TRIANGLES);
   glColor3f(0.0,0.0,0.9);
   glVertex2f(.0,.0);
   glVertex2f(-.2,.1);
   glVertex2f(.2,.1);
   glEnd();
   glLoadIdentity();


   //Moon:

   glTranslatef(-.89, .89, 0);

     x=0.0 ;  y =0.0 ;   radius = 0.1f;
   triangleAmount = 10;
     twicePi  = 2.0*PI;

   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   glLoadIdentity();









    //---->>Clouds
    glPushMatrix();
glTranslatef(position,0.0f, 0.0f);
    glTranslatef(-.1, .79, 0);

     x=0.0 ;  y =0.0 ;   radius = 0.1f;
   triangleAmount = 10;
     twicePi  = 2.0*PI;

   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
    x=0.1 ; y =0.0 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   x=0.03 ; y =0.09 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   glLoadIdentity();

   glPushMatrix();
glTranslatef(position,0.0f, 0.0f);
   glTranslatef(-.87, .78, 0);
     x=0.0 ; y =0.0 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();

    x=0.1 ; y =0.0 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
  glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   x=0.03 ; y =0.09 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   glLoadIdentity();

  glPushMatrix();
glTranslatef(position,0.0f, 0.0f);
   glTranslatef(.8, .79, 0);
     x=0.0 ; y =0.0 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();

    x=0.1 ; y =0.0 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   x=0.03 ; y =0.09 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   glLoadIdentity();

  glPushMatrix();
glTranslatef(position,0.0f, 0.0f);
   glTranslatef(.4, .7, 0);
     x=0.0 ; y =0.0 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
  glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();

    x=0.1 ; y =0.0 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   x=0.03 ; y =0.09 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.3, 0.3);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   glLoadIdentity();
   glPopMatrix();


    //Aeroplane1:
    glPushMatrix();
glTranslatef(position,0.0f, 0.0f);
    glTranslatef(-.47, .79, 0);
    glScalef(.28,.28,0);
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-.6, .2);
    glVertex2f(-.6, -0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.6, 0.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.1, 1.0);
    glVertex2f(.6, .0);
    glVertex2f(.9, .0);
    glVertex2f(.9, .1);
    glVertex2f(.6, .2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.1, 1.0);
    glVertex2f(.6, .0);
    glVertex2f(.6, -.2);
    glVertex2f(.9, .0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.1, 1.0);
    glVertex2f(.0, .2);
    glVertex2f(-.2, .4);
    glVertex2f(-.1, .5);
    glVertex2f(.2, .2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.1, 1.0);
    glVertex2f(.1, -.1);
    glVertex2f(-.1, -.3);
    glVertex2f(.0, -.4);
    glVertex2f(.3, -.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.1, 1.0);
    glVertex2f(-.6, .2);
    glVertex2f(-.6, .4);
    glVertex2f(-.4, .4);
    glVertex2f(-.2, .2);
    glEnd();
    i;
    x=-0.4 ; y =-0.25;radius = 0.1f;
    triangleAmount = 10;
    twicePi  = 2.0*PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0;i<=triangleAmount;i++)
    {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
    }
    glEnd();

    x=-0.2; y =-0.25;  radius = 0.1f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0;i<=triangleAmount;i++)
    {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
    }
    glEnd();

   x=0.3 ; y =-0.25 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();

    x=0.5 ; y =-0.25 ;  radius = 0.1f;
   glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   glLoadIdentity();
   glPopMatrix();








   //Aeroplane2:
   glPushMatrix();
glTranslatef(position1,0.0f, 0.0f);
   glTranslatef(.08,0.8,0);
   glScalef(.4,.2,0);
  glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red

	glVertex2f(-0.7f,-0.5f);    // x, y
	glVertex2f(-0.5f, -0.7f);
	glVertex2f(-.5f,  -0.3f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.0f); // Red

	glVertex2f(-0.6f, -0.55f);    // x, y
	glVertex2f(-0.55f, -0.55f);
	glVertex2f(-0.55f, -0.45f);    // x, y
	glVertex2f(-0.6f, -0.45f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red

	glVertex2f(-0.5f, -0.7f);    // x, y
	glVertex2f(0.3f, -0.7f);
	glVertex2f(0.3f, -0.3f);    // x, y
	glVertex2f(-0.5f, -0.3f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red

	glVertex2f(0.3f, -0.3f);    // x, y
	glVertex2f(0.3f, -0.7f);
	glVertex2f(0.5f, 0.0f);    // x, y
	glVertex2f(0.5f, 0.3f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, .0f); // Red

	glVertex2f(-0.2f, -0.3f);    // x, y
	glVertex2f(-0.2f, -0.4f);    // x, y

	glVertex2f(-0.2f, -0.4f);    // x, y
	glVertex2f(-0.1f, -.4f);    // x, y

    glVertex2f(-0.1f, -0.4f);    // x, y
	glVertex2f(-0.1f, -0.6f);    // x, y

	glVertex2f(-0.1f, -0.6f);    // x, y
	glVertex2f(-0.2f, -0.6f);

	glVertex2f(-0.2f, -0.6f);    // x, y
	glVertex2f(-0.2f, -0.7f);    // x, y

	glVertex2f(0.1f, -0.3f);    // x, y
	glVertex2f(0.1f, -0.4f);    // x, y

    glVertex2f(0.1f, -0.4f);    // x, y
	glVertex2f(0.f, -0.4f);    // x, y

	glVertex2f(0.0f, -0.4f);    // x, y
	glVertex2f(0.0f, -0.6f);

	glVertex2f(0.0f, -0.6f);    // x, y
	glVertex2f(0.1f, -0.6f);

	glVertex2f(0.1f, -0.6f);    // x, y
	glVertex2f(0.1f, -0.7f);

	glVertex2f(-0.5f, -0.3f);    // x, y
	glVertex2f(-0.5f, -0.7f);


	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.0f); // Red

	glVertex2f(-0.4f, -0.55f);    // x, y
	glVertex2f(-0.25f, -0.55f);
	glVertex2f(-0.25f, -0.45f);    // x, y
	glVertex2f(-0.4f, -0.45f);

	glEnd();

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.0f); // Red

	glVertex2f(0.12f, -0.55f);    // x, y
	glVertex2f(0.27f, -0.55f);
	glVertex2f(0.27f, -0.45f);    // x, y
	glVertex2f(0.12f, -0.45f);

	glEnd();

   //glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	//glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glColor3f(0.0f, 0.0f, 0.0f); // Red

    x=-.3f; y=-.75f; radius =.05f;
	triangleAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
			 x=0.1f;  y=-.75f;  radius =.05f;
	 triangleAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

				glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glLoadIdentity();
	glPopMatrix();



    //Hills:
    glTranslatef(0.0,-.10,0.0);
    glScalef(1.2,1.2,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-1.0,0.355);
    glVertex2f(-0.5,0.65);
    glVertex2f(0.0,0.355);
    glEnd();

    glTranslatef(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-1.0,0.355);
    glVertex2f(-0.5,0.65);
    glVertex2f(0.0,0.355);
    glEnd();
    glLoadIdentity();

    glTranslatef(-0.6,.0,0.0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-1.0,0.355);
    glVertex2f(-0.5,0.65);
    glVertex2f(0.0,0.355);
    glEnd();
    glLoadIdentity();

    glTranslatef(0.3,.0,0.0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-1.0,0.355);
    glVertex2f(-0.5,0.65);
    glVertex2f(0.0,0.355);
    glEnd();
    glLoadIdentity();

    glTranslatef(0.66,0.0,0.0);
    glScalef(1,.9,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-1.0,0.355);
    glVertex2f(-0.5,0.65);
    glVertex2f(0.0,0.355);
    glEnd();
    glLoadIdentity();

    glTranslatef(1.0,0.0,0.0);
     glTranslatef(0.45,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(-1.0,0.355);
    glVertex2f(-0.5,0.65);
    glVertex2f(0.0,0.355);
    glEnd();
    glLoadIdentity();



     //SEA SHORE
     glScalef(1,1,0);
    glBegin(GL_QUADS);
    glColor3f(0.3,0.0,0.0);
    glVertex2f(-1.0,0.25);
    glVertex2f(-1.0,-0.9);
    glVertex2f(1.0,-0.9);
    glVertex2f(1.0,0.25);
    glEnd();
    glLoadIdentity();


     //A_Bus:
    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
    glTranslatef(.9, .05,0);
    glScalef(.2,.18,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-.7, .6);
    glVertex2f(-.95, .1);
    glVertex2f(-0.9, -.3);
    glVertex2f(-.7, -.4);
    glVertex2f(.8, -.4);
    glVertex2f(.9, -.3);
    glVertex2f(.9, .5);
    glVertex2f(.8, .6);
    glVertex2f(-.7, .6);
    glEnd();

   x=-0.1 ; y =-0.4; radius = 0.2f;
   triangleAmount = 10;
   twicePi  = 2.0*PI;

   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   x=-0.1; y =-0.4;  radius = 0.14f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.5, 0.5);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();

    x=0.6; y =-0.4;  radius = 0.2f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   x=0.6; y =-0.4;  radius = 0.14f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.5, 0.5);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(-.8, .5);
    glVertex2f(-.7, .6);
    glVertex2f(-0.7, .1);
    glVertex2f(-.95, .1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(-.9, -.3);
    glVertex2f(-.9, -.4);
    glVertex2f(-.7, -.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.5,0.5);
    glVertex2f(-.6, .4);
    glVertex2f(-.6, -.2);
    glVertex2f(-0.5, -.3);
    glVertex2f(-.4, -.3);
    glVertex2f(-.3, -.2);
    glVertex2f(-.3, .4);
    glVertex2f(-.4, .5);
    glVertex2f(-.5, .5);
    glVertex2f(-.6, .4);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-.45, .5);
    glVertex2f(-.45, -.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-.1, .53);
    glVertex2f(-.23, .4);
    glVertex2f(-.23, .2);
    glVertex2f(-.1, .07);
    glVertex2f(.7, 0.07);
    glVertex2f(.83, .2);
    glVertex2f(.83, .4);
    glVertex2f(.7, .53);
    glVertex2f(-.1, .53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-.1, .5);
    glVertex2f(-.2, .4);
    glVertex2f(-.2, .2);
    glVertex2f(-.1, .1);
    glVertex2f(.7, 0.1);
    glVertex2f(.8, .2);
    glVertex2f(.8, .4);
    glVertex2f(.7, .5);
    glVertex2f(-.1, .5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.0, .1);
    glVertex2f(0.0, .5);

    glVertex2f(.2, .1);
    glVertex2f(.2, .5);

    glVertex2f(.4, .1);
    glVertex2f(.4, .5);

    glVertex2f(.6, .1);
    glVertex2f(.6, .5);
    glEnd();
    glLoadIdentity();
    glPopMatrix();







    //Another_Bus:

    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    glTranslatef(-.9, -.2,0);
    glScalef(-.2,.2,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-.7, .6);
    glVertex2f(-.95, .1);
    glVertex2f(-0.9, -.3);
    glVertex2f(-.7, -.4);
    glVertex2f(.8, -.4);
    glVertex2f(.9, -.3);
    glVertex2f(.9, .5);
    glVertex2f(.8, .6);
    glVertex2f(-.7, .6);
    glEnd();

   x=-0.1 ; y =-0.4; radius = 0.2f;
   triangleAmount = 10;
   twicePi  = 2.0*PI;

   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   x=-0.1; y =-0.4;  radius = 0.14f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.5, 0.5);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();

    x=0.6; y =-0.4;  radius = 0.2f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();
   x=0.6; y =-0.4;  radius = 0.14f;
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0, 0.5, 0.5);
    glVertex2f(x,y);
   for(i=0;i<=triangleAmount;i++)
   {
       glVertex2f(
                  x+(radius*cos(i*twicePi/triangleAmount)),
                  y+(radius*sin(i*twicePi/triangleAmount))

                  );
   }
   glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(-.8, .5);
    glVertex2f(-.7, .6);
    glVertex2f(-0.7, .1);
    glVertex2f(-.95, .1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(-.9, -.3);
    glVertex2f(-.9, -.4);
    glVertex2f(-.7, -.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.5,0.5);
    glVertex2f(-.6, .4);
    glVertex2f(-.6, -.2);
    glVertex2f(-0.5, -.3);
    glVertex2f(-.4, -.3);
    glVertex2f(-.3, -.2);
    glVertex2f(-.3, .4);
    glVertex2f(-.4, .5);
    glVertex2f(-.5, .5);
    glVertex2f(-.6, .4);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-.45, .5);
    glVertex2f(-.45, -.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-.1, .53);
    glVertex2f(-.23, .4);
    glVertex2f(-.23, .2);
    glVertex2f(-.1, .07);
    glVertex2f(.7, 0.07);
    glVertex2f(.83, .2);
    glVertex2f(.83, .4);
    glVertex2f(.7, .53);
    glVertex2f(-.1, .53);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-.1, .5);
    glVertex2f(-.2, .4);
    glVertex2f(-.2, .2);
    glVertex2f(-.1, .1);
    glVertex2f(.7, 0.1);
    glVertex2f(.8, .2);
    glVertex2f(.8, .4);
    glVertex2f(.7, .5);
    glVertex2f(-.1, .5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.0, .1);
    glVertex2f(0.0, .5);

    glVertex2f(.2, .1);
    glVertex2f(.2, .5);

    glVertex2f(.4, .1);
    glVertex2f(.4, .5);

    glVertex2f(.6, .1);
    glVertex2f(.6, .5);
    glEnd();
    glLoadIdentity();
    glPopMatrix();



    //SEA
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(-1.0,-0.35);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glVertex2f(1.0,-0.35);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4392156862745098,0.5019607843137255,0.576);
    glVertex2f(-1.0,0.355);
    glVertex2f(-1.0,0.245);
    glVertex2f(1.0,0.245);
    glVertex2f(1.0,0.355);
    glEnd();



    //Ship:

    glPushMatrix();
    glTranslatef(position3,0.0f, 0.0f);
    glTranslatef(-.9, -.73,0);
    glScalef(0.45,0.4,0);

     glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red

	glVertex2f(-0.5f, 0.0f);    // x, y
	glVertex2f(-0.3f, -0.5f);
	glVertex2f(0.3f, -0.5f);    // x, y
	glVertex2f(0.5f, 0.0f);

	glEnd();

     glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f); // Red

	glVertex2f(-0.4f, 0.05f);    // x, y
	glVertex2f(-0.4f, 0.0f);
	glVertex2f(0.4f, 0.0f);    // x, y
	glVertex2f(0.4f, 0.05f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(128.0f, 0.0f, 128.0f); // Red

	glVertex2f(-0.3f, 0.1f);    // x, y
	glVertex2f(-0.3f, 0.05f);
	glVertex2f(0.3f, 0.05f);    // x, y
	glVertex2f(0.3f, 0.1f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red

	glVertex2f(-0.22f, 0.4f);    // x, y
	glVertex2f(-0.22f, 0.1f);
	glVertex2f(-0.12f, 0.1f);    // x, y
	glVertex2f(-0.12f, 0.4f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red

	glVertex2f(-0.06f, 0.4f);    // x, y
	glVertex2f(-0.06f, 0.1f);
	glVertex2f(0.04f, 0.1f);    // x, y
	glVertex2f(0.04f, 0.4f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red

	glVertex2f(0.12f, 0.4f);    // x, y
	glVertex2f(0.12f, 0.1f);
	glVertex2f(0.22f, 0.1f);    // x, y
	glVertex2f(0.22f, 0.4f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 255.0f); // Red

	glVertex2f(0.12f, 0.3f);    // x, y
	glVertex2f(0.12f, 0.2f);
	glVertex2f(0.22f, 0.2f);    // x, y
	glVertex2f(0.22f, 0.3f);

	glEnd();


	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 255.0f); // Red

	glVertex2f(-0.22f, 0.3f);    // x, y
	glVertex2f(-0.22f, 0.2f);
	glVertex2f(-0.12f, 0.2f);    // x, y
	glVertex2f(-0.12f, 0.3f);

	glEnd();


	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 255.0f); // Red

	glVertex2f(-0.06f, 0.3f);    // x, y
	glVertex2f(-0.06f, 0.2f);
	glVertex2f(0.04f, 0.2f);    // x, y
	glVertex2f(0.04f, 0.3f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red

	glVertex2f(0.43f, 0.8f);    // x, y
	glVertex2f(0.43f, 0.0f);
	glVertex2f(0.45f, 0.0f);    // x, y
	glVertex2f(0.45f, 0.8f);

	glEnd();

	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red

	glVertex2f(0.38f, 0.7f);    // x, y
	glVertex2f(0.38f, 0.6f);
	glVertex2f(0.5f, 0.6f);    // x, y
	glVertex2f(0.5f, 0.7f);

	glEnd();

	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red

	glVertex2f(0.43f, 0.8f);    // x, y
	glVertex2f(0.22f, 0.3f);    // x, y


	glVertex2f(0.43f, 0.6f);    // x, y
	glVertex2f(0.22f, 0.1f);    // x, y

	glEnd();

	//circle

	glColor3f(255.0f, 0.0f, 0.0f); // Red


    x=-0.2f; y=-0.25f; radius =.05f;
	triangleAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();



	 x=0.0f;  y=-0.25f;  radius =.05f;
	 triangleAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	//i;

	 x=0.2f;  y=-0.25f;  radius =.05f;
	 triangleAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();









    glPushMatrix();
	 glTranslatef(0.0f,position4,0.0);
glTranslatef(.0,-.9,0);
glScalef(1.2,1.2,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.7, 0.9);
    glVertex2f(0.6, 0.8);

    glVertex2f(0.5, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.8);

    glVertex2f(0.1, 0.9);
    glVertex2f(0.0, 0.8);

    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.5, 0.9);
    glVertex2f(-0.6, 0.8);

    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.8, 0.8);

    glVertex2f(-0.9, 0.9);
    glVertex2f(-1.0, 0.8);

    glEnd();
    glLoadIdentity();
    glPopMatrix();


glPushMatrix();
	 glTranslatef(0.0f,position4,0.0f);
    glTranslatef(.0,-.7,0);
glScalef(1.2,1.2,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.7, 0.9);
    glVertex2f(0.6, 0.8);

    glVertex2f(0.5, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.8);

    glVertex2f(0.1, 0.9);
    glVertex2f(0.0, 0.8);

    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.5, 0.9);
    glVertex2f(-0.6, 0.8);

    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.8, 0.8);

    glVertex2f(-0.9, 0.9);
    glVertex2f(-1.0, 0.8);

    glEnd();
    glLoadIdentity();


    glPopMatrix();

    glPushMatrix();
	 glTranslatef(0.0f,position4,0.0f);
    glTranslatef(.0,-.4,0);
glScalef(1.2,1.2,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.7, 0.9);
    glVertex2f(0.6, 0.8);

    glVertex2f(0.5, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.8);

    glVertex2f(0.1, 0.9);
    glVertex2f(0.0, 0.8);

    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.5, 0.9);
    glVertex2f(-0.6, 0.8);

    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.8, 0.8);

    glVertex2f(-0.9, 0.9);
    glVertex2f(-1.0, 0.8);

    glEnd();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
	 glTranslatef(0.0f,position4,0.0f);
    glTranslatef(.0,-.2,0);
glScalef(1.2,1.2,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.7, 0.9);
    glVertex2f(0.6, 0.8);

    glVertex2f(0.5, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.8);

    glVertex2f(0.1, 0.9);
    glVertex2f(0.0, 0.8);

    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.5, 0.9);
    glVertex2f(-0.6, 0.8);

    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.8, 0.8);

    glVertex2f(-0.9, 0.9);
    glVertex2f(-1.0, 0.8);

    glEnd();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
	 glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(.0,.0,0);
glScalef(1.2,1.2,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.7, 0.9);
    glVertex2f(0.6, 0.8);

    glVertex2f(0.5, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.8);

    glVertex2f(0.1, 0.9);
    glVertex2f(0.0, 0.8);

    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.5, 0.9);
    glVertex2f(-0.6, 0.8);

    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.8, 0.8);

    glVertex2f(-0.9, 0.9);
    glVertex2f(-1.0, 0.8);

    glEnd();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
	 glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(.0,.2,0);
glScalef(1.2,1.2,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.7, 0.9);
    glVertex2f(0.6, 0.8);

    glVertex2f(0.5, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.8);

    glVertex2f(0.1, 0.9);
    glVertex2f(0.0, 0.8);

    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.5, 0.9);
    glVertex2f(-0.6, 0.8);

    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.8, 0.8);

    glVertex2f(-0.9, 0.9);
    glVertex2f(-1.0, 0.8);

    glEnd();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
	 glTranslatef(0.0f,position4,0.0f);
    glTranslatef(.0,.4,0);
glScalef(1.2,1.2,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.7, 0.9);
    glVertex2f(0.6, 0.8);

    glVertex2f(0.5, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.8);

    glVertex2f(0.1, 0.9);
    glVertex2f(0.0, 0.8);

    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.5, 0.9);
    glVertex2f(-0.6, 0.8);

    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.8, 0.8);

    glVertex2f(-0.9, 0.9);
    glVertex2f(-1.0, 0.8);

    glEnd();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
	 glTranslatef(0.0f,position4, 0.0f);
    glTranslatef(.0,.6,0);
glScalef(1.2,1.2,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.7, 0.9);
    glVertex2f(0.6, 0.8);

    glVertex2f(0.5, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.8);

    glVertex2f(0.1, 0.9);
    glVertex2f(0.0, 0.8);

    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.5, 0.9);
    glVertex2f(-0.6, 0.8);

    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.8, 0.8);

    glVertex2f(-0.9, 0.9);
    glVertex2f(-1.0, 0.8);

    glEnd();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
	 glTranslatef(0.0f,position4,0.0f);
    glTranslatef(.0,.8,0);
glScalef(1.2,1.2,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.7, 0.9);
    glVertex2f(0.6, 0.8);

    glVertex2f(0.5, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.8);

    glVertex2f(0.1, 0.9);
    glVertex2f(0.0, 0.8);

    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.5, 0.9);
    glVertex2f(-0.6, 0.8);

    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.8, 0.8);

    glVertex2f(-0.9, 0.9);
    glVertex2f(-1.0, 0.8);

    glEnd();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
	 glTranslatef(0.0f, position4, 0.0f);
    glTranslatef(.0,1,0);
glScalef(1.2,1.2,0);
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.9, 0.9);
    glVertex2f(0.8, 0.8);

    glVertex2f(0.7, 0.9);
    glVertex2f(0.6, 0.8);

    glVertex2f(0.5, 0.9);
    glVertex2f(0.4, 0.8);

    glVertex2f(0.3, 0.9);
    glVertex2f(0.2, 0.8);

    glVertex2f(0.1, 0.9);
    glVertex2f(0.0, 0.8);

    glVertex2f(-0.1, 0.9);
    glVertex2f(-0.2, 0.8);

    glVertex2f(-0.3, 0.9);
    glVertex2f(-0.4, 0.8);

    glVertex2f(-0.5, 0.9);
    glVertex2f(-0.6, 0.8);

    glVertex2f(-0.7, 0.9);
    glVertex2f(-0.8, 0.8);

    glVertex2f(-0.9, 0.9);
    glVertex2f(-1.0, 0.8);

    glEnd();
    glLoadIdentity();
    glPopMatrix();





   glFlush();
}


/*
//Automatic_night_Using_Timer_Function:
float shopnil=0.0;

void Night(int){
    glClearColor(0.0,0.0,0.0,1.0);

    glutPostRedisplay();
    shopnil++;

} */


/*
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{

			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);

	}

		if (button == GLUT_RIGHT_BUTTON)
	{

			speed -= 0.1f;
			printf("clicked at (%d, %d)\n", x, y);

	}



	glutPostRedisplay();
}
*/

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'a':
    speed = 0.0f;
    speed1 = 0.0f;
    speed2 = 0.0f;
    speed3 = 0.0f;
    break;
case 'w':
    speed = 0.1f;
    speed1 = 0.1f;
    speed2 = 0.1f;
    speed3 = 0.1f;
    break;

    case 'n':
    glClearColor(.0f, .0f, .0f, 1.0f);
    break;

case 'd':
    glClearColor(0.0f, 0.8f, 0.7f, 1.0f);



    break;

glutPostRedisplay();


	}
}

//For arrow keys:

void SpecialInput(int key, int x, int y)
{
switch(key)
{
case GLUT_KEY_UP:
//do something here
glutTimerFunc(100, update, 0);
break;
case GLUT_KEY_DOWN:

   glutTimerFunc(100, update3, 0);
break;
case GLUT_KEY_LEFT:
glutTimerFunc(-100, update1, 0);
break;


case GLUT_KEY_RIGHT:

//do something here
glutTimerFunc(100, update2, 0);
break;


}
glutPostRedisplay();
}


void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{

			speed += 0.01f;
			speed1 += 0.01f;
			speed2 += 0.01f;
			speed3 += 0.01f;
			printf("clicked at (%d, %d)\n", x, y);

	}

		if (button == GLUT_RIGHT_BUTTON)
	{

			speed -= 0.01f;
			speed1 -= 0.01f;
			speed2 -= 0.01f;
			speed3 -= 0.01f;
			printf("clicked at (%d, %d)\n", x, y);

	}



	glutPostRedisplay();
}





void sound()
{

    PlaySound("thundering.wav", NULL, SND_ASYNC|SND_LOOP);
    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Sea_Beach");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutSpecialFunc(SpecialInput);

   //glutMouseFunc(handleMouse1);
   //glutKeyboardFunc(handleKeypress1);
   //glutMouseFunc(handleMouse);
   glutTimerFunc(100, update, 0);
   glutTimerFunc(100, update1, 0);
   glutTimerFunc(400, update2, 0);
   glutTimerFunc(10, update3, 0);
   glutTimerFunc(10, update4, 0);
   glutTimerFunc(10, update5, 0);
   //glutTimerFunc(10, update4, 0);
   //glutTimerFunc(10, update5, 0);
   //glutTimerFunc(1000, Day, 2);
   //glutTimerFunc(3500, Night, 0);
   sound();
   glutMainLoop();
   return 0;
}
