#include "GainPermanentManaEvent.h"
#include <algorithm>

void GainPermanentManaEvent::occur(Board &board) {
	Player &player = *board.current_player;
	player.permanent_mana = std::min(
		player.permanent_mana + amount,
		Player::MANA_LIMIT
	);
}

GainPermanentManaEvent::GainPermanentManaEvent(unsigned amount) :
	amount(amount)
{}
