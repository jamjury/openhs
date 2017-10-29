#include "RefreshManaEvent.h"

void RefreshManaEvent::occur(Board &board) {
	Player &player = *board.current_player;
	player.temporary_mana = player.permanent_mana;
}
