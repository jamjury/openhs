#ifndef WINSTONE_GAINEMPTYMANA_H
#define WINSTONE_GAINEMPTYMANA_H


#include "../Event.h"

class GainPermanentManaEvent : public Event {
	int amount;

public:
	explicit GainPermanentManaEvent(int amount = 1);

	void occur(Player &player) override;
};


#endif //WINSTONE_GAINEMPTYMANA_H
