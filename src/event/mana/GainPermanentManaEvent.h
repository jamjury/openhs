#ifndef WINSTONE_GAINEMPTYMANA_H
#define WINSTONE_GAINEMPTYMANA_H


#include "../PlayerEvent.h"

class GainPermanentManaEvent : public PlayerEvent {
	unsigned amount;

public:
	explicit GainPermanentManaEvent(unsigned amount);

	void act() override;
};


#endif //WINSTONE_GAINEMPTYMANA_H
