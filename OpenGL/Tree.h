#pragma once

#include "GameObject.h"

class Tree : GameObject
{
private:

public:
	Tree(float x, float y, float z, Vector3 rotation);
	~Tree();
	void Load();
	virtual void Draw();
	virtual void Update();
	void SetRotation(float newX, float newY, float newZ);
	void SetPosition(float newX, float newY, float newZ);
};