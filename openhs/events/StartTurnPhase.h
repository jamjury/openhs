#ifndef OPENHS_STARTTURNPHASE_H
#define OPENHS_STARTTURNPHASE_H


#include "OriginEvent.h"

class StartTurnPhase final : public OriginEvent {
	void act(Board &) override;
};


#endif //OPENHS_STARTTURNPHASE_H
