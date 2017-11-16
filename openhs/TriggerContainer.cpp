#include "TriggerContainer.h"
#include "Event.h"

void TriggerContainer::trigger_conseq(Event &event) {
	for (auto &conseq : triggered_events[typeid(event)]) {
		conseq->occur(board);
	}
}

TriggerContainer::TriggerContainer(Board &board)
	: board(board), triggered_events()
{}
