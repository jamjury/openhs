#include "StartTurnPhase.h"

void StartTurnPhase::act(Board &board) {
	board.switch_player();
	board.get_cur_player().refresh_mana();
}
