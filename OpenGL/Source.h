//libraries
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdlib.h>     
#include <time.h>    
#include <iostream>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "objLoader.h"
#include "Texture2D.h"
#include "Commons.h"
#include "GameLevel.h"

class Source
{
public:
	Source(int arc, char* argv[]);
	~Source(void);
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void Render();

	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLighting();

private:
	Texture2D* _BackgroundTexture;
	Lighting* _Light;
	GameLevel* _GameLevel;

	float rotation = 0.0f;
};

