#ifndef WINSTONE_DESTROYPERMANENTMANAEVENT_H
#define WINSTONE_DESTROYPERMANENTMANAEVENT_H


#include "../PlayerEvent.h"

class DestroyManaEvent : public PlayerEvent {
	unsigned amount;

public:
	explicit DestroyManaEvent(unsigned amount);

	void occur() override;
};


#endif //WINSTONE_DESTROYPERMANENTMANAEVENT_H
