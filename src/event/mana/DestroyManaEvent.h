#ifndef WINSTONE_DESTROYPERMANENTMANAEVENT_H
#define WINSTONE_DESTROYPERMANENTMANAEVENT_H


#include "../Event.h"

class DestroyManaEvent : public Event {
	unsigned amount;

public:
	explicit DestroyManaEvent(unsigned amount);

	void occur(Board &board) override;
};


#endif //WINSTONE_DESTROYPERMANENTMANAEVENT_H
