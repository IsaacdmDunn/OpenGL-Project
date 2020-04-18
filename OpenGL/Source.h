
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#include "GLUTCallbacks.h"
#include "Structures.h"
//#include "MeshLoader.h"
#include "objLoader.h"
#include "Tree.h"
#include "Floor.h"
#include "Texture2D.h"
//#include "Cube.h"
//#include "SceneObject.h"



#define REFRESH_RATE 16
#define TREECOUNT 15

class Source
{
public:
	Source(int arc, char* argv[]);
	~Source(void);
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	//void Display();
	void Render();

	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLighting();

private:
	objLoader objectLoader;
	objLoader Suzanne;
	Texture2D* _BackgroundTexture;
	Tree* _Tree[TREECOUNT];
	Floor* _Floor;

	Camera* _Camera;
	Lighting* _Light;

	float rotation = 0.0f;
};

