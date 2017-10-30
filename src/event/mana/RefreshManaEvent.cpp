#include "RefreshManaEvent.h"

void RefreshManaEvent::act() {
	player->temporary_mana = player->permanent_mana;
}
