#include "GainTemporaryManaEvent.h"
#include <algorithm>

void GainTemporaryManaEvent::act() {
	player->temp_mana = std::min(
		player->temp_mana + amount,
		Player::MANA_LIMIT
	);
}

GainTemporaryManaEvent::GainTemporaryManaEvent(unsigned amount) :
	amount(amount)
{}
