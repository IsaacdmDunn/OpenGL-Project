//libraries
#include "Player.h"

//constructor
Player::Player(float x, float y, float z, Vector3 rotation)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation.x = rotation.x;
	_rotation.y = rotation.y;
	_rotation.z = rotation.z;
	_Camera = new Camera();
	_PlayerObject = new Tree(x+5,y,z+5, rand() % 360);
	_Camera->eye.z = 1.0f;
	_Camera->up.y = 1.0f;
}

//destructor
Player::~Player()
{
	_Camera = NULL;
	delete _Camera;
	_PlayerObject = NULL;
	delete _PlayerObject;
}

//load player object
void Player::Load()
{
	_PlayerObject->Load();
}

void Player::Draw()
{
	_PlayerObject->Draw();
}

//update player
void Player::Update()
{
	
	//updates camera position and rotation
	glLoadIdentity();
	_PlayerObject->SetPosition(_position.x, _position.y, _position.z);
	_PlayerObject->Update();
	
	gluLookAt(_Camera->eye.x, _Camera->eye.y, _Camera->eye.z, _Camera->center.x, _Camera->center.y, _Camera->center.z, _Camera->up.x, _Camera->up.y, _Camera->up.z);
	glRotatef(_rotation.x, 1, 0, 0);
	glRotatef(_rotation.y, 0, 1, 0);
	glRotatef(_rotation.z, 0, 0, 1);
	glTranslatef(_position.x, _position.y, _position.z);
	
}

void Player::SetPosition(float x, float y, float z)
{
	_position.x += x;
	_position.y += y;
	_position.z += z;
}

void Player::SetRotation(float x, float y, float z)
{
	_rotation.x += x;
	_rotation.y += y;
	_rotation.z += z;
}
