#pragma once

//libraries
#include "GameObject.h"

//skybox class inherits from gameobject
class Skybox : GameObject
{
public:
	Skybox(float x, float y, float z, Vector3 rotation);
	~Skybox();
	void Load();
	virtual void Draw();
	virtual void Update();
	void SetRotation(float newX, float newY, float newZ);
	void SetPosition(float newX, float newY, float newZ);
};