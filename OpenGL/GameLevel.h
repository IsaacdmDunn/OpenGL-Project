#pragma once

//libraries
#include <vector>
#include "Player.h"
#include "Tree.h"
#include "Ring.h"
#include "Moon.h"
#include "Floor.h"
#include "Skybox.h"
#include "Commons.h"

//game level class
class GameLevel
{
//public
public:
	GameLevel();
	~GameLevel();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void Render();
	void InitObjects();

//private
private:
	Tree* _Tree;
	std::vector<Tree*> _Trees;
	
	Skybox* _Skybox[SKYBOX_PLANES];
	Ring* _Ring;
	Moon* _Moon;
	Floor* _Floor;
	Player* _Player;
	Texture2D* _BackgroundTexture;

	int _Score = 0;
	std::string scoreText;
	std::string gameIntroText;

	void DisableProjectedView();
	void EnableProjectedView();
	void CreateTrees();
	void UpdateTrees();
	void RenderTrees();
};