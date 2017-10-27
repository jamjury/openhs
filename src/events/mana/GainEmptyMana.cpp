#include <algorithm>
#include "GainEmptyMana.h"

void GainEmptyMana::occur(Player &player) {
	player.cur_max_mana = std::min(
		player.cur_max_mana + amount,
		player.MAX_MANA
	);
}

GainEmptyMana::GainEmptyMana(int amount) :
	amount(amount)
{}
