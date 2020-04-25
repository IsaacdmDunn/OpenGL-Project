#pragma once

//libraries
#include "GameObject.h"

//floor class inherits from gameobject
class Floor : GameObject
{
//public
public:
	Floor(float x, float y, float z, Vector3 rotation);
	~Floor();
	void Load();
	virtual void Draw();
	virtual void Update();
	void SetRotation(float newX, float newY, float newZ);
	void SetPosition(float newX, float newY, float newZ);
};