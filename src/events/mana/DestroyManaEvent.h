#ifndef WINSTONE_DESTROYPERMANENTMANAEVENT_H
#define WINSTONE_DESTROYPERMANENTMANAEVENT_H


#include "../Event.h"

class DestroyManaEvent : public Event {
	int amount;

public:
	explicit DestroyManaEvent(int amount);

	void occur(Player &player) override;
};


#endif //WINSTONE_DESTROYPERMANENTMANAEVENT_H
