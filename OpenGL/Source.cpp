#include "Source.h"
#include <iostream>
#include <stdlib.h>     
#include <time.h>    


int main(int argc, char* argv[]) 
{
	srand(time(NULL));
	Source* game = new Source(argc, argv);
	return 0;
}

Source::Source(int argc, char* argv[])
{
	//initialises game
	InitGL(argc, argv);

	InitObjects();
	InitLighting();
	
	glutMainLoop();
};

Source::~Source()
{
	delete _Camera;
	delete _Floor;
	delete _BackgroundTexture;
	for (int i = 0; i < TREECOUNT; i++)
	{
		_Tree[i] = NULL;
	}
	delete[] _Tree;
}

void Source::Keyboard(unsigned char key, int x, int y)
{
	//moves camera with WASD controls
	if (key == 'd')
	{
		_Camera->position.x -= 1.1;
	}
	else if (key == 'a')
	{
		_Camera->position.x += 1.1;
	}
	else if (key == 'w')
	{
		_Camera->position.z += 1.1;
	}
	else if (key == 's')
	{
		_Camera->position.z -= 1.1;
	}
	//rotates camera with Q for left and E for right
	else if (key == 'q')
	{
		rotation -= 1.5;
		//_Camera->center.z--;
	}
	else if (key == 'e')
	{
		rotation += 1.5;
		//_Camera->center.z++;
	}
}

void Source::Update()
{
	glLoadIdentity();
	gluLookAt(_Camera->eye.x, _Camera->eye.y, _Camera->eye.z, _Camera->center.x, _Camera->center.y, _Camera->center.z, _Camera->up.x, _Camera->up.y, _Camera->up.z);
	glTranslatef(_Camera->position.x, _Camera->position.y, _Camera->position.z);
	glRotatef(rotation,0,1,0);
	
	for (int i = 0; i < TREECOUNT; i++)
	{
		_Tree[i]->Update();
	}
	_Floor->Update();

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_Light->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_Light->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_Light->specular.x));

	glutPostRedisplay();
}

void Source::Render()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//glBegin(GL_TRIANGLES);

	for (int i = 0; i < TREECOUNT; i++)
	{
		_Tree[i]->Draw();
	}
	_Floor->Draw();
	//glPopMatrix();

	glFlush();
	glutSwapBuffers();


	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, _BackgroundTexture->GetID());

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
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void Source::InitObjects()
{
	_Camera = new Camera();
	_Camera->eye.z = 1.0f;
	_Camera->up.y = 1.0f;
	_Light = new Lighting();
	/*for (int i = 0; i < TREECOUNT; i++)
	{
		std::cout << "tree: " << i << std::endl;
		_Tree[i] = new Tree(rand() % 45 - 22.5, -0.5, rand() % 15 - 25);

		_Tree[i]->Load();
	}*/

	
	_Tree[0] = new Tree(10, -0.5, -8);
	_Tree[0]->Load();
	_Tree[1] = new Tree(-20, -0.5, -5);
	_Tree[1]->Load();
	_Tree[2] = new Tree(-24, -0.5, -2);
	_Tree[2]->Load();
	_Tree[3] = new Tree(30, -0.5, -4);
	_Tree[3]->Load();
	_Tree[4] = new Tree(5, -0.5, -10);
	_Tree[4]->Load();
	_Tree[5] = new Tree(16, -0.5, -15);
	_Tree[5]->Load();
	_Tree[6] = new Tree(-18, -0.5, -14);
	_Tree[6]->Load();
	_Tree[7] = new Tree(-35, -0.5, -12);
	_Tree[7]->Load();
	_Tree[8] = new Tree(10, -0.5, -19);
	_Tree[8]->Load();
	_Tree[9] = new Tree(9, -0.5, -25);
	_Tree[9]->Load();
	_Tree[10] = new Tree(33, -0.5, -22);
	_Tree[10]->Load();
	_Tree[11] = new Tree(-11, -0.5, -30);
	_Tree[11]->Load();
	_Tree[12] = new Tree(-33, -0.5, -32);
	_Tree[12]->Load();
	_Tree[13] = new Tree(22, -0.5, -19);
	_Tree[13]->Load();
	_Tree[14] = new Tree(15, -0.5, -20);
	_Tree[14]->Load(); 

	_Floor = new Floor(0, -0.5, 0);
	_Floor->Load();

	_BackgroundTexture = new Texture2D();
	_BackgroundTexture->Load((char*)"Penguins.raw", 512, 512);
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


	//culls the back face of objects
	glCullFace(GL_BACK);

}
