#ifndef WINSTONE_GAINEMPTYMANA_H
#define WINSTONE_GAINEMPTYMANA_H


#include "../Event.h"

class GainEmptyMana : public Event {
	int amount;

public:
	explicit GainEmptyMana(int amount = 1);

	void occur(Player &player) override;
};


#endif //WINSTONE_GAINEMPTYMANA_H
