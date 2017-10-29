#include "Phase.h"

void Phase::occur() {
	Event::occur();
	for (auto &event : events) {
		event->set_board(board);
		event->occur();
	}
}
