//libraries
#include "GameLevel.h"

//constructor
GameLevel::GameLevel()
{
	gameIntroText = "It hungers...";
}

//destructor
GameLevel::~GameLevel()
{
	/*for (int i = 0; i < TREECOUNT; i++)
	{
		_Tree[i] = NULL;
	}
	delete[] _Tree;*/
	_Trees.clear();
	for (int i = 0; i < SKYBOX_PLANES; i++)
	{
		_Skybox[i] = NULL;
	}
	delete[] _Skybox;
	delete _Floor;
	delete _Ring;
	delete _Moon;
}

//updates level 
void GameLevel::Update()
{
	//update game objects
	_Player->Update();

	//if trees are in vector
	if (!_Trees.empty())
	{
		//draw each tree
		for (unsigned int i = 0; i < _Trees.size(); i++)
		{
			_Trees[i]->Update();
		}
	}

	_Floor->Update();
	_Ring->Update();
	_Moon->Update();


	
	if (CollisionCheck(*_Player->_CollisionBox, *_Ring->_CollisionBox, _Player->GetPosition(), _Ring->GetPosition()) == true)
	{
		std::cout << CollisionCheck(*_Player->_CollisionBox, *_Ring->_CollisionBox, _Player->GetPosition(), _Ring->GetPosition()) << " Ring: X" << _Ring->GetPosition().x << "Z" << _Ring->GetPosition().y << " Player: X" << _Player->GetPosition().x << "Y" << _Player->GetPosition().y << std::endl;


		_Ring->SetPosition(rand() % 100, 5, rand() % 100);
		_Moon->SetPosition(0, 5 + _Moon->GetYPosition(), 0);
		_Score++;
	}
	
	std::cout << _Moon->GetYPosition() << std::endl;

	//if moon hits the floor
	if (_Moon->GetYPosition() < MOON_DESTINATION)
	{
		
		gameIntroText = "Your sacriface is inexcusable and your fate has been sealed";
	}
	else if (_Moon->GetYPosition() < MOON_TEXT_REMOVE)
	{
		gameIntroText = " ";
	}
	
}

//update keybpard inputs
void GameLevel::Keyboard(unsigned char key, int x, int y)
{
	Vector3 playerPosition;
	Vector3 playerRotation;

	//moves camera with WASD controls
	if (key == 'd')
	{
		playerPosition.x -= MOVEMENT_SPEED;

	}
	else if (key == 'a')
	{
		playerPosition.x += MOVEMENT_SPEED;
	}
	if (key == 'w')
	{
		playerPosition.z += MOVEMENT_SPEED;
	}
	else if (key == 's')
	{
		playerPosition.z -= MOVEMENT_SPEED;
	}
	//rotates camera with Q for left and E for right
	if (key == 'q')
	{
		playerRotation.y -= TURING_SPEED;
	}
	else if (key == 'e')
	{
		playerRotation.y += TURING_SPEED;
	}
	//rotates camera with Q for left and E for right
	if (key == 'r')
	{
		playerRotation.x -= TURING_SPEED;
	}
	else if (key == 'f')
	{
		playerRotation.x += TURING_SPEED;
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

//renders level
void GameLevel::Render()
{
	//clear buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//draws background outside skybox 
	DisableProjectedView();
	glBindTexture(GL_TEXTURE_2D, _BackgroundTexture->GetID());
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_TEXTURE_COORD_ARRAY);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2i(0, 0);
	glVertex2i(-1, -1);
	glTexCoord2i(1, 0);
	glVertex2i(1, -1);
	glTexCoord2i(1, 1);
	glVertex2i(1, 1);
	glTexCoord2i(0, 1);
	glVertex2i(-1, 1);
	glEnd();
	glDisable(GL_TEXTURE_COORD_ARRAY);
	EnableProjectedView();

	//skybox drawn with stars.raw
	for (int i = 0; i < SKYBOX_PLANES; i++)
	{
		_Skybox[i]->Draw();
	}

	//no texture
	glBindTexture(GL_TEXTURE_2D, 0);
	
	//if trees are in vector
	if (!_Trees.empty())
	{
		//draw each tree
		for (unsigned int i = 0; i < _Trees.size(); i++)
		{
			_Trees[i]->Draw();
		}
	}

	_Floor->Draw();
	_Ring->Draw();
	_Moon->Draw();
	_Player->Draw();

	//render HUD
	glBindTexture(GL_TEXTURE_2D, 0);
	DisableProjectedView();
	scoreText = "Score: " + std::to_string(_Score);
	//gameIntroText = "It hungers...";
	//score text
	glPushMatrix();
	glRasterPos2f(-0.95f, 0.9f); //Sets the texts position in relation to NDC (Normalized Device Coordinates [-1 to 1])
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)scoreText.c_str()); //Sets the font and the text
	glPopMatrix();

	//intro text
	glPushMatrix();
	glRasterPos2f(-0.50f, 0.0f); //Sets the texts position in relation to NDC (Normalized Device Coordinates [-1 to 1])
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)gameIntroText.c_str()); //Sets the font and the text
	glPopMatrix();
	EnableProjectedView();

	//ends render
	glFlush();
	glutSwapBuffers();
}

//initialises objects
void GameLevel::InitObjects()
{
	//player
	_Player = new Player(50, -6, 50, Vector3(0, 0, 0));
	_Player->Load();

	//trees
	for (int i = 0; i < TREECOUNT; i++)
	{
		CreateTrees();
		_Tree->Load();
	}
	

	//floor
	_Floor = new Floor(0, -0.5, 0, Vector3(0, 0, 0));
	_Floor->Load();
	
	//rings
	_Ring = new Ring(20, 5, 20, Vector3(0, 0, 0));
	_Ring->Load();
	
	//moon
	_Moon = new Moon(20, 150, 20, Vector3(0, 200, 0));
	_Moon->Load();

	//skybox
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

	//background texture
	_BackgroundTexture = new Texture2D();
	_BackgroundTexture->Load((char*)"Assets/stars.raw", 512, 512);
}

//disables projection allowing 2D objects to be drawn
void GameLevel::DisableProjectedView()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
}

//enables projection allowing 3D objects to be drawn
void GameLevel::EnableProjectedView()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void GameLevel::UpdateTrees()
{
}

void GameLevel::RenderTrees()
{
}

void GameLevel::CreateTrees()
{
	_Tree = new Tree(rand() % 200 - 100, -0.5, rand() % 200 - 100, Vector3(0, rand() % 360, 0));
	_Trees.push_back(_Tree);
}
