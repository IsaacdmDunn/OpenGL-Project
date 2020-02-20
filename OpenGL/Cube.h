#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

class Cube
{
private:
	
	Mesh* _mesh;

	Vector3 _position;
	float x, y, z;

protected:
	

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();
	float rotation;
	static bool Load(char* path);
	void Draw();
	void Update();
	void SetRotation(GLfloat newRotation);
};
