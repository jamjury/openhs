#include "DestroyManaEvent.h"
#include <algorithm>

DestroyManaEvent::DestroyManaEvent(unsigned amount) :
	amount(amount)
{}

void DestroyManaEvent::occur() {
	Player &player = *board->current_player;
	// Destroying not more permanent mana than we have
	unsigned permanent_amount = std::min(player.permanent_mana, amount);
	player.permanent_mana -= permanent_amount;
	// Destroying not more temporaty mana than permanent
	player.temporary_mana -= std::min(player.temporary_mana, permanent_amount);
}
