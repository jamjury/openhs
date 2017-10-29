#include "GainTemporaryManaEvent.h"
#include <algorithm>

void GainTemporaryManaEvent::occur(Board &board) {
	Player &player = *board.current_player;
	player.temporary_mana = std::min(
		player.temporary_mana + amount,
		Player::MANA_LIMIT
	);
}

GainTemporaryManaEvent::GainTemporaryManaEvent(unsigned amount) :
	amount(amount)
{}
