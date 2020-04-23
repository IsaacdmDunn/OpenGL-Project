#include "Source.h"

int main(int argc, char* argv[]) 
{
	srand(time(NULL));
	Source* game = new Source(argc, argv);
	return 0;
}

Source::Source(int argc, char* argv[])
{
	_GameLevel = new GameLevel();

	//initialises game
	InitGL(argc, argv);

	InitObjects();
	InitLighting();
	
	glutMainLoop();
};

Source::~Source()
{
	delete _BackgroundTexture;
}

void Source::Keyboard(unsigned char key, int x, int y)
{
	_GameLevel->Keyboard(key, x, y);
}

void Source::Update()
{
	_GameLevel->Update();

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_Light->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_Light->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_Light->specular.x));

	glutPostRedisplay();
}

void Source::Render()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//glBegin(GL_TRIANGLES);

	//disables projection
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	//applies texture
	glBindTexture(GL_TEXTURE_2D, _BackgroundTexture->GetID());

	//draws background
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_TEXTURE_COORD_ARRAY);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2i(0, 0);
	glVertex2i(-1, -1);
	glTexCoord2i(1, 0);
	glVertex2i(1, -1);
	glTexCoord2i(1, 1);
	glVertex2i(1, 1);
	glTexCoord2i(0, 1);
	glVertex2i(-1, 1);
	glEnd();
	glDisable(GL_TEXTURE_COORD_ARRAY);

	//reenables projection
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	_GameLevel->Render();

	glFlush();
	glutSwapBuffers();
}

void Source::InitObjects()
{
	_GameLevel->InitObjects();
	_Light = new Lighting();
	_BackgroundTexture = new Texture2D();
	_BackgroundTexture->Load((char*)"Assets/stars.raw", 512, 512);
	
}

void Source::InitLighting()
{
	//enables lights
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void Source::InitGL(int argc, char* argv[])
{
	//set up window
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESH_RATE, GLUTCallbacks::Timer, REFRESH_RATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	glMatrixMode(GL_PROJECTION);

	//Set the viewport to be the entitre window
	glViewport(0, 0, 800, 800);

	//Set the correct perspective
	gluPerspective(90, 1, 1, 700);

	//Switches back to model view
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_FOG);

	GLfloat density = 0.014;
	GLfloat fogColor[4] = { 0.45, 0.3, 0.3, 1.0 };

	glFogi(GL_FOG_MODE, GL_EXP2);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, density);
	glHint(GL_FOG_HINT, GL_NICEST);

	//culls the back face of objects
	glCullFace(GL_BACK);

}
