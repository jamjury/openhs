#ifndef WINSTONE_GAINMANAONCE_H
#define WINSTONE_GAINMANAONCE_H


#include "../Event.h"

class GainManaOnce : public Event {
	int amount;
public:
	GainManaOnce(int amount);

	void occur(Player &player) override;
};


#endif //WINSTONE_GAINMANAONCE_H
