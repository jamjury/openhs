#ifndef WINSTONE_STARTTURNPHASE_H
#define WINSTONE_STARTTURNPHASE_H


#include "Phase.h"

class StartTurnPhase : public Phase {
public:
	StartTurnPhase();

	void occur(Board &board) override;
};


#endif //WINSTONE_STARTTURNPHASE_H
