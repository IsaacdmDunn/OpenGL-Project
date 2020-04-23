#include "GameLevel.h"

GameLevel::GameLevel()
{
}

GameLevel::~GameLevel()
{
	for (int i = 0; i < TREECOUNT; i++)
	{
		_Tree[i] = NULL;
	}
	delete[] _Tree;
	for (int i = 0; i < SKYBOX_PLANES; i++)
	{
		_Skybox[i] = NULL;
	}
	delete[] _Skybox;
	delete _Floor;
	delete _Ring;
	delete _Moon;
}

void GameLevel::Update()
{
	_Player->Update();

	for (int i = 0; i < TREECOUNT; i++)
	{
		_Tree[i]->Update();
	}

	_Floor->Update();
	_Ring->Update();
	_Moon->Update();
}

void GameLevel::Keyboard(unsigned char key, int x, int y)
{
	Vector3 playerPosition;
	Vector3 playerRotation;

	//moves camera with WASD controls
	if (key == 'd')
	{
		playerPosition.x -= 1.1;

	}
	else if (key == 'a')
	{
		playerPosition.x += 1.1;
	}
	if (key == 'w')
	{
		playerPosition.z += 1.1;
	}
	else if (key == 's')
	{
		playerPosition.z -= 1.1;
	}
	//rotates camera with Q for left and E for right
	if (key == 'q')
	{
		playerRotation.y -= 2.1;
	}
	else if (key == 'e')
	{
		playerRotation.y += 2.1;
	}
	//rotates camera with Q for left and E for right
	if (key == 'r')
	{
		playerRotation.x -= 2.1;
	}
	else if (key == 'f')
	{
		playerRotation.x += 2.1;
	}

	//sets the position and rotation for the player
	_Player->SetPosition(playerPosition.x, playerPosition.y, playerPosition.z);
	_Player->SetRotation(playerRotation.x, playerRotation.y, playerRotation.z);

	_Skybox[0]->SetPosition(playerPosition.x, playerPosition.y, playerPosition.z);
	_Skybox[1]->SetPosition(playerPosition.x, playerPosition.y, playerPosition.z);
	_Skybox[2]->SetPosition(playerPosition.x, playerPosition.y, playerPosition.z);
	_Skybox[3]->SetPosition(playerPosition.x, playerPosition.y, playerPosition.z);
	_Skybox[4]->SetPosition(playerPosition.x, playerPosition.y, playerPosition.z);
}

void GameLevel::Render()
{
	for (int i = 0; i < SKYBOX_PLANES; i++)
	{
		_Skybox[i]->Draw();
	}


	glBindTexture(GL_TEXTURE_2D, 0);
	
	for (int i = 0; i < TREECOUNT; i++)
	{
		_Tree[i]->Draw();
	}

	_Floor->Draw();
	_Ring->Draw();
	_Moon->Draw();
	_Player->Draw();
}

void GameLevel::InitObjects()
{
	_Player = new Player(50, -6, 50, Vector3(0, 0, 0));
	_Player->Load();

	_Tree[0] = new Tree(0, -0.5, 0, rand() % 360);
	_Tree[0]->Load();
	_Tree[1] = new Tree(-120, -0.5, -5, rand() % 360);
	_Tree[1]->Load();
	_Tree[2] = new Tree(-24, -0.5, -2, rand() % 360);
	_Tree[2]->Load();
	_Tree[3] = new Tree(30, -0.5, -4, rand() % 360);
	_Tree[3]->Load();
	_Tree[4] = new Tree(5, -0.5, -10, rand() % 360);
	_Tree[4]->Load();
	_Tree[5] = new Tree(16, -0.5, -15, rand() % 360);
	_Tree[5]->Load();
	_Tree[6] = new Tree(-18, -0.5, -14, rand() % 360);
	_Tree[6]->Load();
	_Tree[7] = new Tree(-35, -0.5, -12, rand() % 360);
	_Tree[7]->Load();
	_Tree[8] = new Tree(10, -0.5, -19, rand() % 360);
	_Tree[8]->Load();
	_Tree[9] = new Tree(9, -0.5, -25, rand() % 360);
	_Tree[9]->Load();
	_Tree[10] = new Tree(33, -0.5, -22, rand() % 360);
	_Tree[10]->Load();
	_Tree[11] = new Tree(-11, -0.5, -30, rand() % 360);
	_Tree[11]->Load();
	_Tree[12] = new Tree(-33, -0.5, -32, rand() % 360);
	_Tree[12]->Load();
	_Tree[13] = new Tree(22, -0.5, -19, rand() % 360);
	_Tree[13]->Load();
	_Tree[14] = new Tree(15, -0.5, -20, rand() % 360);
	_Tree[14]->Load();

	_Floor = new Floor(0, -0.5, 0);
	_Floor->Load();
	
	_Ring = new Ring(20, 5, 20, 0);
	_Ring->Load();
	
	_Moon = new Moon(20, 150, 20, 200);
	_Moon->Load();

	_Skybox[0] = new Skybox(0, 250, 0, Vector3(0, 0, 0));
	_Skybox[0]->Load();
	_Skybox[1] = new Skybox(0, 50, 150, Vector3(90, 0, 0));
	_Skybox[1]->Load();
	_Skybox[2] = new Skybox(150, 50, 0, Vector3(90, 0, 90));
	_Skybox[2]->Load();
	_Skybox[3] = new Skybox(0, 50, -150, Vector3(90, 0, 180));
	_Skybox[3]->Load();
	_Skybox[4] = new Skybox(-150, 50, 0, Vector3(90, 0, 270));
	_Skybox[4]->Load();
}