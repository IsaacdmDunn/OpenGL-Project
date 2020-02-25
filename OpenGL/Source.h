
#include <Windows.h>
#include "Structures.h"

#include "Cube.h"
#include "Pyramid.h"

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

private:
	Camera* camera;
	SceneObject* objects[1000];

	Vector3 cameraPosition;

	void DrawCubeArray();
	void DrawIndexedCube();
};

