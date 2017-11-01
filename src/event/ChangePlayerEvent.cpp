#include "ChangePlayerEvent.h"
#include "../Board.h"

void ChangePlayerEvent::act() {
	board->current_player = board->current_opponent();
}
