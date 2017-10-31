#ifndef OPENHS_CHANGEPLAYEREVENT_H
#define OPENHS_CHANGEPLAYEREVENT_H


#include "Event.h"

class ChangePlayerEvent : public Event {
public:
	void act() override;
};


#endif //OPENHS_CHANGEPLAYEREVENT_H
