#ifndef WINSTONE_PHASE_H
#define WINSTONE_PHASE_H


#include "../Event.h"
#include <vector>
#include <memory>

class Phase : public Event {
protected:
	std::vector<std::unique_ptr<Event>> events;

public:
	void occur(Board &board) override;
};


#endif //WINSTONE_PHASE_H
