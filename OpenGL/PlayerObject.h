#pragma once

//libraries
#include "GameObject.h"

//moon class inherits from gameobject
class PlayerObject : GameObject
{
	//public
public:
	PlayerObject(float x, float y, float z, Vector3 rotation);
	~PlayerObject();
	void Load();
	virtual void Draw();
	virtual void Update();
	void SetRotation(float newX, float newY, float newZ);
	void SetPosition(float newX, float newY, float newZ);
};
