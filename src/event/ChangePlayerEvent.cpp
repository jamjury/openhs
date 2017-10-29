#include <Board.h>
#include "ChangePlayerEvent.h"

void ChangePlayerEvent::occur() {
	Event::occur();
	board->current_player = board->current_player == board->player_two ?
		board->player_one : board->player_two;
}
