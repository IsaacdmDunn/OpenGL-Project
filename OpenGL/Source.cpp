#include "Source.h"
#include "Structures.h"
#include "GLUTCallbacks.h"
#include "MeshLoader.h"
#include <iostream>


int main(int argc, char* argv[]) 
{
	Vector3 cameraPosition;
	cameraPosition.x = 0.0f;
	cameraPosition.y = 0.0f;
	cameraPosition.z = 0.0f;
	Source* game = new Source(argc, argv);
	return 0;
}

Source::Source(int argc, char* argv[])
{
	//sets up camera
	camera = new Camera();
	camera->eye.x = cameraPosition.x + 5.0f;		camera->eye.y = cameraPosition.y + 5.0f;			camera->eye.z = cameraPosition.z + -15.0f;
	camera->center.x = cameraPosition.x + 0.0f;		camera->center.y = cameraPosition.y + 0.0f;			camera->center.z = cameraPosition.z + 0.0f;
	camera->up.x = cameraPosition.x + 0.0f;			camera->up.y = cameraPosition.y + 1.0f;				camera->up.z = cameraPosition.z + 0.0f;

	//Cube::Load((char*)"cube.txt");
	Mesh* cubeMesh = MeshLoader::Load("cube.txt");
	for (int i = 0; i < 200; i++)
	{
		cube[i] = new Cube(cubeMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	glutCreateWindow("OpenGL Program");

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESH_RATE, GLUTCallbacks::Timer, REFRESH_RATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	//Set the viewport to be the entitre window
	glViewport(0, 0, 800, 800);

	//Set the correct perspective
	gluPerspective(90, 1, 1, 700);

	//Switches back to model view
	glMatrixMode(GL_MODELVIEW);

	//culls the back face of objects
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutMainLoop();
};


Source::~Source()
{
	delete camera;
	delete cube;
}

void Source::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		cameraPosition.x++;
	}
	else if (key == 'a')
	{
		cameraPosition.x--;
	}
	else if (key == 'w')
	{
		cameraPosition.z++;
	}
	else if (key == 's')
	{
		cameraPosition.z--;
	}

	std::cout << "X: " << cameraPosition.x << " Y: " << cameraPosition.y << " Z: " << cameraPosition.z << std::endl;
}

void Source::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);


	glutPostRedisplay();
	for (int i = 0; i < 200; i++)
	{
		//cube[i]->SetRotation(1.0f);
	}

	Sleep(10);

	camera->eye.x =		cameraPosition.x + 5.0f;	camera->eye.y = cameraPosition.y + 5.0f;		camera->eye.z = cameraPosition.z + -25.0f;
	camera->center.x =	cameraPosition.x + 0.0f;	camera->center.y = cameraPosition.y + 0.0f;		camera->center.z = cameraPosition.z + -15.0f;
	camera->up.x =		cameraPosition.x + 0.0f;	camera->up.y = cameraPosition.y + 1.0f;			camera->up.z = cameraPosition.z + -15.0f;
}

void Source::DrawCubeArray() 
{
	
}

void Source::DrawIndexedCube()
{
	
}

void Source::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	for (int i = 0; i < 200; i++)
	{
		

		cube[i]->Draw();

	}

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void Source::InitObjects()
{
}

void Source::InitGL(int argc, char* argv[])
{
}
