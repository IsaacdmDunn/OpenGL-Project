#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Windows.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

//struct for 2D vector
struct Vector2 {
	float x, y;

	Vector2(float _x = 0.0f, float _y = 0.0f) {
		x = _x;
		y = _y;
	}

	//overrides operators for 2D vectors to simplify calculations
	bool operator==(const Vector2& other) {
		return (this->x == other.x && this->y == other.y);
	}

	bool operator!=(const Vector2& other) {
		return !(this->x == other.x && this->y == other.y);
	}

	Vector2 operator+(const Vector2& other) {
		return Vector2(this->x + other.x, this->y + other.y);
	}

	Vector2 operator-(const Vector2& other) {
		return Vector2(this->x - other.x, this->y - other.y);
	}

	Vector2 operator*(const Vector2& other) {
		return Vector2(this->x * other.x, this->y * other.y);
	}

	Vector2 operator/(const Vector2& other) {
		return Vector2(this->x / other.x, this->y / other.y);
	}
};

//struct for 3D vector 
struct Vector3 {
	float x, y, z;

	Vector3(float xValue = 0.0f, float yValue = 0.0f, float zValue = 0.0f) {
		x = xValue;
		y = yValue;
		z = zValue;
	}

	//overrides operators for 3D vectors to simplify calculations
	bool operator==(const Vector3& other) const {
		return (this->x == other.x && this->y == other.y && this->z == other.z);
	}

	bool operator!=(const Vector3& other) const {
		return !(this->x == other.x && this->y == other.y && this->z == other.z);
	}

	Vector3 operator+(const Vector3& other) {
		return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
	}

	Vector3 operator-(const Vector3& other) {
		return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	}

	Vector3 operator*(const Vector3& other) {
		return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
	}

	Vector3 operator/(const float& other) const {
		return Vector3(this->x / other, this->y / other, this->z / other);
	}
};

//namespace for math equations
namespace Math {

	//calculates cross product using 2 3D vectors
	Vector3 CrossProduct(const Vector3 vector1, const Vector3 vector2) {
		return Vector3(vector1.y * vector2.z - vector1.z * vector2.y,
			vector1.z * vector2.x - vector1.x * vector1.z,
			vector1.x * vector2.y - vector1.y * vector2.x);
	}

	//finds magnitude
	float Magnitude(const Vector3 in) {
		return (sqrtf(powf(in.x, 2) + powf(in.y, 2) + powf(in.z, 2)));
	}

	//calculates dot product using 2 3D vectors
	float DotProduct(const Vector3 vector1, const Vector3 vector2) {
		return (vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z);
	}

	//finds an angle between 2 3D vectors
	float AngleBetweenVectors(const Vector3 vector1, const Vector3 vector2) {
		float angle = DotProduct(vector1, vector2);
		angle /= Magnitude(vector1) * Magnitude(vector2);
		return angle = acosf(angle);
	}

	//finds the projection of a 3D vector
	Vector3 ProjectionCalculation(const Vector3 vector1, const Vector3 vector2) {
		Vector3 projection = vector2 / Magnitude(vector2);
		return projection * DotProduct(vector1, projection);
	}
}

//namespace for algorithms
namespace Algorithm {
	//overloads * for 3D vectors
	Vector3 operator*(const float& left, const Vector3& right) {
		return Vector3(right.x * left, right.y * left, right.z * left);
	}

	bool SameSide(Vector3 p1, Vector3 p2, Vector3 a, Vector3 b) {
		Vector3 cp1 = Math::CrossProduct(b - a, p1 - a);
		Vector3 cp2 = Math::CrossProduct(b - a, p2 - a);

		if (Math::DotProduct(cp1, cp2) >= 0) {
			return true;
		}
		else
		{
			return false;
		}
	}

	//generates normals for a triangle
	Vector3 GenerateTriangleNormal(Vector3 t1, Vector3 t2, Vector3 t3) {
		Vector3 u = t2 - t1;
		Vector3 v = t3 - t1;

		Vector3 normal = Math::CrossProduct(u, v);

		return normal;
	}

	bool InTriangle(Vector3 point, Vector3 tri1, Vector3 tri2, Vector3 tri3) {
		//Checks to see if the point is within the triangle outlines
		bool withinTriangle = SameSide(point, tri1, tri2, tri3) && SameSide(point, tri2, tri1, tri3) && SameSide(point, tri3, tri1, tri2);

		if (!withinTriangle) {
			return false;
		}

		//Calculates normal point for the triangle
		Vector3 n = GenerateTriangleNormal(tri1, tri2, tri3);

		Vector3 proj = Math::ProjectionCalculation(point, n);

		if (Math::Magnitude(proj) == 0) {
			return true;
		}
		else
		{
			return false;
		}
	}

	//splits a given string
	inline void Split(const std::string& in, std::vector<std::string>& out, std::string token) {
		out.clear();

		std::string temp;

		for (int i = 0; i < int(in.size()); i++)
		{
			std::string test = in.substr(i, token.size());

			if (test == token)
			{
				if (!temp.empty())
				{
					out.push_back(temp);
					temp.clear();
					i += (int)token.size() - 1;
				}
				else
				{
					out.push_back("");
				}
			}
			else if (i + token.size() >= in.size())
			{
				temp += in.substr(i, token.size());
				out.push_back(temp);
				break;
			}
			else
			{
				temp += in[i];
			}
		}
	}

	inline std::string tail(const std::string& in) {
		if (!in.empty()) {
			size_t tokenStart = in.find_first_not_of(" \t");
			size_t spaceStart = in.find_first_of(" \t", tokenStart);
			size_t tailStart = in.find_first_not_of(" \t", spaceStart);
			size_t tailEnd = in.find_last_not_of(" \t");
			if (tailStart != std::string::npos && tailEnd != std::string::npos) {
				return in.substr(tailStart, tailEnd - tokenStart + 1);
			}
			else if (tailStart != std::string::npos) {
				return in.substr(tailStart);
			}
		}
		return "";
	}

	inline std::string firstToken(const std::string& in) {
		if (!in.empty()) {
			size_t tokenStart = in.find_first_not_of(" \t");
			size_t tokenEnd = in.find_first_of(" \t", tokenStart);
			if (tokenStart != std::string::npos && tokenEnd != std::string::npos) {
				return in.substr(tokenStart, tokenEnd - tokenStart);
			}
			else if (tokenStart != std::string::npos)
			{
				return in.substr(tokenStart);
			}
		}
		return "";
	}

	template <class T>
	inline const T& GetElement(const std::vector<T>& elements, std::string& index)
	{
		int idx = std::stoi(index);
		if (idx < 0)
			idx = int(elements.size()) + idx;
		else
			idx--;
		return elements[idx];
	}
}
//struct for vertexes
struct Vertex {
	Vector3 position;
	Vector3 normal;
	Vector2 textureCoordinate;
};

//struct for materials
struct Material
{
	Material() {
		name;
		specularExponent = 0.0f;
		opticalDensity = 0.0f;
		dissolve = 0.0f;
		shininess = 0.0f;
	}

	//material properties
	std::string name;
	Vector3 ambientColour;
	Vector3 diffuseColour; 
	Vector3 specularComponent; 
	float specularExponent; 
	float opticalDensity; 
	float dissolve; 
	float shininess;

	//texture maps
	std::string ambientTextureMap; 
	std::string diffuseTextureMap; 
	std::string specularTextureMap; 
	std::string specularHighlightMap; 
	std::string alphaTextureMap;
	std::string bumpTextureMap; 
};

//struct for meshes
struct Mesh {
	Mesh() {}

	Mesh(std::vector<Vertex>& inVertices, std::vector<unsigned int>& inIndices) : verticies(inVertices), indices(inIndices) {}

	std::string meshName;
	std::vector<Vertex>verticies;
	std::vector<unsigned int>indices;
	Material meshMaterial;
};

//struct for camera
struct Camera 
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
	Vector3 position;
};

//struct for lighting
struct Lighting 
{
	Vector3 ambient;
	Vector3 diffuse;
	Vector3 specular;

	Lighting() 
	{
		ambient = Vector3(1.0f, 0.0f, 0.0f);
		diffuse = Vector3(0.0f, 1.0f, 0.0f);
		specular = Vector3(0.0f, 0.0f, 1.0f);
	}
};

struct CollisionBox 
{
	Vector3 objectDimenions;

	CollisionBox(float width, float height, float length) 
	{
		objectDimenions = Vector3(width, height, length);
	}
};

//returns true or false if the 2 objects passed through have collided
bool CollisionCheck(CollisionBox &collisionBox1, CollisionBox &collisionBox2, Vector3 position1, Vector3 position2)
{
	//bounding box for object 1
	float minAX = position1.x;
	float maxAX = position1.x + collisionBox1.objectDimenions.x;
	float minAY = position1.y;	 
	float maxAY = position1.y + collisionBox1.objectDimenions.y;
	float minAZ = position1.z;	 
	float maxAZ = position1.z + collisionBox1.objectDimenions.z;

	//bounding box for object 2
	float minBX = position2.x;
	float maxBX = position2.x + collisionBox2.objectDimenions.x;
	float minBY = position2.y;
	float maxBY = position2.y + collisionBox2.objectDimenions.y;
	float minBZ = position2.z;
	float maxBZ = position2.z + collisionBox2.objectDimenions.z;

	//if collided return true
	if (minAX <= maxBX && maxAX >= minBX && minAY <= maxBY && maxAY >= minBY && minAZ <= maxBZ && maxAZ >= minBZ) 
	{
		return true;
	}
	else
	{
		return false;
	}
}