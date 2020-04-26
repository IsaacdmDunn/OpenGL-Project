#pragma once

//libraries
#include "GameObject.h"

//ring class inherits from gameobject
class Ring : GameObject
{
//public
public:
	Ring(float x, float y, float z, Vector3 rotation);
	~Ring();
	void Load();
	virtual void Draw();
	virtual void Update();
	void SetRotation(float newX, float newY, float newZ);
	void SetPosition(float newX, float newY, float newZ);
	Vector3 GetPosition();
	Vector3 GetRotation();

	CollisionBox* _CollisionBox;
};