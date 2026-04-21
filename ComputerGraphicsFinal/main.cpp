#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;

bool scenarioELAHI658 = true;


/// **************************************************************************************************************************************************
/// ******************************************************** >>> ELAHI658 - SADI  <<< ************************************************************************
/// **************************************************************************************************************************************************
bool isDay = true;

/// #############  Circle  #############
void circle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

void halfCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

/// #############  Sun  #############
float moveSun = 0.0f;
float sunSpeed =0.3f;
float savedSunSpeed = 0.0f;
bool sunPaused = false;

void sun()
{
    if(isDay)
    {
        glPushMatrix();
        glTranslatef(moveSun, 0, 0);
        glColor3f(1,1,0);
        circle(50,650,35);
        glPopMatrix();
    }
}

void updateSun(int value)
{
    if(!sunPaused)
    {
        moveSun += sunSpeed;
        if (moveSun > 1050)
        {
            moveSun = -200;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, updateSun, 0);
}

/// ############# Moon #############
float moveMoon = 0;
float moonSpeed =0.3f;
float savedMoonSpeed = 0.0f;
bool moonPaused = false;

void moon()
{
    if(!isDay)
    {
        glPushMatrix();
        glTranslatef(moveMoon, 0, 0);

        glColor3f(1,1,1);
        circle(850,650,40);

        glColor3f(0.10f, 0.13f, 0.22f);
        circle(860,660,40);
        glPopMatrix();
    }
}

void updateMoon(int value)
{
    if(!moonPaused)
    {
        moveMoon -= moonSpeed;
        if (moveMoon < -940)
        {
            moveMoon = 200;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, updateMoon, 0);
}

/// #############  SKY  #############
void sky()
{
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.37f, 0.82f, 0.94f);
    else
        glColor3f(0.10f, 0.13f, 0.22f);

    glVertex2f(0,   200);
    glVertex2f(1000,200);
    glVertex2f(1000,700);
    glVertex2f(0,   700);
    glEnd();
}

/// #############  Cloud  #############

float V_moveCloud1 = 0.0f;
float V_cloudSpeed1 =1.0f;
float V_savedCloudSpeed1 = 0.0f;
bool V_cloudPaused1 = false;

float V_moveCloud2 = 0.0f;
float V_cloudSpeed2 =1.0f;
float V_savedCloudSpeed2 = 0.0f;
bool V_cloudPaused2 = false;

float V_moveCloud3 = 0.0f;
float V_cloudSpeed3 =1.0f;
float V_savedCloudSpeed3 = 0.0f;
bool V_cloudPaused3 = false;

float V_moveCloud4 = 0.0f;
float V_cloudSpeed4 =1.0f;
float V_savedCloudSpeed4 = 0.0f;
bool V_cloudPaused4 = false;

void V_cloud1()
{
    glPushMatrix();
    glTranslatef(V_moveCloud1, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 200, y = 650, r = 20;
    circle(x,    y, r);
    circle(x-25, y+5, r);
    circle(x+25, y+5, r);
    circle(x-10, y+20, r-3);
    circle(x+10, y+20, r-3);

    glPopMatrix();
}

void V_cloud2()
{
    glPushMatrix();
    glTranslatef(V_moveCloud2, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    circle(337,640,18);
    circle(365,640,20);
    circle(390,640,18);
    circle(350,632,20);
    circle(375,632,20);
    circle(355,648,20);
    circle(375,648,20);

    glPopMatrix();
}

void V_cloud3()
{
    glPushMatrix();
    glTranslatef(V_moveCloud3, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 700, y = 650, r = 20;
    circle(x, y-15, r);
    circle(x+25, y-10, r);
    circle(x-25, y-10, r);
    circle(x-50, y, r);
    circle(x+50, y, r);
    circle(x+30, y+15, r+5);
    circle(x, y+25, r+5);
    circle(x-30, y+15, r+5);

    glBegin(GL_QUADS);
    glVertex2f(650,630);
    glVertex2f(750,630);
    glVertex2f(750,670);
    glVertex2f(650,670);
    glEnd();

    glPopMatrix();
}

void V_cloud4()
{
    glPushMatrix();
    glTranslatef(V_moveCloud4, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);
    circle(830,640,20);
    circle(860,638,22);
    circle(890,640,20);
    circle(845,652,20);
    circle(870,655,28);

    glPopMatrix();
}

void V_updateCloud1(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 -= V_cloudSpeed1+1;
            if (V_moveCloud1 < -250)
            {
                V_moveCloud1 = 860;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 += V_cloudSpeed1+1;
            if (V_moveCloud1 >1000)
            {
                V_moveCloud1 = -250;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud1, 0);
}

void V_updateCloud2(int value)
{
    if(!V_cloudPaused2)
    {
        V_moveCloud2 -= V_cloudSpeed2+.3;
        if (V_moveCloud2 < -450)
        {
            V_moveCloud2 = 740;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(9, V_updateCloud2, 0);
}

void V_updateCloud3(int value)
{
    if(!V_cloudPaused3)
    {
        V_moveCloud3 -= V_cloudSpeed3;
        if (V_moveCloud3 < -800)
        {
            V_moveCloud3 = 420;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, V_updateCloud3, 0);
}

void V_updateCloud4(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 -= V_cloudSpeed4+1;
            if (V_moveCloud4 < -900)
            {
                V_moveCloud4 = 250;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 += V_cloudSpeed4+2;
            if (V_moveCloud4 >250)
            {
                V_moveCloud4 = -940;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud4, 0);
}

/// ##############################################################  Garden  ###############################################################
void garden()
{
    //Base
    if (isDay)
        glColor3f(0.0f, 0.5f, 0.0f);
    else
        glColor3f(0.1f, 0.3f, 0.1f);

    glBegin(GL_QUADS);
    glVertex2f(0,180);
    glVertex2f(1000,180);
    glVertex2f(1000,200);
    glVertex2f(0,200);
    glEnd();
    /// Triangle Tree
    int shift = 70;

    for(int i = 0; i< 67; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(0.702,0.333,0.224);
        glVertex2f(15 + shift * i,205);
        glVertex2f(25 + shift * i,205);
        glVertex2f(25 + shift * i,220);
        glVertex2f(15 + shift * i,220);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0,0.32,0.004);

        glVertex2f(0  + shift * i,220);
        glVertex2f(40 + shift * i,220);
        glVertex2f(20 + shift * i,230);

        glVertex2f(10  + shift * i,225);
        glVertex2f(30 + shift * i,225);
        glVertex2f(20 + shift * i,235);

        glVertex2f(10  + shift * i,230);
        glVertex2f(30 + shift * i,230);
        glVertex2f(20 + shift * i,240);

        glEnd();

        /// Cloud shape tree
        if (isDay)
            glColor3f(0.0f, 0.5f, 0.0f);
        else
            glColor3f(0.1f, 0.3f, 0.1f);

        for(int i = 0; i<1000; i+=50)
        {
            halfCircle(i+20,190,25);
        }
    }
}

/// ##############################################################  Train  ###############################################################
float moveTrain = 0.0f;
float trainSpeed =1.0f;
float savedTrainSpeed = 0.0f;
bool trainPaused = false;

void train()
{
    glPushMatrix();
    glTranslatef(moveTrain, 0.0f, 0.0f);

    // Main body
    if (isDay)
        glColor3f(0.70f, 0.20f, 0.20f);
    else
        glColor3f(0.50f, 0.18f, 0.18f);

    glBegin(GL_POLYGON);
    glVertex2f(300.0f, 290.0f);
    glVertex2f(720.0f, 290.0f);
    glVertex2f(720.0f, 335.0f);
    glVertex2f(680.0f, 355.0f);
    glVertex2f(320.0f, 355.0f);
    glVertex2f(300.0f, 345.0f);
    glEnd();

    //Top stripe above windows
    if (isDay)
        glColor3f(0.20f, 0.70f, 0.18f);
    else
        glColor3f(0.15f, 0.35f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2f(310.0f, 340.0f);
    glVertex2f(690.0f, 340.0f);
    glVertex2f(690.0f, 345.0f);
    glVertex2f(310.0f, 345.0f);
    glEnd();

    // Outline for top stripe
    glColor3f(0.05f, 0.05f, 0.05f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(310.0f, 340.0f);
    glVertex2f(690.0f, 340.0f);
    glVertex2f(690.0f, 345.0f);
    glVertex2f(310.0f, 345.0f);
    glEnd();

    // === Bottom stripe below windows ===
    if (isDay)
    {
        glColor3f(0.95f, 0.12f, 0.18f);
    }
    else
    {
        glColor3f(0.55f, 0.15f, 0.15f);
        glBegin(GL_QUADS);
        glVertex2f(310.0f, 293.5f);
        glVertex2f(700.0f, 293.5f);
        glVertex2f(700.0f, 298.5f);
        glVertex2f(310.0f, 298.5f);
        glEnd();
    }

    // Outline for bottom stripe
    glColor3f(0.05f, 0.05f, 0.05f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(310.0f, 293.5f);
    glVertex2f(700.0f, 293.5f);
    glVertex2f(700.0f, 298.5f);
    glVertex2f(310.0f, 298.5f);
    glEnd();

    // === Window row ===
    float wx = 340.0f;
    for (int i = 0; i < 6; ++i)
    {
        // window fill
        if (isDay)
            glColor3f(0.92f, 0.98f, 1.0f);
        else
            glColor3f(0.95f, 0.94f, 0.65f);

        glBegin(GL_QUADS);
        glVertex2f(wx, 305.0f);
        glVertex2f(wx + 52.0f, 305.0f);
        glVertex2f(wx + 52.0f, 333.0f);
        glVertex2f(wx, 333.0f);
        glEnd();

        // window frame
        glColor3f(0.06f, 0.06f, 0.06f);
        glLineWidth(4.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(wx, 305.0f);
        glVertex2f(wx + 52.0f, 305.0f);
        glVertex2f(wx + 52.0f, 333.0f);
        glVertex2f(wx, 333.0f);
        glEnd();

        wx += 60.0f;
    }

    //   cabin
    if (isDay)
        glColor3f(0.38f, 0.84f, 1.0f);
    else
        glColor3f(0.18f, 0.64f, 0.80f);
    glBegin(GL_POLYGON);
    glVertex2f(300.0f, 305.0f);
    glVertex2f(318.0f, 315.0f);
    glVertex2f(318.0f, 332.0f);
    glVertex2f(300.0f, 340.0f);
    glEnd();

    // Front glass
    if (isDay)
        glColor3f(0.02f, 0.12f, 0.20f);
    else
        glColor3f(0.98f, 0.92f, 0.30f);
    glBegin(GL_POLYGON);
    glVertex2f(305.0f, 310.0f);
    glVertex2f(316.0f, 315.0f);
    glVertex2f(316.0f, 328.0f);
    glVertex2f(305.0f, 329.0f);
    glEnd();

    // Front headlight
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(298.0f, 300.0f);
    glVertex2f(305.0f, 300.0f);
    glVertex2f(305.0f, 305.0f);
    glVertex2f(298.0f, 305.0f);
    glEnd();

    //Back light (yellow square at rear)
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(715.0f, 300.0f);
    glVertex2f(720.0f, 300.0f);
    glVertex2f(720.0f, 308.0f);
    glVertex2f(715.0f, 308.0f);
    glEnd();

    // Back bumper trim
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(710.0f, 290.0f);
    glVertex2f(720.0f, 290.0f);
    glVertex2f(720.0f, 296.0f);
    glVertex2f(710.0f, 296.0f);
    glEnd();

    //Small underbody shadow
    glColor3f(0.08f, 0.08f, 0.08f);
    glBegin(GL_QUADS);
    glVertex2f(310.0f, 284.5f);
    glVertex2f(700.0f, 284.5f);
    glVertex2f(700.0f, 292.0f);
    glVertex2f(310.0f, 292.0f);
    glEnd();

    glPopMatrix();
}

void updateTrain(int value)
{
    if (!trainPaused)
    {
        moveTrain -= trainSpeed;
        if (moveTrain < -800.0f)
        {
            moveTrain = 750.0f;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, updateTrain, 0);
}


/// ##############################################################  Flyover  ###############################################################
void flyOver()
{
    ///Pillar
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);
    for(int x = 50; x<1000; x+=100)
    {
        glVertex2f(x,   205);
        glVertex2f(x+15,205);
        glVertex2f(x+15,275);
        glVertex2f(x,   275);
    }
    glEnd();

    /// Pillar upper box
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_TRIANGLES);
    for(int x = 40; x<1000; x+=100)
    {
        glVertex2f(x,     275);
        glVertex2f(x+35,  275);
        glVertex2f(x+15,255);
    }
    glEnd();

    if(isDay)
        glColor3f(0.80f, 0.80f, 0.80f);
    else
        glColor3f(.4,.4,.4);

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(0,   275);
    glVertex2f(1000,275);
    glEnd();

    ///Bridge body
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);
    glVertex2f(0,   277);
    glVertex2f(1000,277);
    glVertex2f(1000,288);
    glVertex2f(0,   288);
    glEnd();
}

/// ##############################################################  Road  ###############################################################
void road()
{
    if (isDay)
        glColor3f(.37f, .37f, .37f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    //Base Gray Color
    glBegin(GL_QUADS);
    glVertex2f(0,   0);
    glVertex2f(1000,0);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Base white line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0,   40);
    glVertex2f(1000,40);
    glEnd();

    //Main Road
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.15f, 0.15f, 0.15f);
    else
        glColor3f(0,0,0);

    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Upper white line of the road
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glEnd();

    //Upper gray color
    if (isDay)
        glColor3f(0.51f, 0.51f, 0.51f);
    else
        glColor3f(0.25f, 0.25f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,173);
    glVertex2f(0,   173);
    glEnd();

    //Road dash line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 0; x<1000; x+=60)
    {
        glVertex2f(x,   102);
        glVertex2f(x+30,102);
    }
    glEnd();
}

/// ##############################################################  Bus  ###################################################################
float V_moveBus = 0.0f;
float V_busSpeed =1.0f;
float V_savedBusSpeed = 0.0f;
float V_busTireAngle = 0.0f;
bool V_busPaused = false;

void bus()
{
    glPushMatrix();
    glTranslatef(V_moveBus, 0, 0);

    // --- BODY & LIGHTS (No Changes here) ---
    glBegin(GL_QUADS);
    if (isDay) glColor3f(1.00f, 0.60f, 0.29f);
    else       glColor3f(0.70f, 0.35f, 0.20f);

    glVertex2f(400, 130); glVertex2f(550, 130);
    glVertex2f(550, 190); glVertex2f(400, 190);

    glVertex2f(550, 130); glVertex2f(570, 130);
    glVertex2f(570, 160); glVertex2f(550, 190);
    glEnd();

    // FRONT Light
    if(isDay) glColor3f(1,1,1); else glColor3f(1,1,0);
    glBegin(GL_QUADS);
    glVertex2f(565, 135); glVertex2f(570, 135);
    glVertex2f(570, 142); glVertex2f(565, 142);
    if(!isDay) {
        glColor3f(1,1,.6);
        glVertex2f(570, 135); glVertex2f(640, 125);
        glVertex2f(640, 152); glVertex2f(570, 142);
    }
    // REAR LIGHT
    if(isDay) glColor3f(1,1,1); else glColor3f(1,0,0);
    glVertex2f(400, 135); glVertex2f(405, 135);
    glVertex2f(405, 142); glVertex2f(400, 142);
    glEnd();

    // WINDOWS
    if (isDay) glColor3f(0.92f, 1.0f, 0.996f); else glColor3f(1,1,.6);
    glBegin(GL_QUADS);
    glVertex2f(410, 160); glVertex2f(530, 160);
    glVertex2f(530, 180); glVertex2f(410, 180);
    glEnd();

    glColor3f(1.00f, 0.60f, 0.29f);
    glLineWidth(4);
    glBegin(GL_LINES);
    for(int x = 432; x<530; x+=25) {
        glVertex2f(x,160); glVertex2f(x,180);
    }
    glEnd();

    if (isDay) glColor3f(0.92f, 1.0f, 0.996f); else glColor3f(1,1,.6);
    glBegin(GL_QUADS);
    glVertex2f(533, 180); glVertex2f(550, 180);
    glVertex2f(565, 150); glVertex2f(533, 160);
    glEnd();

    // ==========================================
    // FIX: WHEELS (Logic corrected)
    // ==========================================

    // --- REAR TIRE ---
    glColor3f(0,0,0);
    halfCircle(425,130,12); // Fender

    glPushMatrix();
    glTranslatef(425, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-425, -130, 0);

    // 1. Tire Body
    if (isDay) glColor3f(0.8f, 0.8f, 0.8f);
    else       glColor3f(0.5f, 0.5f, 0.5f);
    circle(425,130,11); // <--- MOVED OUTSIDE ELSE

    // 2. Rim / Hubcap
    if (isDay) glColor3f(1.0f, 1.0f, 1.0f);
    else       glColor3f(0.7f, 0.7f, 0.7f);
    circle(425,130,5);  // <--- MOVED OUTSIDE ELSE

    // 3. Spokes
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(414,130); glVertex2f(436,130);
    glEnd();
    glPopMatrix();

    // --- FRONT TIRE ---
    glColor3f(0,0,0);
    halfCircle(540,130,12); // Fender

    glPushMatrix();
    glTranslatef(540, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-540, -130, 0);

    // 1. Tire Body
    if (isDay) glColor3f(0.8f, 0.8f, 0.8f);
    else       glColor3f(0.5f, 0.5f, 0.5f);
    circle(540,130,11); // <--- MOVED OUTSIDE ELSE

    // 2. Rim / Hubcap
    if (isDay) glColor3f(1.0f, 1.0f, 1.0f);
    else       glColor3f(0.7f, 0.7f, 0.7f);
    circle(540,130,5);  // <--- MOVED OUTSIDE ELSE

    // 3. Spokes
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(529,130); glVertex2f(551,130);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

void V_updateBus(int value)
{
    if(!V_busPaused)
    {
        V_moveBus += V_busSpeed+1;
        if (V_moveBus > 700)
        {
            V_moveBus = -550;
        }
        V_busTireAngle -= 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateBus, 0);


}
/// ######################################################## Cargo Track ########################################################
float V_moveCargo = 0.0f;
float V_cargoSpeed =3.0f;
float V_savedCargoSpeed = 0.0f;
float V_cargoTireAngle = 0.0f;
bool V_cargoPaused = false;

void cargoTruck()
{
    glPushMatrix();
    glTranslatef(V_moveCargo, 0, 0);

    /// Head and Body joint
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_QUADS);
    glVertex2f(760, 73);
    glVertex2f(730, 73);
    glVertex2f(730, 110);
    glVertex2f(760, 83);
    glEnd();

    ///  ********> Body <********
    if (isDay)
        glColor3f(0.51f, 0.86f, 0.92f);
    else
        glColor3f(0.22f, 0.46f, 0.55f);

    glBegin(GL_QUADS);
    glVertex2f(900, 83);
    glVertex2f(750, 83);
    glVertex2f(750, 150);
    glVertex2f(900, 150);
    glEnd();


    /// Head
    if (isDay)
        glColor3f(0.30f, 0.82f, 0.87f);
    else
        glColor3f(0.15f, 0.42f, 0.48f);

    /// upper quad
    glBegin(GL_QUADS);
    glVertex2f(745, 138);
    glVertex2f(715, 138);
    glVertex2f(690, 113);
    glVertex2f(745, 113);

    if (isDay)
        glColor3f(0.69f, 0.92f, 0.95f);
    else
        glColor3f(0.32f, 0.55f, 0.65f);

    glVertex2f(690, 113);
    glVertex2f(693, 111);
    glVertex2f(713, 132);
    glVertex2f(711, 135);

    if (isDay)
        glColor3f(0.30f, 0.82f, 0.87f);
    else
        glColor3f(0.15f, 0.42f, 0.48f);

    /// down quad
    glVertex2f(745, 75);
    glVertex2f(690, 70);
    glVertex2f(690, 113);
    glVertex2f(745, 113);

    glEnd();

    if (isDay)
        glColor3f(0.07f, 0.64f, 0.70f);
    else
        glColor3f(0.04f, 0.38f, 0.50f);

    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(740, 133);
    glVertex2f(717, 133);

    glVertex2f(740, 134);
    glVertex2f(740, 87);

    glVertex2f(740, 87);
    glVertex2f(720, 87);

    glVertex2f(720, 87);
    glVertex2f(710, 80);

    glVertex2f(710, 80);
    glVertex2f(693, 83);

    glVertex2f(717, 133);
    glVertex2f(693, 110);

    glVertex2f(693, 110);
    glVertex2f(693, 83);

    glEnd();

    /// window glass
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(718, 130);
    glVertex2f(737, 130);
    glVertex2f(737, 105);
    glVertex2f(697, 100);
    glVertex2f(697, 110);
    glEnd();

    /// inner glass
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(0.60f, 0.75f, 0.78f);

    glBegin(GL_POLYGON);
    glVertex2f(720, 128);
    glVertex2f(735, 128);
    glVertex2f(735, 107);
    glVertex2f(699, 102);
    glVertex2f(701, 110);
    glEnd();

    ///******> door holder
    if (isDay)
        glColor3f(0.1f, 0.1f, 0.4f);
    else
        glColor3f(0.05f, 0.05f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(735, 102);
    glVertex2f(735, 98);
    glVertex2f(727, 98);
    glVertex2f(727, 102);
    glEnd();

    /// *********>  REAR Light  <***********
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,0,0);

    glBegin(GL_QUADS);
    glVertex2f(895, 78);
    glVertex2f(900, 78);
    glVertex2f(900, 90);
    glVertex2f(895, 90);
    glEnd();


    /// *********>  FRONT Light  <***********
    if (isDay)
        glColor3f(1.0f, 1.0f, 0.0f);
    else
        glColor3f(0.8f, 0.8f, 0.2f);

    glBegin(GL_QUADS);
    glVertex2f(689, 82);
    glVertex2f(695, 85);
    glVertex2f(695, 89);
    glVertex2f(689, 89);

    if (isDay)
        glColor3f(1.0f, 0.68f, 0.016f);
    else
        glColor3f(0.8f, 0.5f, 0.01f);

    glVertex2f(689, 94);
    glVertex2f(695, 95);
    glVertex2f(695, 89);
    glVertex2f(689, 89);

    glEnd();

    if(!isDay)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.68f, 0.016f);
        glVertex2f(689, 94);
        glVertex2f(600, 97);
        glVertex2f(600, 50);
        glVertex2f(689, 84);

        glEnd();
    }

    /// Under The Body Black bar
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_QUADS);
    glVertex2f(900, 73);
    glVertex2f(730, 73);
    glVertex2f(725, 83);
    glVertex2f(900, 83);

    glEnd();

    /// Front Black Bumper
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_POLYGON);
    glVertex2f(690, 70);
    glVertex2f(730, 70);
    glVertex2f(730, 75);
    glVertex2f(695, 75);
    glVertex2f(695, 85);
    glVertex2f(685, 80);

    glEnd();

    /// ********> body design <********
    if (isDay)
        glColor3f(0.31f, 0.81f, 0.88f);
    else
        glColor3f(0.15f, 0.45f, 0.55f);

    glBegin(GL_QUADS);

    for(int x = 895; x>760; x-=12)
    {
        glVertex2f(x, 88);
        glVertex2f(x-7, 88);
        glVertex2f(x-7, 145);
        glVertex2f(x, 145);
    }
    glEnd();

    /// Body sky blue 3 quads
    if (isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.4f, 0.6f, 0.7f);

    glBegin(GL_QUADS);
    glVertex2f(755, 145);
    glVertex2f(775, 145);
    glVertex2f(810, 88);
    glVertex2f(790, 88);

    glVertex2f(785, 145);
    glVertex2f(825, 145);
    glVertex2f(860, 88);
    glVertex2f(820, 88);

    glVertex2f(835, 145);
    glVertex2f(860, 145);
    glVertex2f(895, 88);
    glVertex2f(870, 88);

    glEnd();

    /// blue design shadow
    /// side shadow
    if (isDay)
        glColor3f(0.05f, 0.64f, 0.69f);
    else
        glColor3f(0.02f, 0.3f, 0.35f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 889; x>750; x-=12)
    {
        glVertex2f(x, 88);
        glVertex2f(x, 145);
    }
    glEnd();

    /// body up-down shadow
    if (isDay)
        glColor3f(0.05f, 0.64f, 0.69f);
    else
        glColor3f(0.02f, 0.28f, 0.32f);

    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x = 895; x>760; x-=12)
    {
        glVertex2f(x, 88);
        glVertex2f(x-7, 88);

        glVertex2f(x, 145);
        glVertex2f(x-7, 145);
    }
    glEnd();

    /// REAR TIRE
    if (isDay)
        glColor3f(0.26f, 0.26f, 0.26f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(865,69,14);

    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.8f, 0.8f, 0.8f);

    halfCircle(865,69,12);

    glPushMatrix();
    glTranslatef(865, 69, 0);
    glRotatef(V_cargoTireAngle, 0.0, 0.0, 1.0);  // Rotate only the tire
    glTranslatef(-865, -69, 0);

    if (isDay)
        glColor3f(0.7f, 0.7f, 0.6f);
    else
        glColor3f(0.4f, 0.4f, 0.35f);

    circle(865,69,12);

    if (isDay)
        glColor3f(0.70f, 0.73f, 0.73f);
    else
        glColor3f(0.45f, 0.48f, 0.48f);

    circle(865,69,8);

    if (isDay)
        glColor3f(0.57f, 0.60f, 0.61f);
    else
        glColor3f(0.3f, 0.32f, 0.33f);

    circle(865,69,7);

    if (isDay)
        glColor3f(0.89f, 0.89f, 0.89f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(865,69,5);

    if (isDay)
        glColor3f(0.60f, 0.60f, 0.60f);
    else
        glColor3f(0.35f, 0.35f, 0.35f);

    circle(865,69,4);

    glPopMatrix();

    /// FRONT TIRE

    if (isDay)
        glColor3f(0.26f, 0.26f, 0.26f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(725,69,14);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.8f, 0.8f, 0.8f);

    halfCircle(725,69,12);

    glPushMatrix();
    glTranslatef(725, 69, 0);
    glRotatef(V_cargoTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-725, -69, 0);

    // Front Tire
    if (isDay)
        glColor3f(0.7f, 0.7f, 0.6f);
    else
        glColor3f(0.45f, 0.45f, 0.4f);

    circle(725,69,12);

    if (isDay)
        glColor3f(0.70f, 0.73f, 0.73f);
    else
        glColor3f(0.45f, 0.48f, 0.48f);

    circle(725,69,8);

    if (isDay)
        glColor3f(0.57f, 0.60f, 0.61f);
    else
        glColor3f(0.35f, 0.38f, 0.39f);

    circle(725,69,7);

    if (isDay)
        glColor3f(0.89f, 0.89f, 0.89f);
    else
        glColor3f(0.45f, 0.45f, 0.45f);

    circle(725,69,5);

    if (isDay)
        glColor3f(0.60f, 0.60f, 0.60f);
    else
        glColor3f(0.35f, 0.35f, 0.35f);

    circle(725,69,4);

    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(.5,.5,.5);

    glBegin(GL_TRIANGLES);
    glVertex2f(722,70);
    glVertex2f(728,70);
    glVertex2f(725,66);
    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void V_updateCargo(int value)
{
    if(!V_cargoPaused)
    {
        V_moveCargo -= V_cargoSpeed;
        if (V_moveCargo < -940)
        {
            V_moveCargo = 450;
        }
        V_cargoTireAngle += 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateCargo, 0);


}

/// ##############################################################  Road Side Wall  ###############################################################
void roadSideWall()
{
    if (isDay)
        glColor3f(0.839f, 0.443f, 0.235f);
    else
        glColor3f(0.42f, 0.22f, 0.13f);

    glBegin(GL_QUADS);
    glVertex2f(0,   170);
    glVertex2f(1000,170);
    glVertex2f(1000,190);
    glVertex2f(0,   190);
    glEnd();

    //Breaks Line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2f(0,   170);
    glVertex2f(1000,170);

    glVertex2f(0,   175);
    glVertex2f(1000,175);

    glVertex2f(0,   180);
    glVertex2f(1000,180);

    glVertex2f(0,   185);
    glVertex2f(1000,185);

    glVertex2f(0,   190);
    glVertex2f(1000,190);

    for(int x = 10; x<1000; x+=20)
    {
        glVertex2f(x,170);
        glVertex2f(x,175);

        glVertex2f(x+10,175);
        glVertex2f(x+10,180);

        glVertex2f(x,180);
        glVertex2f(x,185);

        glVertex2f(x+10,185);
        glVertex2f(x+10,190);
    }

    glEnd();

    //Upper 2 lines
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(0,   200);
    glVertex2f(1000,200);

    glVertex2f(0,   205);
    glVertex2f(1000,205);

    for(int i = 0; i< 1000; i+=45)
    {
        glLineWidth(1);
        glVertex2f(i, 190);
        glVertex2f(i, 205);

        glVertex2f(i+5, 190);
        glVertex2f(i+5, 205);
    }
    glEnd();

}

/// ####################################################################### Building ###########################################################
void building()
{
    /// 1st Building
    if(isDay)
        glColor3f(0.92f, 0.92f, 0.92f);
    else
        glColor3f(0.55f, 0.55f, 0.55f);

    // body
    glBegin(GL_QUADS);
    glVertex2f(10,  200);
    glVertex2f(100, 200);
    glVertex2f(100, 525);
    glVertex2f(10,  525);

    if(isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    // Top
    glVertex2f(6,   525);
    glVertex2f(104, 525);
    glVertex2f(104, 535);
    glVertex2f(6,   535);
    glEnd();

    // window
    glBegin(GL_QUADS);
    for(int x = 18; x<80; x+=27 )
    {
        for(int y = 500; y>200; y-=60)
        {
            if(isDay)
                glColor3f(1,1,1);
            else
                glColor3f(0.15f, 0.07f, 0.03f);

            glVertex2f(x-2,  y+7);
            glVertex2f(x+22, y+7);
            glVertex2f(x+22, y-20);
            glVertex2f(x-2,  y-20);

            if(isDay)
                glColor3f(0.52f, 0.78f, 0.96f);
            else
                glColor3f(1.0f, 1.0f, 0.5f);

            glVertex2f(x,  y+5);
            glVertex2f(x+20, y+5);
            glVertex2f(x+20, y-20);
            glVertex2f(x,  y-20);
        }
    }

    // Window white border
    if(isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_QUADS);
    for(int y = 480; y > 200; y -= 60 )
    {
        glVertex2f(5,   y   );
        glVertex2f(105, y   );
        glVertex2f(105, y-15);
        glVertex2f(5,   y-15);
    }
    glEnd();

    /// $$$$$$$$$$$$$$$$$$ 2nd Building $$$$$$$$$$$$$$
    glBegin(GL_QUADS);

    //body Left half
    if(isDay)
        glColor3f(0.90f, 0.80f, 0.69f);
    else
        glColor3f(0.45f, 0.40f, 0.35f);

    glVertex2f(90,  200);
    glVertex2f(135, 200);
    glVertex2f(135, 400);
    glVertex2f(90,  400);

    //right half
    if(isDay)
        glColor3f(0.83f, 0.73f, 0.63f);
    else
        glColor3f(0.50f, 0.45f, 0.40f);

    glVertex2f(135,  200);
    glVertex2f(180, 200);
    glVertex2f(180, 400);
    glVertex2f(135,  400);

    // Top
    if(isDay)
        glColor3f(0.45f, 0.24f, 0.13f);
    else
        glColor3f(0.25f, 0.15f, 0.10f);

    glVertex2f(90,  400);
    glVertex2f(180, 400);
    glVertex2f(165, 425);
    glVertex2f(105, 425);
    glEnd();

    // Left triangles
    if(isDay)
        glColor3f(0.90f, 0.80f, 0.69f);
    else
        glColor3f(0.45f, 0.40f, 0.35f);
    glBegin(GL_TRIANGLES);
    glVertex2f(135, 400);
    glVertex2f(115, 400);
    glVertex2f(135, 425);
    glEnd();

    // Right triangles
    if(isDay)
        glColor3f(0.83f, 0.73f, 0.63f);
    else
        glColor3f(0.50f, 0.45f, 0.40f);

    glBegin(GL_TRIANGLES);
    glVertex2f(135, 400);
    glVertex2f(155, 400);
    glVertex2f(135, 425);
    glEnd();

    // All border
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(88, 400);
    glVertex2f(115, 400);

    glVertex2f(115, 398);
    glVertex2f(135, 427);

    glVertex2f(135, 427);
    glVertex2f(155, 400);

    glVertex2f(153, 400);
    glVertex2f(182, 400);

    //body Lines
    glVertex2f(90, 340);
    glVertex2f(180,340);

    glVertex2f(90, 280);
    glVertex2f(180,280);

    glVertex2f(90, 220);
    glVertex2f(180,220);

    glEnd();

    //window
    //Outer quad
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int x = 100; x<180; x+=45)
    {
        for(int y = 385; y>200; y-=60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+25, y);
            glVertex2f(x+25, y-30);
            glVertex2f(x,    y-30);
        }
    }

    if(isDay)
        glColor3f(0.67f, 0.77f, 0.89f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    //inner quad
    for(int x = 102; x<180; x+=45)
    {
        for(int y = 382; y>200; y-=60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+21, y);
            glVertex2f(x+21, y-25);
            glVertex2f(x,    y-25);
        }
    }
    glEnd();

    // On window border
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x =100; x<180; x+=45)
        for(int y = 372; y>200; y-=60)
        {
            {
                glVertex2f(x,y);
                glVertex2f(x+25,y);

                glVertex2f(x+12.5,y+10);
                glVertex2f(x+12.5,y);
            }
        }

    glEnd();

    /// 3rd Building
    // Left side
    if (isDay)
        glColor3f(0.84f, 0.30f, 0.37f);
    else
        glColor3f(0.50f, 0.15f, 0.20f);

    glBegin(GL_QUADS);
    glVertex2f(190, 200);
    glVertex2f(235, 200);
    glVertex2f(235, 480);
    glVertex2f(190, 480);

    // Right side
    if (isDay)
        glColor3f(0.90f, 0.45f, 0.50f);
    else
        glColor3f(0.60f, 0.25f, 0.30f);

    glVertex2f(235, 200);
    glVertex2f(280, 200);
    glVertex2f(280, 480);
    glVertex2f(235, 480);

    //Top bar
    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);

    glVertex2f(185, 490);
    glVertex2f(285, 490);
    glVertex2f(285, 475);
    glVertex2f(185, 475);

    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);
    ;
    for(int y = 410; y>200; y-=70)
    {
        glVertex2f(185, y);
        glVertex2f(285, y);
        glVertex2f(285, y-10);
        glVertex2f(185, y-10);
    }

    glEnd();

    ///     window
    //   white border
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int x = 198; x < 280; x += 47)
    {
        for(int y=454; y>220; y-=70)
        {
            glVertex2f(x,    y);
            glVertex2f(x+26, y);
            glVertex2f(x+26, y-34);
            glVertex2f(x,    y-34);
        }
    }
    glEnd();

    // blue
    if (isDay)
        glColor3f(0.36f, 0.54f, 0.66f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    for(int x = 202; x < 280; x += 47)
    {
        for(int y=450; y>220; y-=70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x,    y);
            glVertex2f(x+18, y);
            glVertex2f(x+18, y-27);
            glVertex2f(x,    y-27);
            glEnd();
        }
    }
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 198; x < 280; x += 47)
        for(int y=454; y>220; y-=70)
        {
            glVertex2f(x+13, y);
            glVertex2f(x+13, y-32);

            glVertex2f(x, y-13);
            glVertex2f(x+26, y-13);

            glVertex2f(x,    y-22);
            glVertex2f(x+26, y-22);

        }

    glEnd();

    ///              ***> 4th Building <***
    if (isDay)
        glColor3f(0.36f, 0.54f, 0.66f);
    else
        glColor3f(0.20f, 0.35f, 0.45f);

    glBegin(GL_QUADS);
    glVertex2f(300, 200);
    glVertex2f(400, 200);
    glVertex2f(400, 550);
    glVertex2f(300, 510);

    //Top White
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glVertex2f(299, 495);
    glVertex2f(401, 540);
    glVertex2f(401, 555);
    glVertex2f(299, 510);

    // Body white quard
    glVertex2f(300, 470);
    glVertex2f(400, 470);
    glVertex2f(400, 455);
    glVertex2f(300, 455);
    glEnd();

    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(320, 200);
    glVertex2f(320, 510);

    glVertex2f(340, 200);
    glVertex2f(340, 520);

    glVertex2f(360, 200);
    glVertex2f(360, 530);

    glVertex2f(380, 200);
    glVertex2f(380, 535);

    if (isDay)
        glColor3f(0.30f, 0.42f, 0.51f);
    else
        glColor3f(0.18f, 0.28f, 0.36f);


    for(int y = 455; y> 200; y-=30)
    {
        glVertex2f(300, y);
        glVertex2f(400, y);
    }
    glVertex2f(312, 500);
    glVertex2f(400, 500);


    glEnd();

    /// 6th Building
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.94f, 0.69f, 0.35f);
    else
        glColor3f(0.65f, 0.45f, 0.20f);

    //Body
    glVertex2f(550, 200);
    glVertex2f(640, 200);
    glVertex2f(640, 400);
    glVertex2f(550, 400);

    //top red
    if(isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.6f, 0.0f, 0.0f);

    glVertex2f(550, 415);
    glVertex2f(640, 415);
    glVertex2f(640, 400);
    glVertex2f(550, 400);
    glEnd();

    if(isDay)
        glColor3f(0.94f, 0.69f, 0.35f);
    else
        glColor3f(0.65f, 0.45f, 0.20f);

    for(int x = 555; x<640; x+=13)
        circle(x,400,7);

    //body red lines
    if(isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.6f, 0.0f, 0.0f);

    glLineWidth(4);
    glBegin(GL_LINES);

    glVertex2f(550, 290);
    glVertex2f(640, 290);

    glVertex2f(550, 350);
    glVertex2f(640, 350);

    glVertex2f(550, 230);
    glVertex2f(640, 230);
    glEnd();

    // Window white color
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glBegin(GL_QUADS);
    for(int x = 561; x<640; x+=40 )
    {
        for(int y = 395; y>200; y-=60)
        {

            glVertex2f(x,  y);
            glVertex2f(x+25, y);
            glVertex2f(x+25, y-30);
            glVertex2f(x,  y-30);
        }
    }
    // window blue glass
    if(isDay)
        glColor3f(0.44f, 0.63f, 0.78f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    for(int x = 561; x<640; x+=40 )
    {
        for(int y = 395; y>200; y-=60)
        {
            glVertex2f(x+3,  y-3);
            glVertex2f(x+22, y-3);
            glVertex2f(x+22, y-27);
            glVertex2f(x+3,  y-27);
        }
    }
    glEnd();

    /// Window white line
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 561; x<640; x+=40)
    {
        for(int y = 385; y>200; y-=60)
        {
            glVertex2f(x,  y);
            glVertex2f(x+22, y);

            glVertex2f(x+12, y);
            glVertex2f(x+12, y-20);
        }
    }
    glEnd();

    /// 5th Building
    if (isDay)
        glColor3f(0.96f, 0.96f, 0.96f);
    else
        glColor3f(0.70f, 0.70f, 0.70f);

    glBegin(GL_QUADS);
    //Main Body
    glVertex2f(420, 200);
    glVertex2f(550, 200);
    glVertex2f(550, 440);
    glVertex2f(420, 440);

    //Upper box
    glVertex2f(440, 440);
    glVertex2f(530, 440);
    glVertex2f(530, 480);
    glVertex2f(440, 480);

    glVertex2f(450, 495);
    glVertex2f(520, 495);
    glVertex2f(520, 505);
    glVertex2f(450, 505);

    glVertex2f(460, 505);
    glVertex2f(510, 505);
    glVertex2f(510, 515);
    glVertex2f(460, 515);

    //Top Bar
    glVertex2f(470, 515);
    glVertex2f(500, 515);
    glVertex2f(500, 525);
    glVertex2f(470, 525);

    glEnd();

    //Body white bar
    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(415, 420);
    glVertex2f(555, 420);
    glVertex2f(555, 440);
    glVertex2f(415, 440);
    glEnd();

    // border shadow
    if (isDay)
        glColor3f(0.90f, 0.90f, 0.90f);
    else
        glColor3f(0.60f, 0.60f, 0.60f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(417, 420);
    glVertex2f(553, 420);
    glEnd();

    //top white
    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(435, 495);
    glVertex2f(535, 495);
    glVertex2f(535, 480);
    glVertex2f(435, 480);
    glEnd();

    // border shadow
    if (isDay)
        glColor3f(0.90f, 0.90f, 0.90f);
    else
        glColor3f(0.60f, 0.60f, 0.60f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(437, 479);
    glVertex2f(533, 479);
    glEnd();

    //blue glass
    if (isDay)
        glColor3f(0.38f, 0.54f, 0.66f);
    else
        glColor3f(0.20f, 0.35f, 0.45f);

    //body
    glBegin(GL_QUADS);
    for(int x = 435; x<550; x+=40)
    {
        glVertex2f(x, 200);
        glVertex2f(x+20, 200);
        glVertex2f(x+20, 400);
        glVertex2f(x, 400);
    }

    //top
    for(int x = 450; x<520; x+=20)
    {
        glVertex2f(x,    470);
        glVertex2f(x+11, 470);
        glVertex2f(x+11, 440);
        glVertex2f(x,    440);
    }
    glEnd();

    glColor3f(0.38f, 0.54f, 0.66f);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2f(455, 499);
    glVertex2f(515, 499);

    glVertex2f(465, 509);
    glVertex2f(505, 509);

    glVertex2f(475, 519);
    glVertex2f(495, 519);

    glEnd();

    //Flag
    if(isDay)
        glColor3f(0.00f, 0.42f, 0.31f);
    else
        glColor3f(0.00f, 0.25f, 0.18f);

    glBegin(GL_QUADS);
    glVertex2f(485, 555);
    glVertex2f(510, 555);
    glVertex2f(510, 540);
    glVertex2f(485, 540);
    glEnd();

    if(isDay)
        glColor3f(0.96f, 0.16f, 0.25f);
    else
        glColor3f(0.6f, 0.1f, 0.15f);

    circle(497.5, 547.5, 4);

    // Bamboo
    if(isDay)
        glColor3f(0.83f, 0.65f, 0.42f);
    else
        glColor3f(0.55f, 0.45f, 0.30f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(485, 525);
    glVertex2f(485, 555);
    glEnd();



    /// 7th Building
    if (isDay)
        glColor3f(0.84f, 0.74f, 0.62f);
    else
        glColor3f(0.50f, 0.40f, 0.30f);

    //body
    glBegin(GL_QUADS);
    glVertex2f(640, 200);
    glVertex2f(720, 200);
    glVertex2f(720, 380);
    glVertex2f(640, 380);

    //window
    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int y = 373; y>200; y-=30)
    {
        glVertex2f(647, y);
        glVertex2f(713, y);
        glVertex2f(713, y-21);
        glVertex2f(647, y-21);
    }

    if (isDay)
        glColor3f(0.52f, 0.78f, 0.96f);
    else
        glColor3f(0.94f, 0.69f, 0.35f);

    for(int y = 370; y>200; y-=30)
    {
        glVertex2f(650, y);
        glVertex2f(710, y);
        glVertex2f(710, y-15);
        glVertex2f(650, y-15);
    }
    glEnd();

    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    // window lines
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x = 670; x<710; x+=20)
        for(int y = 370; y>200; y-=30)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-15);
        }
    glEnd();

    /// 8th Building
    if (isDay)
        glColor3f(0.39f, 0.30f, 0.32f);
    else
        glColor3f(0.19f, 0.15f, 0.16f);

    glBegin(GL_QUADS);
    glVertex2f(730, 200);
    glVertex2f(970, 200);
    glVertex2f(970, 430);
    glVertex2f(730, 430);
    glEnd();

    // top bar
    glColor3f(0.28f, 0.13f, 0.06f);
    glBegin(GL_QUADS);
    glVertex2f(725, 440);
    glVertex2f(975, 440);
    glVertex2f(975, 430);
    glVertex2f(725, 430);
    glEnd();

    //Window
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    //4 corner window
    glBegin(GL_QUADS);
    for(int x=759; x<950; x+=150)
        for(int y = 400; y>250; y-=120)
        {
            glVertex2f(x, y);
            glVertex2f(x+32, y);
            glVertex2f(x+32, y-40);
            glVertex2f(x, y-40);
        }
    // middle 2 window
    for(int x=743; x<950; x+=182)
    {
        glVertex2f(x,    340);
        glVertex2f(x+32, 340);
        glVertex2f(x+32, 300);
        glVertex2f(x,    300);
    }
    glEnd();

    //Window
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    //window white circle
    //4 corner
    for(int x = 759; x<940; x+=150)
        for(int y = 360; y>200; y-=120)
            for(int xx = x; xx<x+34; xx+=8)
                circle(xx,y,4);
    for(int x = 743; x<950; x+=182)
        for(int xx = x; xx<x+34; xx+=8)
            circle(xx,300,4);

    if(isDay)
        glColor3f(0.44f, 0.65f, 0.80f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    // blue glass
    for(int x=763; x<950; x+=150)
        for(int y = 397; y>250; y-=120)
        {
            glVertex2f(x,    y);
            glVertex2f(x+24, y);
            glVertex2f(x+24, y-34);
            glVertex2f(x,    y-34);
        }

    for(int x=747; x<950; x+=182)
    {
        glVertex2f(x,    337);
        glVertex2f(x+24, 337);
        glVertex2f(x+24, 303);
        glVertex2f(x,    303);
    }

    glEnd();

    // Lines of windows
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 775; x<940; x+=150)
        for(int y = 400; y>200; y-=120)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-40);
        }

    // Middle window lines
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 759; x<950; x+=182)
    {
        glVertex2f(x, 340);
        glVertex2f(x, 300);
    }

    glEnd();

    /// ***> 9th Building <***
    if (isDay)
        glColor3f(0.51f, 0.73f, 0.75f);
    else
        glColor3f(0.29f, 0.42f, 0.43f);

    glBegin(GL_QUADS);
    glVertex2f(800, 200);
    glVertex2f(850, 200);
    glVertex2f(850, 480);
    glVertex2f(800, 480);

    if (isDay)
        glColor3f(0.47f, 0.67f, 0.69f);
    else
        glColor3f(0.23f, 0.34f, 0.35f);

    glVertex2f(850, 200);
    glVertex2f(900, 200);
    glVertex2f(900, 480);
    glVertex2f(850, 480);

    // Top bar
    if (isDay)
        glColor3f(0.29f, 0.42f, 0.43f);
    else
        glColor3f(0.14f, 0.21f, 0.22f);

    glVertex2f(795, 490);
    glVertex2f(905, 490);
    glVertex2f(905, 475);
    glVertex2f(795, 475);

    if (isDay)
        glColor3f(0.29f, 0.42f, 0.43f);
    else
        glColor3f(0.14f, 0.21f, 0.22f);

    for (int y = 410; y > 200; y -= 70)
    {
        glVertex2f(800, y);
        glVertex2f(900, y);
        glVertex2f(900, y - 10);
        glVertex2f(800, y - 10);
    }

    glEnd();

// Window
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for (int x = 810; x < 900; x += 54)
    {
        for (int y = 450; y > 220; y -= 70)
        {
            glVertex2f(x, y);
            glVertex2f(x + 26, y);
            glVertex2f(x + 26, y - 30);
            glVertex2f(x, y - 30);
        }
    }
    glEnd();

    halfCircle(823, 450, 13);
    halfCircle(877, 450, 13);
    halfCircle(823, 380, 13);
    halfCircle(877, 380, 13);
    halfCircle(823, 310, 13);
    halfCircle(877, 310, 13);
    halfCircle(823, 240, 13);
    halfCircle(877, 240, 13);

// Red
    glColor3f(1, 0, 0);
    for (int x = 814; x < 900; x += 54)
    {
        for (int y = 450; y > 220; y -= 70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + 18, y);
            glVertex2f(x + 18, y - 27);
            glVertex2f(x, y - 27);
            glEnd();
        }
    }

    halfCircle(823, 450, 9);
    halfCircle(877, 450, 9);
    halfCircle(823, 380, 9);
    halfCircle(877, 380, 9);
    halfCircle(823, 310, 9);
    halfCircle(877, 310, 9);
    halfCircle(823, 240, 9);
    halfCircle(877, 240, 9);

    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 823; x<900; x+=54)
        for(int y = 460; y>200; y-=70)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-40);

            glVertex2f(x-13, y-12);
            glVertex2f(x+13, y-12);

            glVertex2f(x-13, y-25);
            glVertex2f(x+13, y-25);

        }
    glEnd();
}

float moveCar = 0.0f;
float carSpeed =1.0f;
float savedCarSpeed = 0.0f;
float carTireAngle = 0.0f;
bool carPaused = false;

void car()
{
    glPushMatrix();
    glTranslatef(moveCar, 0, 0);

    glBegin(GL_POLYGON);
    if (isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(100,125);
    glVertex2i(100,140);
    glVertex2i(105,150);
    glVertex2i(193,150);
    glVertex2i(205,145);
    glVertex2i(205,125);
    glEnd();

    /// ***> Light <***
    glBegin(GL_QUADS);
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,1,.7);
    /// Front light
    glVertex2i(200,128);
    glVertex2i(205,128);
    glVertex2i(205,135);
    glVertex2i(200,135);

    /// Rear light
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,0,0);

    glVertex2i(100,128);
    glVertex2i(105,128);
    glVertex2i(105,135);
    glVertex2i(100,135);

    /// Yellow light for night
    if(!isDay)
    {
        glColor3f(1,1,.7);
        glVertex2i(205,128);
        glVertex2i(260,115);
        glVertex2i(260,140);
        glVertex2i(205,135);

    }

    glEnd();

    glBegin(GL_POLYGON);
    if (isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(110,145);
    glVertex2i(121,168);
    glVertex2i(170,168);
    glVertex2i(190,145);

    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(123,150);
    glVertex2i(123,162);
    glVertex2i(145,162);
    glVertex2i(145,150);
    glEnd();


    glBegin(GL_QUADS);/////////////////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2i(125,152);
    glVertex2i(125,160);
    glVertex2i(143,160);
    glVertex2i(143,152);
    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(152,151);
    glVertex2i(152,162);
    glVertex2i(168,162);
    glVertex2i(177,151);
    glEnd();


    glBegin(GL_QUADS);/////////////////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    glVertex2i(154,149);
    glVertex2i(154,160);
    glVertex2i(166,160);
    glVertex2i(175,149);
    glEnd();




    //first car chakka/////////////////////////
    if (isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(125,125,10);


    if (isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(125,125,9);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(125,125,3);

    if (isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    circle(175,125,10);


    if (isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(175,125,9);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(175,125,3);

    glPopMatrix();
}
void updateCar(int value)
{
    if(!carPaused)
    {

        moveCar += carSpeed+1;
        if (moveCar > 900)
        {
            moveCar = -350;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(10, updateCar, 0);
}

void specialKeys(int key, int x, int y)
{
    //Day Mode Metro speed control
    if(isDay)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            trainSpeed += 0.2f;
            break;
        case GLUT_KEY_DOWN:
            trainSpeed -= 0.2f;
            if (trainSpeed < 0) trainSpeed = 0;
            break;
        }
    }
    //Night Mode Metro speed control
    if(!isDay)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            trainSpeed += 0.2f;
            break;
        case GLUT_KEY_DOWN:
            trainSpeed -= 0.2f;
            if (trainSpeed < 0) trainSpeed = 0;
            break;
        }
    }
//Sun Speed
    if(isDay)
    {
        switch (key)
        {
        case GLUT_KEY_RIGHT:
            sunSpeed += 0.2f;
            break;
        case GLUT_KEY_LEFT:
            sunSpeed -= 0.2f;
            if (sunSpeed < 0) sunSpeed = 0;
            break;
        }
    }
//Moon Speed
    if(!isDay)
    {
        switch (key)
        {
        case GLUT_KEY_RIGHT:
            moonSpeed += 0.2f;
            break;
        case GLUT_KEY_LEFT:
            moonSpeed -= 0.2f;
            if (moonSpeed < 0) moonSpeed = 0;
            break;
        }
    }
    //Cargoo Truck Speed
     if(!isDay)
    {
        switch (key)
        {
        case GLUT_KEY_PAGE_UP:
            V_cargoSpeed += 0.2f;
            break;
        case GLUT_KEY_PAGE_DOWN:
            V_cargoSpeed -= 0.2f;
            if (V_cargoSpeed < 0) V_cargoSpeed = 0;
            break;
        }
    }
     if(isDay)
    {
        switch (key)
        {
        case GLUT_KEY_PAGE_UP:
            V_cargoSpeed += 0.2f;
            break;
        case GLUT_KEY_PAGE_DOWN:
            V_cargoSpeed -= 0.2f;
            if (V_cargoSpeed < 0) V_cargoSpeed = 0;
            break;
        }
    }

}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        isDay = true;
        glutPostRedisplay();
    }

    if(key == 'n' || key == 'N')
    {
        isDay = false;
        glutPostRedisplay();
    }

    if (key == ' ')
    {
        /// Cargo Stop and Start
       V_cargoPaused = !V_cargoPaused;

       if(V_cargoPaused)
       {
           V_savedCargoSpeed = V_cargoSpeed;
           V_cargoSpeed = 0;
       }
       else
       {
           V_cargoSpeed = V_savedCargoSpeed;
       }

        /// Car Stop and Start
        carPaused = !carPaused;

        if(carPaused)
        {
            savedCarSpeed = carSpeed;
            carSpeed = 0;
        }
        else
        {
            carSpeed = savedCarSpeed;
        }

        /// Bus Stop and Start
        V_busPaused = !V_busPaused;

        if(V_busPaused)
        {
            V_savedBusSpeed = V_busSpeed;
            V_busSpeed = 0;
        }
        else
        {
            V_busSpeed = V_savedBusSpeed;
        }

        /// Train Stop and Start
        trainPaused = !trainPaused;

        if (trainPaused)
        {
            savedTrainSpeed = trainSpeed;
            trainSpeed = 0;
        }
        else
        {
            trainSpeed = savedTrainSpeed;
        }

        /// Cloud Stop and Start
        // Cloud 1
        V_cloudPaused1 = !V_cloudPaused1;

        if (V_cloudPaused1)
        {
            V_savedCloudSpeed1 = V_cloudSpeed1;
            V_cloudSpeed1 = 0;
        }
        else
        {
            V_cloudSpeed1 = V_savedCloudSpeed1;
        }

        // Cloud 2
        V_cloudPaused2 = !V_cloudPaused2;

        if (V_cloudPaused2)
        {
            V_savedCloudSpeed2 = V_cloudSpeed2;
            V_cloudSpeed2 = 0;
        }
        else
        {
            V_cloudSpeed2 = V_savedCloudSpeed2;
        }

        // Cloud 3
        V_cloudPaused3 = !V_cloudPaused3;

        if (V_cloudPaused3)
        {
            V_savedCloudSpeed3 = V_cloudSpeed3;
            V_cloudSpeed3 = 0;
        }
        else
        {
            V_cloudSpeed3 = V_savedCloudSpeed3;
        }

        // Cloud 4
        V_cloudPaused4 = !V_cloudPaused4;

        if (V_cloudPaused4)
        {
            V_savedCloudSpeed4 = V_cloudSpeed4;
            V_cloudSpeed4 = 0;
        }
        else
        {
            V_cloudSpeed4 = V_savedCloudSpeed4;
        }

        /// Sun Stop and Start
        sunPaused = !sunPaused;

        if (sunPaused)
        {
            savedSunSpeed = sunSpeed;
            sunSpeed = 0;
        }
        else
        {
            sunSpeed = savedSunSpeed;
        }

        /// Moon Stop and Start
        moonPaused = !moonPaused;

        if (moonPaused)
        {
            savedMoonSpeed = moonSpeed;
            moonSpeed = 0;
        }
        else
        {
            moonSpeed = savedMoonSpeed;
        }
    }


    if(key == 27)
        exit(0);
}

void mouse(int button, int state, int x, int y)
{
    //Train
    if(isDay)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            trainPaused = !trainPaused;
            if (trainPaused)
            {
                savedTrainSpeed = trainSpeed;
                trainSpeed = 0;
            }
            else
            {
                trainSpeed = savedTrainSpeed;
            }
        }
    }
    if(!isDay)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            trainPaused = !trainPaused;
            if (trainPaused)
            {
                savedTrainSpeed = trainSpeed;
                trainSpeed = 0;
            }
            else
            {
                trainSpeed = savedTrainSpeed;
            }
        }
    }
    //Sun
    if(isDay)
    {
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
            sunPaused = !sunPaused;
            if (sunPaused)
            {
                savedSunSpeed = sunSpeed;
                sunSpeed = 0;
            }
            else
            {
                sunSpeed = savedSunSpeed;
            }
        }
    }
    if(!isDay)
    {
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            moonPaused = !moonPaused;
            if (moonPaused)
            {
                savedMoonSpeed = moonSpeed;
                moonSpeed = 0;
            }
            else
            {
                moonSpeed = savedMoonSpeed;
            }
        }
    }
    //Cargoo Truck
    if(!isDay)
    {
        if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            V_cargoPaused = !V_cargoPaused;

            if (V_cargoPaused)
            {
                V_savedCargoSpeed = V_cargoSpeed;
                V_cargoSpeed = 0;
            }
            else
            {
                V_cargoSpeed = V_savedCargoSpeed;
            }
        }
    }
    if(isDay)
    {
        if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            V_cargoPaused = !V_cargoPaused;

            if (V_cargoPaused)
            {
                V_savedCargoSpeed = V_cargoSpeed;
                V_cargoSpeed = 0;
            }
            else
            {
                V_cargoSpeed = V_savedCargoSpeed;
            }
        }
    }
}

void ELAHI658()
{
    glDisable(GL_LIGHTING);
    sky();

    // ==========================================
    // SUN/MOON LIGHTING SETUP (GL_LIGHT0)
    // ==========================================

    if(isDay)
    {
        // DAY MODE: SUN
        float sunX_ELAHI658 = 50.0f + moveSun;
        float sunY_ELAHI658 = 650.0f;
        GLfloat lightPos[] = { sunX_ELAHI658, sunY_ELAHI658, 200.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        GLfloat sunColor[] = { 1.0f, 0.95f, 0.8f, 1.0f }; // Warm sunlight
        glLightfv(GL_LIGHT0, GL_DIFFUSE, sunColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, sunColor);
        GLfloat ambientColor[] = { 0.3f, 0.3f, 0.3f, 1.0f };
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
        glEnable(GL_LIGHT0);
    }
    else
    {
        // NIGHT MODE: MOON
        float moonX_ELAHI658 = 850.0f + moveMoon;
        float moonY_ELAHI658 = 650.0f;
        GLfloat lightPos[] = { moonX_ELAHI658, moonY_ELAHI658, 200.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

        GLfloat moonLightColor[] = { 0.4f, 0.4f, 0.5f, 1.0f }; // Dimmer light for night
        glLightfv(GL_LIGHT0, GL_DIFFUSE, moonLightColor);
        glLightfv(GL_LIGHT0, GL_SPECULAR, moonLightColor);
        GLfloat ambientColor[] = { 0.25f, 0.25f, 0.3f, 1.0f }; // Increased ambient for brighter night
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
        glEnable(GL_LIGHT0);
    }

    // Draw sun/moon (disabling lighting temporarily for visual)
    glDisable(GL_LIGHTING);
    moon();
    sun();
    glEnable(GL_LIGHTING);
    V_cloud1();
    V_cloud2();
    V_cloud3();
    V_cloud4();
    building();
    train();
    flyOver();
    garden();
    road();
    roadSideWall();
    bus();
    car();
    cargoTruck();
}

/// =======================================================$$$$$$$$$$$$$$$$$$$$$$$$===================================================================








void selectKeyboard(unsigned char key, int x, int y)
{

    if (scenarioELAHI658)
    {
        keyboard(key, x, y);
    }
}



void selectSpecialKeys(int key, int x, int y)
{
    // --- Scene 1: ELAHI658 ---
    if (scenarioELAHI658)
    {
        specialKeys(key, x, y);
    }

}

void selectMouse(int button, int state, int x, int y)
{
    if (scenarioELAHI658)
    {
        mouse(button, state, x, y);
    }

}

/// ##############################################################  Display  ###############################################################
void display()
{
    if(scenarioELAHI658) ELAHI658();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{


    // ==========================================
    // 2. MAIN CITY CONTROLS
    // ==========================================
    cout<<"********** >>> Main City Specifics <<< **********"<<endl;
    cout<<"Press key_up / key_down    : Train speed (Day/Night)"<<endl;
    cout<<"Press key_left / key_right : Sun speed (Day)/Moon speed (Night)"<<endl;
    cout<<"Press Page Up / Page Down  : Cargo Truck speed (Day/Night)"<<endl<<endl;
    cout<<"Mouse Left Click           : Stop/Start Train (Day) / Moon (Night)"<<endl;
    cout<<"Mouse Right Click          : Stop/Start Sun/Moon"<<endl;
    cout<<"Mouse Middle Click          : Stop/Start Truck (Day/Night)"<<endl;
    cout<<"Press SPACE                : Stop Everything"<<endl;

    // --- Window Initialization ---
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Going Through Places - A Journey By Car");

    // --- Graphics & Smoothing Setup ---
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Shade Model:
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING);


    glEnable(GL_LIGHT0);   // Sun/Moon
    glEnable(GL_LIGHT1);   // Street Lamps Group 1
    glEnable(GL_LIGHT2);   // Street Lamps Group 2
    glEnable(GL_LIGHT3);   // CyberTruck Headlight

    glEnable(GL_COLOR_MATERIAL);

    // Set Initial Light Properties
    GLfloat sunColor[] = { 1.0f, 0.95f, 0.8f, 1.0f }; // Warm sunlight
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sunColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, sunColor);

    // Ambient Light
    GLfloat ambientColor[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);

    // --- Projection Setup ---
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 700);

    // --- Callback Registration ---
    glutDisplayFunc(display);

    // Timers: ELAHI658
    glutTimerFunc(16, V_updateCloud1, 0);
    glutTimerFunc(16, V_updateCloud2, 0);
    glutTimerFunc(16, V_updateCloud3, 0);
    glutTimerFunc(16, V_updateCloud4, 0);
    glutTimerFunc(2, updateSun, 0);
    glutTimerFunc(16, updateMoon, 0);
    glutTimerFunc(16, updateTrain, 0);
    glutTimerFunc(2, V_updateBus, 0);
    glutTimerFunc(2, updateCar, 0);
    glutTimerFunc(16, V_updateCargo, 0);


    // Input Callbacks
    glutKeyboardFunc(selectKeyboard);
    glutSpecialFunc(selectSpecialKeys);
    glutMouseFunc(selectMouse);

    glutMainLoop();

    return 0;
}
