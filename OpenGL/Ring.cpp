#include "Ring.h"
#include <iostream>
#include <stdlib.h>     
#include <time.h>    

Ring::Ring(float x, float y, float z, Vector3 rotation) : GameObject(x, y, z, rotation)
{
	srand(time(NULL));
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = rotation.y;

	_CollisionBox = new CollisionBox(3,3,3);
}

Ring::~Ring()
{
}

void Ring::Load()
{
	GameObject::Load("Assets/Ring.obj");
}

void Ring::Draw()
{
	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation.y, 0, 1, 0);
	glScalef(5, 5, 5);
	GameObject::Draw();
}

void Ring::Update()
{
	_rotation.y++;
}

void Ring::SetRotation(float newX, float newY, float newZ)
{
	GameObject::SetRotation(newX, newY, newZ);
}

void Ring::SetPosition(float newX, float newY, float newZ)
{
	GameObject::SetPosition(newX, newY, newZ);
}
