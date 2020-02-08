#include "GLUTCallbacks.h"
#include "Source.h"

#define REFRESH_RATE 16

namespace GLUTCallbacks 
{
	namespace 
	{
		Source* source = nullptr;
	}

	void Init(Source* gl)
	{
		source = gl;
	}

	void Timer(int preferredRefresh)
	{

		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		source->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		source->Keyboard(key, x, y);
	}

	void Display()
	{
		if (source != nullptr)
		{
			source->Display();
		}
	}
}