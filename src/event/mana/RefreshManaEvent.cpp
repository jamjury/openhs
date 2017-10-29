#include "RefreshManaEvent.h"

void RefreshManaEvent::occur() {
	Event::occur();
	Player &player = *board->current_player;
	player.temporary_mana = player.permanent_mana;
}
