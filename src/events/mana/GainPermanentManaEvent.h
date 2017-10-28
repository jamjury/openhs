#ifndef WINSTONE_GAINEMPTYMANA_H
#define WINSTONE_GAINEMPTYMANA_H


#include "../Event.h"

class GainPermanentManaEvent : public Event {
	unsigned amount;

public:
	explicit GainPermanentManaEvent(unsigned amount);

	void occur(Player &player) override;
};


#endif //WINSTONE_GAINEMPTYMANA_H
