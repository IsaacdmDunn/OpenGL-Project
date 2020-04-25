#pragma once

//libraries
#include "objLoader.h"
#include "Tree.h"

//player class inherits from gameobject
class Player : GameObject
{
//private
private:
	//player objects
	Camera* _Camera;
	Tree* _PlayerObject;
//public
public:
	Player(float x, float y, float z, Vector3 rotation);
	~Player();
	void Load();
	virtual void Draw();
	virtual void Update();

	void SetPosition(float newX, float newY, float newZ);
	Vector3 GetPosition() { return _position.x, _position.y, _position.z; }

	void SetRotation(float newX, float newY, float newZ);
	Vector3 GetRotation() { return _rotation.x, _rotation.y, _rotation.z; }

	CollisionBox* _CollisionBox;
};
