#include "Moon.h"
#include <iostream>
#include <stdlib.h>     
#include <time.h>    

Moon::Moon(/*Texture2D* _texture, */float x, float y, float z, float rotation)
{
	srand(time(NULL));
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = rotation;
}

Moon::~Moon()
{
}

void Moon::Load()
{
	bool cubeLoad = objectLoader.LoadFile("Assets/Moon.obj");

	for (auto& objectLoader : objectLoader.mLoadedMeshes) {
		std::cout << "Object loaded: " << objectLoader.meshName << ".obj" << std::endl;
	}

	for (auto& objectLoader : objectLoader.mLoadedMaterial) {
		std::cout << "Material loaded: " << objectLoader.name << ".mtl" << std::endl;
	}
	std::cout << _position.x << "  " << _position.y << "  " << _position.z << "  " << _rotation << "" << std::endl;
}

void Moon::Draw()
{


	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1, 0, 0);
	glScalef(50, 50, 50);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glBegin(GL_TRIANGLES);
	for (auto& object : objectLoader.mLoadedMeshes) {
		for (int i = 0; i < object.indices.size(); i++) {

			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, &(object.meshMaterial.ambientColour.x));
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, &(object.meshMaterial.diffuseColour.x));
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, &(object.meshMaterial.specularComponent.x));
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, object.meshMaterial.shininess);

			glTexCoord2fv(&object.verticies[object.indices[i]].textureCoordinate.x);
			glNormal3fv(&object.verticies[object.indices[i]].normal.x);
			glVertex3fv(&object.verticies[object.indices[i]].position.x);
		}
	}

	glEnd();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glPopMatrix();


}

void Moon::Update()
{
	_position.y -= 0.02;
}

void Moon::SetRotation(float newX, float newY, float newZ)
{
}

void Moon::SetPosition(float newX, float newY, float newZ)
{
	_position.x = newX;
	_position.y = newY;
	_position.z = newZ;
}
