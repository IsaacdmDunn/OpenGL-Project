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
	//delete camera;
	//delete objects;
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
	////moves camera with WASD controls
	//if (key == 'd')
	//{
	//	cameraPosition.x++;
	//}
	//else if (key == 'a')
	//{
	//	cameraPosition.x--;
	//}
	//else if (key == 'w')
	//{
	//	cameraPosition.z++;
	//}
	//else if (key == 's')
	//{
	//	cameraPosition.z--;
	//}
	//else if (key == '1')
	//{ 
	//	for (int i = 0; i < 1000; i++)
	//	{
	//		objects[i]->Draw();

	//	}
	//}

	//else if (key == '2')
	//{
	//
	//}

	//else if (key == '3')
	//{

	//}


	//std::cout << "X: " << cameraPosition.x << " Y: " << cameraPosition.y << " Z: " << cameraPosition.z << std::endl;
}

void Source::Update()
{
	////loads camera position
	//glLoadIdentity();
	//gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);

	////updates lighting
	//glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	//glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));
	//glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	//glutPostRedisplay();

	////object rotation
	//for (int i = 0; i < 1000; i++)
	//{
	//	objects[i]->Update();
	//}
	//glTranslatef(0.0f, 0.0f, -5.0f);
	//glutPostRedisplay();
	////update camera position
	//camera->eye.x = cameraPosition.x + 0.0f;		camera->eye.y = cameraPosition.y + 0.0f;			camera->eye.z = cameraPosition.z + 1.0f;
	//camera->center.x = cameraPosition.x + 0.0f;		camera->center.y = cameraPosition.y + 0.0f;			camera->center.z = cameraPosition.z + 0.0f;
	//camera->up.x = cameraPosition.x + 0.0f;			camera->up.y = cameraPosition.y + 1.0f;				camera->up.z = cameraPosition.z + 0.0f;
	//
	glLoadIdentity();
	gluLookAt(_Camera->eye.x, _Camera->eye.y, _Camera->eye.z, _Camera->center.x, _Camera->center.y, _Camera->center.z, _Camera->up.x, _Camera->up.y, _Camera->up.z);

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_Light->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_Light->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_Light->specular.x));



	glTranslatef(0.0f, 0.0f, -5.0f);

	glutPostRedisplay();
}

void Source::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0.0f, -12.0f, -12.0f);
	glRotatef(rotation, 0.0f, 1.0f, 0.0f);


	glBegin(GL_TRIANGLES);

	for (auto& object : objectLoader.mLoadedMeshes) {
		for (int i = 0; i < object.indices.size(); i++) {
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, &(object.meshMaterial.ambientColour.x));
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, &(object.meshMaterial.diffuseColour.x));
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, &(object.meshMaterial.specularComponent.x));
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, object.meshMaterial.shininess);

			glMaterialfv(GL_LEFT, GL_AMBIENT, &(object.meshMaterial.ambientColour.x));
			glMaterialfv(GL_LEFT, GL_DIFFUSE, &(object.meshMaterial.diffuseColour.x));
			glMaterialfv(GL_LEFT, GL_SPECULAR, &(object.meshMaterial.specularComponent.x));
			glMaterialf(GL_LEFT, GL_SHININESS, object.meshMaterial.shininess);

			glMaterialfv(GL_RIGHT, GL_AMBIENT, &(object.meshMaterial.ambientColour.x));
			glMaterialfv(GL_RIGHT, GL_DIFFUSE, &(object.meshMaterial.diffuseColour.x));
			glMaterialfv(GL_RIGHT, GL_SPECULAR, &(object.meshMaterial.specularComponent.x));
			glMaterialf(GL_RIGHT, GL_SHININESS, object.meshMaterial.shininess);

			glTexCoord2fv(&object.verticies[object.indices[i]].textureCoordinate.x);
			glNormal3fv(&object.verticies[object.indices[i]].normal.x);
			glVertex3fv(&object.verticies[object.indices[i]].position.x);
		}
	}

	glEnd();

	glPopMatrix();

	glFlush();
	glutSwapBuffers();

}

void Source::InitObjects()
{
	////sets up camera
	//camera = new Camera();
	//camera->eye.x = cameraPosition.x + 0.0f;		camera->eye.y = cameraPosition.y + 0.0f;			camera->eye.z = cameraPosition.z + 1.0f;
	//camera->center.x = cameraPosition.x + 0.0f;		camera->center.y = cameraPosition.y + 0.0f;			camera->center.z = cameraPosition.z + 0.0f;
	//camera->up.x = cameraPosition.x + 0.0f;			camera->up.y = cameraPosition.y + 1.0f;				camera->up.z = cameraPosition.z + 0.0f;

	//Mesh* cubeMesh = MeshLoader::Load((char*)"Cube.txt");
	////Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");

	////load cube textures
	//Texture2D* texture = new Texture2D();
	//texture->Load((char*)"Penguins.raw", 512, 512);

	////initialise cubes
	//for (int i = 0; i < 1000; i++)
	//{
	//	objects[i] = new Cube(cubeMesh, texture, ((rand() % 800) / 10.0f) - 20.0f, ((rand() % 500) / 10.0f) - 10.0f, -(rand() % 1500) / 10.0f);
	//}

	_Camera = new Camera();
	_Camera->eye.z = 1.0f;
	_Camera->up.y = 1.0f;

	_Light = new Lighting();


	bool cubeLoad = objectLoader.LoadFile("tree.obj");

	for (auto& objectLoader : objectLoader.mLoadedMeshes) {
		std::cout << "Object loaded: " << objectLoader.meshName << ".obj" << std::endl;
	}

	for (auto& objectLoader : objectLoader.mLoadedMaterial) {
		std::cout << "Material loaded: " << objectLoader.name << ".mtl" << std::endl;
	}


	//bool brick = objectLoader.LoadFile("brick.obj");
}

void Source::InitLighting()
{
	////set lighting position
	//_lightPosition = new Vector4();
	//_lightPosition->x = 0.0;
	//_lightPosition->y = 0.0;
	//_lightPosition->z = 1.0;
	//_lightPosition->w = 0.0;

	//_lightData = new Lighting();
	//_lightData->Ambient.x = 0.6;
	//_lightData->Ambient.y = 0.6;
	//_lightData->Ambient.z = 0.6;
	//_lightData->Ambient.w = 1.0;
	//_lightData->Diffuse.x = 0.8;
	//_lightData->Diffuse.y = 0.8;
	//_lightData->Diffuse.z = 0.8;
	//_lightData->Diffuse.w = 1.0;
	//_lightData->Specular.x = 0.2;
	//_lightData->Specular.y = 0.2;
	//_lightData->Specular.z = 0.2;
	//_lightData->Specular.w = 1.0;
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
