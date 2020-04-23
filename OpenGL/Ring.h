#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "objLoader.h"
#include "Texture2D.h"

class Ring : public objLoader
{
private:


	Material* _material;
	float x, y, z;
	float _rotation;

protected:


public:
	objLoader objectLoader;
	Vector3 _position;
	Ring(/*Texture2D* _texture,*/ float x, float y, float z, float rotation);
	~Ring();
	void Load();
	//static bool Load(char* path);
	virtual void Draw();
	virtual void Update();
	void SetRotation(float newX, float newY, float newZ);
	void SetPosition(float newX, float newY, float newZ);
};