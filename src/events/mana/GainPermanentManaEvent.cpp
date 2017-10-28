#include "GainPermanentManaEvent.h"
#include <algorithm>

void GainPermanentManaEvent::occur(Player &player) {
	player.permanent_mana = std::min(
		player.permanent_mana + amount,
		Player::MANA_LIMIT
	);
}

GainPermanentManaEvent::GainPermanentManaEvent(int amount) :
	amount(amount)
{}
