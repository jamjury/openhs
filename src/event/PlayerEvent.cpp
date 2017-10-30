#include "PlayerEvent.h"

void PlayerEvent::set_board(Board *board) {
	Event::set_board(board);
	player = board->current_player;
}
