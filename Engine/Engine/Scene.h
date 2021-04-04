#pragma once
#include "Entt/entt.hpp"


/*
 * Scene is like level or world.
 * In scene is saved all entities(objects) which exist.
 */

class Entity;

class Scene {
public:
	Scene();

	Entity createEntity();

	~Scene();
private:
	friend Entity;
	entt::registry m_Registry;
};

