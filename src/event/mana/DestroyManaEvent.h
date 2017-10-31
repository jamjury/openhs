#ifndef OPENHS_DESTROYPERMANENTMANAEVENT_H
#define OPENHS_DESTROYPERMANENTMANAEVENT_H


#include "../PlayerEvent.h"

class DestroyManaEvent : public PlayerEvent {
	unsigned amount;

public:
	explicit DestroyManaEvent(unsigned amount);

	void act() override;
};


#endif //OPENHS_DESTROYPERMANENTMANAEVENT_H
