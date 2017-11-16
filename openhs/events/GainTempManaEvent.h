#ifndef OPENHS_GAINTEMPMANAEVENT_H
#define OPENHS_GAINTEMPMANAEVENT_H


#include "OwnedEvent.h"

class GainTempManaEvent final : public OwnedEvent {
	int amount;
public:
	explicit GainTempManaEvent(int amount);

private:
	void act(Player &owner) override;
};


#endif //OPENHS_GAINTEMPMANAEVENT_H
