#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "objLoader.h"
#include "Texture2D.h"

class Floor : public objLoader
{
private:


	Material* _material;
	float x, y, z;

protected:


public:
	objLoader objectLoader;
	Vector3 _position;
	Floor(/*Texture2D* _texture,*/ float x, float y, float z);
	~Floor();
	void Load();
	float rotation;
	//static bool Load(char* path);
	virtual void Draw();
	virtual void Update();
	void SetRotation(GLfloat newRotation);
};