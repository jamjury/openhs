#include "GainTemporaryMana.h"
#include <algorithm>

void GainTemporaryMana::occur(Player &player) {
	player.temporary_mana = std::min(
		player.temporary_mana + amount,
		MANA_LIMIT
	);
}

GainTemporaryMana::GainTemporaryMana(int amount) :
	amount(amount)
{}
