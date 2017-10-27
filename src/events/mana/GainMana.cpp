#include <algorithm>
#include "GainMana.h"

void GainMana::occur(Player &player) {
	player.cur_mana = std::min(
        player.cur_mana + amount,
		player.cur_max_mana
	);
}
