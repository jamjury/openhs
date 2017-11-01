#include "GainPermanentManaEvent.h"
#include <algorithm>

void GainPermanentManaEvent::act() {
	player->perm_mana = std::min(
		player->perm_mana + amount,
		Player::MANA_LIMIT
	);
}

GainPermanentManaEvent::GainPermanentManaEvent(unsigned amount) :
	amount(amount)
{}
