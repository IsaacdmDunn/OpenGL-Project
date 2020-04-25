#include "Floor.h"
#include <iostream>
#include <stdlib.h>     
#include <time.h>    

Floor::Floor(float x, float y, float z, Vector3 rotation) : GameObject(x, y, z, rotation)
{
	srand(time(NULL));
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Floor::~Floor()
{
}

void Floor::Load()
{
	GameObject::Load("Assets/floor.obj");
}

void Floor::Draw()
{
	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glScalef(100, 0.1, 100);

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

void Floor::Update()
{
	glTranslatef(_position.x, _position.y, _position.z);
}

void Floor::SetPosition(float newX, float newY, float newZ)
{
	GameObject::SetPosition(newX, newY, newZ);
}

void Floor::SetRotation(float newX, float newY, float newZ)
{
	GameObject::SetRotation(newX, newY, newZ);
}
