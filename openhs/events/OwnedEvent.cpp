#include "OwnedEvent.h"
#include "../Board.h"

void OwnedEvent::act(Board &board) {
	act(board.get_cur_player());
}
