#include "StartTurnPhase.h"
#include "Board.h"
#include "Player.h"

void StartTurnPhase::act() {
	board->switch_player();
	board->get_current_player()->refresh_mana();
}
