/*#define DEBUG
#define MEMORY_LEAK
#include "Memory.h"*/

#include "Entt/entt.hpp"
#include "Scene.h"
#include "Entity.h"
#include <string>
#include <iostream>

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


int main() {
	Scene scene;

	Entity entity = scene.createEntity();
	entity.AddComponent<Tag>("Testas");
	entity.AddComponent<Position>(4, 9, 6);

	if (entity.hasComponent<Tag>()) {
		std::cout << entity.getComponent<Tag>().tag.c_str() << std::endl;
	}

	if (entity.hasComponent<Position>()) {
		std::cout << entity.getComponent<Position>().x << " " << entity.getComponent<Position>().y << " " << entity.getComponent<Position>().z << std::endl;
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