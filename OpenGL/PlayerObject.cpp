#include "PlayerObject.h"
#include <iostream>
#include <stdlib.h>     
#include <time.h>    

PlayerObject::PlayerObject(float x, float y, float z, Vector3 rotation) : GameObject(x, y, z, rotation)
{
	srand(time(NULL));
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = rotation.y;

	//_CollisionBox = new CollisionBox(3, 3, 3);
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::Load()
{
	GameObject::Load("Assets/cube.obj");
}

void PlayerObject::Draw()
{
	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation.y, 0, 1, 0);
	glScalef(0.3, 0.3, 0.3);
	GameObject::Draw();
}

void PlayerObject::Update()
{
	_rotation.y++;
}

void PlayerObject::SetRotation(float newX, float newY, float newZ)
{
	GameObject::SetRotation(newX, newY, newZ);
}

void PlayerObject::SetPosition(float newX, float newY, float newZ)
{
	GameObject::SetPosition(newX, newY, newZ);
}
