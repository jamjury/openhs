#include "DestroyManaEvent.h"
#include <algorithm>

DestroyManaEvent::DestroyManaEvent(unsigned amount) :
	amount(amount)
{}

void DestroyManaEvent::occur() {
	// Destroying not more permanent mana than we have
	unsigned permanent_destroyed = std::min(
		player->permanent_mana,
		amount
	);
	player->permanent_mana -= permanent_destroyed;
	// Destroying not more temporaty mana than permanent
	player->temporary_mana -= std::min(
		player->temporary_mana,
		permanent_destroyed
	);
}
