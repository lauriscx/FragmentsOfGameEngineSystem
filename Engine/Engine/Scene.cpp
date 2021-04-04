#include "Scene.h"
#include "Entity.h"


Scene::Scene() {}

Entity Scene::createEntity() {
	Entity entity = { m_Registry.create(), this };
	return entity;
}

Scene::~Scene() {}