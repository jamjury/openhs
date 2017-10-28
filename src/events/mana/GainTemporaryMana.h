#ifndef WINSTONE_GAINMANAONCE_H
#define WINSTONE_GAINMANAONCE_H


#include "../Event.h"

class GainTemporaryMana : public Event {
	int amount;
public:
	explicit GainTemporaryMana(int amount);

	void occur(Player &player) override;
};


#endif //WINSTONE_GAINMANAONCE_H
