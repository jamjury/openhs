#ifndef WINSTONE_GAINMANA_H
#define WINSTONE_GAINMANA_H


#include "../CombinedEvent.h"

class GainMana : public CombinedEvent {
public:
	explicit GainMana(int amount);
};


#endif //WINSTONE_GAINMANA_H
