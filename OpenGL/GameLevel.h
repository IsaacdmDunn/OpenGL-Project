#pragma once

#include "Player.h"
#include "Tree.h"
#include "Floor.h"
#include "Skybox.h"
#include "Commons.h"

class GameLevel
{
public:
	GameLevel();
	~GameLevel();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void Render();
	void InitObjects();
private:
	Tree* _Tree[TREECOUNT];
	Skybox* _Skybox[SKYBOX_PLANES];
	Floor* _Floor;
	Player* _Player;
};