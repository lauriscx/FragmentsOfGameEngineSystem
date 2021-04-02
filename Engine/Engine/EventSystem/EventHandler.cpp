#include "EventHandler.h"
#include "EventManager.h"


EventHandler::EventHandler() : m_Name("Event handler empty") {}
EventHandler::EventHandler(const char * name) : m_Name(name) {}

void EventHandler::SubscribeToEvent		(int eventType) {
	EventManager::GetInstance()->Surscribe(eventType, this);
}
void EventHandler::UnsubscribeToEvent	(int eventType) {
	EventManager::GetInstance()->UnSurscribe(eventType, this);
}
void EventHandler::UnsubscribeToEvents	() {
	EventManager::GetInstance()->UnSurscribe(this);
}

const char * EventHandler::GetHandlerName() {
	return m_Name.c_str();
}

EventHandler::~EventHandler() {
	UnsubscribeToEvents();
}