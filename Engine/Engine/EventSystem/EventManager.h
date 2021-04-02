#pragma once
#include <map>

class EventHandler;

class EventManager {
private:
	EventManager() {}

public:
	static EventManager* GetInstance();

protected://Using this functions only EventHandler class.
	void Surscribe	(int eventType, EventHandler* eventHandler);
	void UnSurscribe(int eventType, EventHandler* eventHandler);
	void UnSurscribe(EventHandler* eventHandler);

public:
	void SendEvent	(BasicEvent* event);

private:
	~EventManager() { m_EventHandlerEvents.clear(); }
	EventManager(const EventManager& eventManager) {}
	EventManager& operator=(const EventManager& eventmanager) {}

	std::multimap<int, EventHandler*> m_EventHandlerEvents;

	friend EventHandler;
};