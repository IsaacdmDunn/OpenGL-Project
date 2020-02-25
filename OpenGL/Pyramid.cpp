#include "Pyramid.h"
#include <fstream>
#include <iostream>

bool Pyramid::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}

	inFile.close();

	return true;
}

Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr)
{
	rotation = rand();

	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Pyramid::~Pyramid()
{

}

void Pyramid::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		/*glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);*/
		//glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoord);
		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

		//glRotatef(rotation, 1.0f, 1.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		for (int i = 0; i < 36; i++)
		{
			glColor3fv(&_mesh->Colors[_mesh->Indices[i]].r);
			glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
		}
		glEnd();
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glPopMatrix();
	}
}

void Pyramid::Update()
{
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
}

void Pyramid::SetRotation(GLfloat newRotation)
{
	rotation += newRotation;
}
