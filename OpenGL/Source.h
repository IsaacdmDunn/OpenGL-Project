
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"


#include "GLUTCallbacks.h"
#include "Structures.h"
#include "MeshLoader.h"
#include "Cube.h"
#include "SceneObject.h"

#define REFRESH_RATE 16

class Source
{
public:
	Source(int arc, char* argv[]);
	~Source(void);
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void Display();

	void InitObjects();
	void InitGL(int argc, char* argv[]);
	void InitLighting();

private:
	Camera* camera;
	SceneObject* objects[1000];

	Vector3 cameraPosition;
	Vector4* _lightPosition;
	Lighting* _lightData;
};

