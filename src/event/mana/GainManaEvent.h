#ifndef OPENHS_GAINMANA_H
#define OPENHS_GAINMANA_H


#include "../CombinedEvent.h"
#include "../PlayerEvent.h"

class GainManaEvent : public CombinedEvent, public PlayerEvent {
public:
	explicit GainManaEvent(unsigned amount);

	void set_board(Board *board) override;
};


#endif //OPENHS_GAINMANA_H
