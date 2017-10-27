#ifndef WINSTONE_COMBINEDEVENT_H
#define WINSTONE_COMBINEDEVENT_H


#include "Event.h"

class CombinedEvent : public Event {
	Event *first, *second;
public:
	CombinedEvent(Event *first, Event *second);

	void occur(Player &player) override;

	virtual ~CombinedEvent();
};


#endif //WINSTONE_COMBINEDEVENT_H
