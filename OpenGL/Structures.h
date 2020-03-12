#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#pragma once

struct Vector2
{
	float x, y;
};

struct Vector3
{
	float x, y, z;
};

struct Vector4
{
	float x, y, z, w;
};

struct Material
{
	Vector4 Ambient, Diffuse, Specular;
	GLfloat Shininess;
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

//struct Normals
//{
//	Vector3 normal;
//};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoord
{
	GLfloat u, v;
};

struct Mesh
{
	Vector3* Position;
	Vertex* Vertices;
	Vector3* Normals;
	GLushort* Indices;
	TexCoord* TexCoords;
	int VertexCount, NormalCount, IndexCount, TexCoordCount;
};

struct Lighting
{
	Vector4 Ambient, Diffuse, Specular;
};

//struct for coordinates
struct coordinate
{
    float x, y, z;
    coordinate(float a, float b, float c) : x(a), y(b), z(c) {};
};

//struct for faces
struct face
{
    int facenum;
    bool four;
    int faces[4];

    //triangle structure
    face(int facen, int f1, int f2, int f3) : facenum(facen) {
        faces[0] = f1;
        faces[1] = f2;
        faces[2] = f3;
        four = false;
    }

    //quad structure
    face(int facen, int f1, int f2, int f3, int f4) : facenum(facen) {
        faces[0] = f1;
        faces[1] = f2;
        faces[2] = f3;
        faces[3] = f4;
        four = true;
    }
};

