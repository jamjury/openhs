#ifndef WINSTONE_PHASE_H
#define WINSTONE_PHASE_H


#include "../event/Event.h"
#include <vector>
#include <memory>

class Phase {
protected:
	std::vector<std::unique_ptr<Event>> events;

public:
	virtual void start() = 0;
};


#endif //WINSTONE_PHASE_H
