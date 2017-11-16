#include "CombinedEvent.h"

void CombinedEvent::act(Board &board) {
	for (auto &event : events) {
		event->occur(board);
	}
}
