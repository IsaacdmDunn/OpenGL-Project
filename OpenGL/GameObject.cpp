//library
#include "GameObject.h"
#include <iostream>    
#include <time.h>    

//constructor
GameObject::GameObject(float x, float y, float z, Vector3 rotation)
{
}

//destructor
GameObject::~GameObject()
{
}

//loads game object
void GameObject::Load(std::string objectDirectory)
{
	bool cubeLoad = objectLoader.LoadFile(objectDirectory);

	for (auto& objectLoader : objectLoader.mLoadedMeshes) {
		std::cout << "Object loaded: " << objectLoader.meshName << ".obj" << std::endl;
	}

	for (auto& objectLoader : objectLoader.mLoadedMaterial) {
		std::cout << "Material loaded: " << objectLoader.name << ".mtl" << std::endl;
	}
}

void GameObject::Draw()
{
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

//sets rotation of game object
void GameObject::SetRotation(float newX, float newY, float newZ)
{
	_rotation.x = newX;
	_rotation.y = newY;
	_rotation.z = newZ;
}

//sets position of game object
void GameObject::SetPosition(float newX, float newY, float newZ)
{
	_position.x = newX;
	_position.y = newY;
	_position.z = newZ;
}
