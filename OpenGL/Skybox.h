#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "objLoader.h"
#include "Texture2D.h"

class Skybox : public objLoader
{
private:


	Material* _material;
	float x, y, z;

protected:


public:
	objLoader objectLoader;
	Vector3 _position;
	Vector3 _rotation;
	Skybox(/*Texture2D* _texture,*/ float x, float y, float z, Vector3 rotation);
	~Skybox();
	void Load();
	float rotation;
	//static bool Load(char* path);
	virtual void Draw();
	void SetPosition(float newX, float newY, float newZ);
};