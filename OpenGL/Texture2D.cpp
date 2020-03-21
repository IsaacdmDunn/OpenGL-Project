//#include <iostream>
//#include <fstream>
//#include "Texture2D.h"
//
//using namespace std;
//
//Texture2D::Texture2D()
//{
//}
//
//Texture2D::~Texture2D()
//{
//	glDeleteTextures(1, &_ID);
//}
//
//bool Texture2D::Load(char* path, int width, int height)
//{
//	char* tempTextureData; int fileSize; ifstream infile;
//	_width = width; _height = height;
//	infile.open(path, ios::binary);
//
//	if (!infile.good())
//	{
//		cerr << "Can't open texture file " << path << endl;
//		return false;
//	}
//
//	infile.seekg(0, ios::end);
//	fileSize = (int)infile.tellg();
//	tempTextureData = new char[fileSize];
//	infile.seekg(0, ios::beg);
//	infile.read(tempTextureData, fileSize);
//	infile.close();
//
//	cout << path << " loaded" << endl;
//
//	glGenTextures(1, &_ID);
//	glBindTexture(GL_TEXTURE_2D, _ID);
//	//glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);
//	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);
//
//	delete[] tempTextureData;
//
//	return true;
//}
