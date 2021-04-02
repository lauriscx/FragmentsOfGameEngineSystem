#include "EventHandler.h"
#include "EventManager.h"

EventManager * EventManager::GetInstance() {
	static EventManager instance; return &instance;
}

void EventManager::Surscribe	(int eventType, EventHandler * eventHandler) {
	m_EventHandlerEvents.insert(std::make_pair(eventType, eventHandler));
}
void EventManager::UnSurscribe	(int eventType, EventHandler * eventHandler) {
	/* Store 2 pointers from map. First pointer stores address where stars objects with key value,
	 * second stores addres where ends objects with key value.
	 */
	std::pair<std::multimap<int, EventHandler*>::iterator, std::multimap<int, EventHandler*>::iterator> range;
	/*
	 * Get by object range in map.
	 */
	range = m_EventHandlerEvents.equal_range(eventType);
	/*
	 * Iterate through map in specific range.
	 */
	for (std::multimap<int, EventHandler*>::iterator it = range.first; it != range.second; it++) {
		//Send subscripted event to event handler.
		if (it->second == eventHandler) {
			//Remove subscription.
			m_EventHandlerEvents.erase(it);
			break;
		}
	}
}
void EventManager::UnSurscribe	(EventHandler * eventHandler) {
	//Iterate through map.
	for (std::map<int, EventHandler*>::iterator it = m_EventHandlerEvents.begin(); it != m_EventHandlerEvents.end();) {
		//Check is value equal.
		if ((it->second) == eventHandler) {
			//if equal delete and return element who is next. Do not increase pointer.
			it = m_EventHandlerEvents.erase(it);
		} else {
			//If data not equal increase pointer to go through map.
			it++;
		}
	}
}

void EventManager::SendEvent	(BasicEvent * event) {
	/* Store 2 pointers from map. First pointer stores address where stars objects with key value,
	 * second stores addres where ends objects with key value.
	 */
	std::pair<std::multimap<int, EventHandler*>::iterator, std::multimap<int, EventHandler*>::iterator> range;
	/*
	 * Get by object range in map.
	 */
	range = m_EventHandlerEvents.equal_range(event->GetType());
	/*
	 * Iterate thought map in specific range.
	 */
	for (std::multimap<int, EventHandler*>::iterator it = range.first; it != range.second; it++) {
		//Send subscripted event to event handler.
		if (it->second->OnEvent(*event)) {
			break;
		}
	}
}