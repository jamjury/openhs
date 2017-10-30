#ifndef WINSTONE_GAINMANAONCE_H
#define WINSTONE_GAINMANAONCE_H


#include "../PlayerEvent.h"

class GainTemporaryManaEvent : public PlayerEvent {
	unsigned amount;
public:
	explicit GainTemporaryManaEvent(unsigned amount);

	void act() override;
};


#endif //WINSTONE_GAINMANAONCE_H
