#ifndef OPENHS_COMBINEDEVENT_H
#define OPENHS_COMBINEDEVENT_H


#include "Event.h"
#include <memory>

class CombinedEvent : public virtual Event {
	std::unique_ptr<Event> first, second;
public:
	CombinedEvent(
		std::unique_ptr<Event> first,
		std::unique_ptr<Event> second
	);

	void set_board(Board *board) override;

private:
	void act() override;
};


#endif //OPENHS_COMBINEDEVENT_H
