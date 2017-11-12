#include "Player.h"
#include "Zone.h"

Player::Player() {
	perm_mana = 0;
	temp_mana = 0;
	play_zone = new Zone(7);
	hand_zone = new Zone(10);
	// Wonder why so? See advanced rulebook
	deck_zone = new Zone(60);
}

Player::~Player() {
	delete play_zone;
	delete hand_zone;
	delete deck_zone;
}

const unsigned Player::MANA_LIMIT = 10;
