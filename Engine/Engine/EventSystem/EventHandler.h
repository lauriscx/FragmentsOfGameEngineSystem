#pragma once
#include "Event.h"
#include <string>

/*
 * Basic Event handler used
 * as interface with event handler.
 * Also used to subscribe and unsubscribe events.
 */

class EventHandler {
public:
	EventHandler();
	EventHandler(const char* name);

	virtual bool	OnEvent				(BasicEvent& event	) = 0;
	void			SubscribeToEvent	(int eventType		);
	void			UnsubscribeToEvent	(int eventType		);
	void			UnsubscribeToEvents	();

	const char *	GetHandlerName();

	virtual ~EventHandler();

private:
	std::string m_Name;
};