#include "RefreshMana.h"

void RefreshMana::occur(Player &player) {
	player.temporary_mana = player.permanent_mana;
}
