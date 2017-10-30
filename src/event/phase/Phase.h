#ifndef WINSTONE_PHASE_H
#define WINSTONE_PHASE_H


#include "../Event.h"
#include <vector>
#include <memory>

// Phase is just a group of events
class Phase : public Event {
protected:
	std::vector<std::unique_ptr<Event>> events;

public:
	void occur() override;
};


#endif //WINSTONE_PHASE_H
