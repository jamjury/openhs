#ifndef WINSTONE_GAINMANA_H
#define WINSTONE_GAINMANA_H


#include "../CombinedEvent.h"

class GainManaEvent : public CombinedEvent {
public:
	explicit GainManaEvent(unsigned amount);
};


#endif //WINSTONE_GAINMANA_H
