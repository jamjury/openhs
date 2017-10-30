#include "GainTemporaryManaEvent.h"
#include <algorithm>

void GainTemporaryManaEvent::act() {
	player->temporary_mana = std::min(
		player->temporary_mana + amount,
		Player::MANA_LIMIT
	);
}

GainTemporaryManaEvent::GainTemporaryManaEvent(unsigned amount) :
	amount(amount)
{}
