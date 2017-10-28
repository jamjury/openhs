#include <algorithm>
#include "GainPermanentManaEvent.h"

void GainPermanentManaEvent::occur(Player &player) {
	player.permanent_mana = std::min(
		player.permanent_mana + amount,
		MANA_LIMIT
	);
}

GainPermanentManaEvent::GainPermanentManaEvent(int amount) :
	amount(amount)
{}
