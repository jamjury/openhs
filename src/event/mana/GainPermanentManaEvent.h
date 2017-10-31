#ifndef OPENHS_GAINEMPTYMANA_H
#define OPENHS_GAINEMPTYMANA_H


#include "../PlayerEvent.h"

class GainPermanentManaEvent : public PlayerEvent {
	unsigned amount;

public:
	explicit GainPermanentManaEvent(unsigned amount);

	void act() override;
};


#endif //OPENHS_GAINEMPTYMANA_H
