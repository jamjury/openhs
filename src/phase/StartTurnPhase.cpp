#include "StartTurnPhase.h"
#include "../event/mana/RefreshManaEvent.h"

StartTurnPhase::StartTurnPhase() {
	events.emplace_back(new RefreshManaEvent);
}

void StartTurnPhase::start() {
	// TODO: reset all counters related to 'this turn'
}
