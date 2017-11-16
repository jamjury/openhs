#include "OriginEvent.h"
#include "../Board.h"

void OriginEvent::occur(Board &board) {
	Event::occur(board);
	resolve(board);
}

void OriginEvent::resolve(Board &board) {
	board.triggers.trigger_conseq(*this);
}
