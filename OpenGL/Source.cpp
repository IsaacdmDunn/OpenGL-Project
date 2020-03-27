#include "Source.h"
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
	//initialises game
	InitGL(argc, argv);

	InitObjects();
	InitLighting();
	
	glutMainLoop();
};

Source::~Source()
{
}

void Source::Keyboard(unsigned char key, int x, int y)
{
	//moves camera with WASD controls
	if (key == 'd')
	{
		rotation++;
	}
	else if (key == 'a')
	{
		rotation--;
	}
}

void Source::Update()
{
	glLoadIdentity();
	gluLookAt(_Camera->eye.x, _Camera->eye.y, _Camera->eye.z, _Camera->center.x, _Camera->center.y, _Camera->center.z, _Camera->up.x, _Camera->up.y, _Camera->up.z);

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_Light->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_Light->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_Light->specular.x));

	//glTranslatef(0.0f, -5.0f, -5.0f);

	glutPostRedisplay();
}

void Source::Render()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//glBegin(GL_TRIANGLES);

	for (int i = 0; i < 50; i++)
	{
		_Tree[i]->Draw();
	}
	glPopMatrix();

	glFlush();
	glutSwapBuffers();

}

void Source::InitObjects()
{
	_Camera = new Camera();
	_Camera->eye.z = 1.0f;
	_Camera->up.y = 1.0f;
	_Light = new Lighting();
	for (int i = 0; i < 50; i++)
	{
		std::cout << "tree: " << i << std::endl;
		_Tree[i] = new Tree(0, 0, 0);

		_Tree[i]->Load();
	}

	//bool brick = Suzanne.LoadFile("test.obj");
	//for (auto& Suzanne : Suzanne.mLoadedMeshes) {
	//	std::cout << "Object loaded: " << Suzanne.meshName << ".obj" << std::endl;
	//}

	//for (auto& Suzanne : Suzanne.mLoadedMaterial) {
	//	std::cout << "Material loaded: " << Suzanne.name << ".mtl" << std::endl;
	//}

	//_BackgroundTexture = new Texture2D();
	//_BackgroundTexture->Load((char*)"Penguins.raw", 512, 512);
}

void Source::InitLighting()
{
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

	//enables lights
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//culls the back face of objects
	glCullFace(GL_BACK);


}
