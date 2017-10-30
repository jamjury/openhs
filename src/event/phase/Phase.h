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
	void set_board(Board *board) override;

private:
	void act() override;
};


#endif //WINSTONE_PHASE_H
