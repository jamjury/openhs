#include "RefreshManaEvent.h"

void RefreshManaEvent::occur(Player &player) {
	player.temporary_mana = player.permanent_mana;
}
