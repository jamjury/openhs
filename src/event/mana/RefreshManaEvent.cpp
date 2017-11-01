#include "RefreshManaEvent.h"

void RefreshManaEvent::act() {
	player->temp_mana = player->perm_mana;
}
