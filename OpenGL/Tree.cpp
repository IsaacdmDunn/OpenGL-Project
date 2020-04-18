#include "Tree.h"
#include <iostream>
#include <stdlib.h>     
#include <time.h>    

Tree::Tree(/*Texture2D* _texture, */float x, float y, float z)
{
	srand(time(NULL));
	/*_position.x = rand() % 300 - 150;
	_position.y = -2;
	_position.z = rand() % 15 - 10;*/
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Tree::~Tree()
{
}

void Tree::Load()
{
	bool cubeLoad = objectLoader.LoadFile("tree.obj");

	for (auto& objectLoader : objectLoader.mLoadedMeshes) {
		std::cout << "Object loaded: " << objectLoader.meshName << ".obj" << std::endl;
	}

	for (auto& objectLoader : objectLoader.mLoadedMaterial) {
		std::cout << "Material loaded: " << objectLoader.name << ".mtl" << std::endl;
	}
	std::cout << _position.x << "  " << _position.y << "  " << _position.z << "  " << std::endl;
}

void Tree::Draw()
{
	

	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);


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

void Tree::Update()
{
	glTranslatef(_position.x, _position.y, _position.z);
}

void Tree::SetRotation(GLfloat newRotation)
{
}
