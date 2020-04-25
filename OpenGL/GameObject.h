#pragma once

//libraries
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "objLoader.h"
#include "Texture2D.h"

//game object class inherits from obj loader
class GameObject : public objLoader
{
//protected
protected:
	objLoader objectLoader;
	Vector3 _position;
	Vector3 _rotation;

//public
public:
	GameObject(float x, float y, float z, Vector3 rotation);
	~GameObject();
	void Load(std::string objectDirectory);
	void Draw();
	void SetRotation(float newX, float newY, float newZ);
	void SetPosition(float newX, float newY, float newZ);
};