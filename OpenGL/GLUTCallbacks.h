#pragma once
class Source;
namespace GLUTCallbacks
{
	void Init(Source* gl);

	void Timer(int preferredRefresh);

	void Keyboard(unsigned char key, int x, int y);

	void Display();
}