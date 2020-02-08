
#include <Windows.h>
#include "Structures.h"

#include "Cube.h"

#define REFRESH_RATE 16

class Source
{
public:
	Source(int arc, char* argv[]);
	~Source(void);
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void Display();

private:
	Camera* camera;
	Cube* cube[200];

	void DrawCubeArray();
	void DrawIndexedCube();
};

