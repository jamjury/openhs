#include "GainTemporaryMana.h"
#include <algorithm>

void GainTemporaryMana::occur(Player &player) {
	player.temporary_mana = std::min(
			player.temporary_mana + amount,
			player.permanent_mana
	);
}

GainTemporaryMana::GainTemporaryMana(int amount) :
	amount(amount)
{}
