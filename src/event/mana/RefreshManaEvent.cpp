#include "RefreshManaEvent.h"

void RefreshManaEvent::occur() {
	Event::occur();
	player->temporary_mana = player->permanent_mana;
}
