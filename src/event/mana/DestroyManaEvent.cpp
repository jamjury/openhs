#include "DestroyManaEvent.h"
#include <algorithm>

DestroyManaEvent::DestroyManaEvent(unsigned amount) :
	amount(amount)
{}

void DestroyManaEvent::act() {
	// Destroying not more permanent mana than we have
	unsigned permanent_destroyed = std::min(
		player->perm_mana,
		amount
	);
	player->perm_mana -= permanent_destroyed;
	// Destroying not more temporaty mana than permanent
	player->temp_mana -= std::min(
		player->temp_mana,
		permanent_destroyed
	);
}
