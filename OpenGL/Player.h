#pragma once
#include "objLoader.h"
#include "Tree.h"

class Player : public objLoader
{
private:
	objLoader objectLoader;
	Vector3 _position;
	Vector3 _rotation;
	Camera* _Camera;
	Tree* _PlayerObject;
	Material* _material;

protected:


public:
	Player(/*Texture2D* _texture,*/ float x, float y, float z, Vector3 rotation);
	~Player();
	void Load();
	virtual void Draw();
	virtual void Update();

	void SetPosition(float x, float y, float z);
	Vector3 GetPosition() { return _position.x, _position.y, _position.z; }

	void SetRotation(float x, float y, float z);
	Vector3 GetRotation() { return _rotation.x, _rotation.y, _rotation.z; }
};
