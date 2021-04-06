/*#define DEBUG
#define MEMORY_LEAK
#include "Memory.h"*/

#include "Entt/entt.hpp"
#include "Scene.h"
#include "Entity.h"
#include <string>
#include <iostream>
#include "FileSystem.h"
#include "VFS.h"


#include <fstream>
#include <filesystem>
#include <sstream>

struct Tag {
	Tag() = default;
	Tag(const Tag& _tag) = default;
	Tag(const std::string& _tag) : tag(_tag) {}

	std::string tag;
};

struct Position {
	Position(const float x, const float y, const float z) : x(x), y(y), z(z) {}

	float x, y, z;
};

struct testData {
	int a;
	std::string b;
	float c;
	std::string tekstai[3];
};


int main() {
	VFS vfs;
	vfs.Mount("res", "binary");
	//vfs.Mount("res", "resources/binary");
	//String path = vfs.PhysicalFilePath("/res/TestDataFile.binary");
	//std::cout << path.c_str() << std::endl;

	/*Scene scene;

	Entity entity = scene.createEntity();
	entity.AddComponent<Tag>("Testas");
	entity.AddComponent<Position>(4, 9, 6);

	if (entity.hasComponent<Tag>()) {
		std::cout << entity.getComponent<Tag>().tag.c_str() << std::endl;
	}

	if (entity.hasComponent<Position>()) {
		std::cout << entity.getComponent<Position>().x << " " << entity.getComponent<Position>().y << " " << entity.getComponent<Position>().z << std::endl;
	}*/
	
	{
		testData data;
		data.a = 115;
		data.b = "Tavo reikalas";
		data.c = 45.99f;
		data.tekstai[0] = ("pirmas");
		data.tekstai[1] = ("antras");
		data.tekstai[2] = ("trecias");

		vfs.WriteFile("/res/TestDataFile.binary", (char*)&data, sizeof(testData));
	}

	if (FileSystem::FileExist(vfs.PhysicalFilePath("/res/TestDataFile.binary").c_str())) {
		std::cout << FileSystem::FileSize(vfs.PhysicalFilePath("/res/TestDataFile.binary").c_str()) << std::endl;
	}

	testData NewData;

	if (vfs.ReadFile("/res/TestDataFile.binary", (char*)&NewData, sizeof(testData))) {
		std::cout << NewData.a << " " << NewData.b.c_str() << " " << NewData.c << std::endl;

		std::cout << NewData.tekstai[0].c_str() << std::endl;
		std::cout << NewData.tekstai[1].c_str() << std::endl;
		std::cout << NewData.tekstai[2].c_str() << std::endl;
		/*for (auto a : NewData.tekstai) {
			std::cout << a.c_str() << std::endl;
		}*/
	}

	/*{
		int d = 2;

		Memory::Reference<Entyti> ent = Memory::CreateReference<Entyti>();
	
		int a = 45;
	}*/

	while (true) {

	}

	return 0;
}