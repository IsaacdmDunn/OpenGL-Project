#include "Cube.h"
#include <fstream>
#include <iostream>

bool Cube::Load(char* path)
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

Cube::Cube(Mesh* mesh, Texture2D* _texture, float x, float y, float z) : SceneObject(mesh, _texture)
{
	rotation = rand();

	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Cube::~Cube()
{

}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		//glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoord);
		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

		glRotatef(rotation, 1.0f, 1.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		for (int i = 0; i < _mesh->IndexCount; i++)
		{
			glTexCoord2fv(&_mesh->TexCoords[_mesh->Indices[i]].u);
			//glColor3fv(&_mesh->Colors[_mesh->Indices[i]].r);
			glNormal3f(_mesh->Normals[i].normal.x, _mesh->Normals[i].normal.y, _mesh->Normals[i].normal.z);
			glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
		}
		glEnd();
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glPopMatrix();
	}
}

void Cube::Update()
{
	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}
}

void Cube::SetRotation(GLfloat newRotation)
{
	rotation += newRotation;
}
