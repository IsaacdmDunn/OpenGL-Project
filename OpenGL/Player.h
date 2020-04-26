#pragma once

//libraries
#include "objLoader.h"
#include "PlayerObject.h"

//player class inherits from gameobject
class Player : GameObject
{
//private
private:
	//player objects
	Camera* _Camera;
	PlayerObject* _PlayerObject;
//public
public:
	Player(float x, float y, float z, Vector3 rotation);
	~Player();
	void Load();
	virtual void Draw();
	virtual void Update();

	void SetPosition(float newX, float newY, float newZ);
	void SetRotation(float newX, float newY, float newZ);

	Vector3 GetPosition();
	Vector3 GetRotation();

	CollisionBox* _CollisionBox;
};

struct PlayerNode 
{

};
