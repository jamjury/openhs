#include "StartTurnPhase.h"
#include "../ChangePlayerEvent.h"
#include "../mana/RefreshManaEvent.h"

StartTurnPhase::StartTurnPhase() {
	events.emplace_back(new ChangePlayerEvent);
	events.emplace_back(new RefreshManaEvent);
}

void StartTurnPhase::occur(Board &board) {
	Phase::occur(board);
	// TODO: reset all counters related to 'this turn'
}
