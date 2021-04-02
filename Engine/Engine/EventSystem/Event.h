#pragma once

/*
 * Basic event class
 */

class BasicEvent {
public:
	BasicEvent() {}
	
	virtual int			GetType	()	{ return false;		}
	virtual const char* toString()	{ return "Event";	}

	virtual ~BasicEvent() {}
};