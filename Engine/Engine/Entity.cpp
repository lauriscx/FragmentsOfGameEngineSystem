#include "Entity.h"

Entity::Entity(entt::entity entity, Scene * Scene) : m_entityID(entity), m_Scene(Scene) {}

/*template<typename T, typename... Args>
T& Entity::AddComponent(Args&&... args) {
	return m_Scene->m_Registry.emplace<T>(m_entityID, std::forward<Args>(args)...);
}

template<typename T>
bool Entity::hasComponent() {
	return m_Scene->m_Registry.has<T>(m_entityID);
}

template<typename T>
T& Entity::getComponent() {
	return m_Scene->m_Registry.get<T>(m_entityID);
}*/

Entity::~Entity() {}