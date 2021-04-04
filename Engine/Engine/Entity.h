#pragma once

#include "Scene.h"

class Scene;

class Entity {
public:
	Entity(entt::entity entity, Scene* m_Scene);

	/*template<typename T, typename... Args>
	T& AddComponent(Args&&... args);

	template<typename T>
	bool hasComponent();

	template<typename T>
	T& getComponent();*/


	template<typename T, typename... Args>
	T& AddComponent(Args&&... args) {
		return m_Scene->m_Registry.emplace<T>(m_entityID, std::forward<Args>(args)...);
	}

	template<typename T>
	bool hasComponent() {
		return m_Scene->m_Registry.has<T>(m_entityID);
	}

	template<typename T>
	T& getComponent() {
		return m_Scene->m_Registry.get<T>(m_entityID);
	}


	~Entity();

private:
	entt::entity m_entityID;
	Scene* m_Scene = nullptr;

};