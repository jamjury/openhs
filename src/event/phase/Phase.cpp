#include "Phase.h"

void Phase::occur(Board &board) {
	for (auto event : events)
		event->occur(board);
}
