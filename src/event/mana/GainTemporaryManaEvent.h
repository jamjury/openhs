#ifndef OPENHS_GAINMANAONCE_H
#define OPENHS_GAINMANAONCE_H


#include "../PlayerEvent.h"

class GainTemporaryManaEvent : public PlayerEvent {
	unsigned amount;
public:
	explicit GainTemporaryManaEvent(unsigned amount);

	void act() override;
};


#endif //OPENHS_GAINMANAONCE_H
