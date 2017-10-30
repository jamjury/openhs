#include "Phase.h"

void Phase::act() {
	for (auto &event : events) {
		event->occur();
	}
}

void Phase::set_board(Board *board) {
	Event::set_board(board);
	for (auto &event : events) {
		event->set_board(board);
	}
}
