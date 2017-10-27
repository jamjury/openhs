#include "GainManaOnce.h"
#include <algorithm>

void GainManaOnce::occur(Player &player) {
	player.cur_mana = std::min(
			player.cur_mana + amount,
			player.cur_max_mana
	);
}

GainManaOnce::GainManaOnce(int amount) :
	amount(amount)
{}
