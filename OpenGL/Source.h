
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Structures2.h"
//#include "MeshLoader.h"
#include "objLoader.h"
//#include "Cube.h"
//#include "SceneObject.h"



#define REFRESH_RATE 16

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

	Camera* _Camera;
	Lighting* _Light;

	float rotation = 0.0f;
};

