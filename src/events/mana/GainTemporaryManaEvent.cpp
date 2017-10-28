#include "GainTemporaryManaEvent.h"
#include <algorithm>

void GainTemporaryManaEvent::occur(Player &player) {
	player.temporary_mana = std::min(
		player.temporary_mana + amount,
		MANA_LIMIT
	);
}

GainTemporaryManaEvent::GainTemporaryManaEvent(int amount) :
	amount(amount)
{}
