#pragma once

//libraries
#include "GameObject.h"

//moon class inherits from gameobject
class Moon : GameObject
{
//public
public:
	Moon(float x, float y, float z, Vector3 rotation);
	~Moon();
	void Load();
	virtual void Draw();
	virtual void Update();
	void SetRotation(float newX, float newY, float newZ);
	void SetPosition(float newX, float newY, float newZ);
	float GetYPosition();
};
