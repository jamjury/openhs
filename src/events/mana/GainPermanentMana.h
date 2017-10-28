#ifndef WINSTONE_GAINEMPTYMANA_H
#define WINSTONE_GAINEMPTYMANA_H


#include "../Event.h"

class GainPermanentMana : public Event {
	int amount;

public:
	explicit GainPermanentMana(int amount = 1);

	void occur(Player &player) override;
};


#endif //WINSTONE_GAINEMPTYMANA_H
