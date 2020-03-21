//#include "Cube.h"
//#include <fstream>
//#include <iostream>
//
//bool Cube::Load(char* path)
//{
//	std::ifstream inFile;
//	inFile.open(path);
//	if (!inFile.good()) 
//	{
//		std::cerr << "Can't open text file " << path << std::endl;
//		return false;
//	}
//
//	inFile.close();
//
//	return true;
//}
//
//Cube::Cube(Mesh* mesh, Texture2D* _texture, float x, float y, float z) : SceneObject(mesh, _texture)
//{
//	//rotation = rand();
//
//	_position.x = x;
//	_position.y = y;
//	_position.z = z;
//
//	_material = new Material();
//	_material->Ambient.w = 1.0;
//	_material->Ambient.x = 0.8;
//	_material->Ambient.y = 0.15;
//	_material->Ambient.z = 0.15;
//	_material->Diffuse.w = 1.0;
//	_material->Diffuse.x = 0.8;
//	_material->Diffuse.y = 0.05;
//	_material->Diffuse.z = 0.05;
//	_material->Specular.w = 1.0;
//	_material->Specular.x = 0.9;
//	_material->Specular.y = 0.35;
//	_material->Specular.z = 0.35;
//	_material->Shininess = 100.0f;
//}
//
//Cube::~Cube()
//{
//
//}
//
//void Cube::Draw()
//{
//	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
//	{
//		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
//		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//
//		_material->Ambient.w = 1.0;
//		_material->Ambient.x = 0.8;
//		_material->Ambient.y = 0.8;
//		_material->Ambient.z = 0.8;
//		_material->Diffuse.w = 1.0;
//		_material->Diffuse.x = 0.8;
//		_material->Diffuse.y = 0.8;
//		_material->Diffuse.z = 0.8;
//		_material->Specular.w = 1.0;
//		_material->Specular.x = 0.9;
//		_material->Specular.y = 0.9;
//		_material->Specular.z = 0.9;
//		_material->Shininess = 100.0f;
//		
//		glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);
//		glPushMatrix();
//
//		
//		glTranslatef(_position.x, _position.y, _position.z);
//
//		glRotatef(rotation, 1.0f, 1.0f, 1.0f);
//
//		glBegin(GL_TRIANGLES);
//		for (int i = 0; i < _mesh->IndexCount; i++)
//		{
//			glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
//			glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.x));
//			glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.x));
//			glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);
//
//			glTexCoord2fv(&_mesh->TexCoords[_mesh->Indices[i]].u);
//			//glColor3fv(&_mesh->Colors[_mesh->Indices[i]].r);
//			glNormal3f(_mesh->Normals[i].x, _mesh->Normals[i].y, _mesh->Normals[i].z);
//			glVertex3fv(&_mesh->Vertices[_mesh->Indices[i]].x);
//		}
//		
//
//		glEnd();
//		glPopMatrix();
//		//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//	}
//}
//
//void Cube::Update()
//{
//	//updates cube rotation
//	if (rotation >= 360.0f)
//	{
//		rotation = 0.0f;
//	}
//}
//
//void Cube::SetRotation(GLfloat newRotation)
//{
//	//increases rotation of cube
//	rotation += newRotation;
//}
