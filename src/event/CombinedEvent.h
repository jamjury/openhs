#ifndef OPENHS_COMBINEDEVENT_H
#define OPENHS_COMBINEDEVENT_H


#include "Event.h"
#include <memory>

class CombinedEvent : public virtual Event {
	Event *first, *second;
public:
	// Will remove both events on destruction
	CombinedEvent(
		Event *first,
		Event *second
	);

	virtual ~CombinedEvent();

	void set_board(Board *board) override;

private:
	void act() override;
};


#endif //OPENHS_COMBINEDEVENT_H
