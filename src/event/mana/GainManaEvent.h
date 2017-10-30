#ifndef WINSTONE_GAINMANA_H
#define WINSTONE_GAINMANA_H


#include "../CombinedEvent.h"
#include "../PlayerEvent.h"

class GainManaEvent : public CombinedEvent, public PlayerEvent {
public:
	explicit GainManaEvent(unsigned amount);

	void set_board(Board *board) override;
};


#endif //WINSTONE_GAINMANA_H
