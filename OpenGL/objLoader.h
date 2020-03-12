#pragma once

#include "Structures.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
namespace objLoader
{
	Mesh* Load(char* path);
};