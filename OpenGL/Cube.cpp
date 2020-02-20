#include "Cube.h"
#include <fstream>
#include <iostream>

//Vertex* Cube::indexedVertices = nullptr;
//Color* Cube::indexedColors = nullptr;
//GLushort* Cube::indices = nullptr;
//
//int Cube::numVertices;
//int Cube::numColors;
//int Cube::numIndices;

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

Cube::Cube(Mesh* mesh, float x, float y, float z)
{
	rotation = rand();
	_mesh = mesh;

	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Cube::~Cube()
{

}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

		glRotatef(rotation, 1.0f, 1.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		for (int i = 0; i < 36; i++)
		{
			glColor3fv(&_mesh->Colors[_mesh->Indices[i]].r);
			glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
		}
		glEnd();

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
