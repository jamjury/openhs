#ifndef OPENHS_PHASE_H
#define OPENHS_PHASE_H


#include "../Event.h"
#include <vector>
#include <memory>

// CombinedEvent is just a group of events
class CombinedEvent : public Event {
	std::vector<Event *> events;

private:
	void act(Board &board) override;
};


#endif //OPENHS_PHASE_H
