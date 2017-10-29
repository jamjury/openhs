#ifndef WINSTONE_GAINMANAONCE_H
#define WINSTONE_GAINMANAONCE_H


#include "../Event.h"

class GainTemporaryManaEvent : public Event {
	unsigned amount;
public:
	explicit GainTemporaryManaEvent(unsigned amount);

	void occur() override;
};


#endif //WINSTONE_GAINMANAONCE_H
