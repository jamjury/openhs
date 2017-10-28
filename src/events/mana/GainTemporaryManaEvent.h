#ifndef WINSTONE_GAINMANAONCE_H
#define WINSTONE_GAINMANAONCE_H


#include "../Event.h"

class GainTemporaryManaEvent : public Event {
	int amount;
public:
	explicit GainTemporaryManaEvent(int amount);

	void occur(Player &player) override;
};


#endif //WINSTONE_GAINMANAONCE_H
