#include "Skybox.h"
#include <iostream>
#include <stdlib.h>     
#include <time.h>    

Skybox::Skybox(float x, float y, float z, Vector3 rotation) : GameObject(x, y, z, rotation)
{
	srand(time(NULL));
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_rotation.x = rotation.x;
	_rotation.y = rotation.y;
	_rotation.z = rotation.z;
}

Skybox::~Skybox()
{
}

void Skybox::Load()
{
	GameObject::Load("Assets/skybox.obj");
}

void Skybox::Draw()
{
	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation.x, 1, 0, 0);
	glRotatef(_rotation.y, 0, 1, 0);
	glRotatef(_rotation.z, 0, 0, 1);
	glScalef(25, 1, 25);

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

void Skybox::Update()
{
}

void Skybox::SetRotation(float newX, float newY, float newZ)
{
	GameObject::SetRotation(newX, newY, newZ);
}

void Skybox::SetPosition(float newX, float newY, float newZ)
{
	_position.x -= newX;
	_position.y -= newY;
	_position.z -= newZ;
	GameObject::SetPosition(_position.x, _position.y, _position.z);
}
