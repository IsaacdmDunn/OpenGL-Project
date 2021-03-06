//library
#include "Source.h"

//main function
int main(int argc, char* argv[]) 
{
	srand(time(NULL));
	Source* game = new Source(argc, argv);
	return 0;
}

//constructor
Source::Source(int argc, char* argv[])
{
	//create a new level
	_GameLevel = new GameLevel();
	int score = 0;

	//initialises game and objects
	InitGL(argc, argv);
	InitObjects();
	InitLighting();
	
	//run game loop
	glutMainLoop();
};

//destructor
Source::~Source()
{
	delete _BackgroundTexture;
}

//keyboard handler
void Source::Keyboard(unsigned char key, int x, int y)
{
	_GameLevel->Keyboard(key, x, y);
}

//updates each frame
void Source::Update()
{
	//updates level
	_GameLevel->Update();

	//updates lights
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_Light->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_Light->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_Light->specular.x));

	glutPostRedisplay();
}

//renders each frame
void Source::Render()
{
	

	//render level
	_GameLevel->Render();

	
}

//initialises all objects
void Source::InitObjects()
{
	//level objects
	_GameLevel->InitObjects();
}

//initialises lighting
void Source::InitLighting()
{
	_Light = new Lighting();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

//initialises openGL
void Source::InitGL(int argc, char* argv[])
{
	//set up window
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1440, 1080);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);

	//sets refresh rate
	glutTimerFunc(REFRESH_RATE, GLUTCallbacks::Timer, REFRESH_RATE);

	//runs keyboard handler
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	//projects the game perspective
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 1440, 1080);
	gluPerspective(110, 1, 1, 700);

	//Switches back to model view
	glMatrixMode(GL_MODELVIEW);

	//enables features
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_FOG);

	//adds fog
	GLfloat density = 0.014;
	GLfloat fogColor[4] = { 0.45, 0.3, 0.3, 1.0 };
	glFogi(GL_FOG_MODE, GL_EXP2);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, density);
	glHint(GL_FOG_HINT, GL_NICEST);

	//culls the back face of objects
	glCullFace(GL_BACK);

}
