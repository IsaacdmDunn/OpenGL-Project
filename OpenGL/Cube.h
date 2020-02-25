#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"
#include "Texture2D.h"

class Cube : public SceneObject
{
private:

	Vector3 _position;
	float x, y, z;

protected:
	

public:
	Cube(Mesh* mesh, Texture2D* _texture, float x, float y, float z);
	~Cube();
	float rotation;
	static bool Load(char* path);
	void Draw();
	void Update();
	void SetRotation(GLfloat newRotation);
};
