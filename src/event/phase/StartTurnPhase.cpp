#include "StartTurnPhase.h"
#include "Board.h"
#include "Player.h"

StartTurnPhase::StartTurnPhase() {
	board->switch_player();
	board->current_player->refresh_mana();
}