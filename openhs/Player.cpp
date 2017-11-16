#include "Player.h"
#include "Zone.h"
#include <vector>

const int Player::MANA_LIMIT = 10;

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

void Player::destroy_mana(int amount) {
	// Destroying not more permanent mana than we have
	auto perm_delta = std::min(perm_mana, amount);
	perm_mana -= perm_delta;
	// Destroying not more temporary mana than permanent
	temp_mana -= std::min(temp_mana, perm_delta);
}

int Player::gain_perm_mana(int amount) {
	return perm_mana = std::min(perm_mana + amount, MANA_LIMIT);
}

int Player::gain_temp_mana(int amount) {
	return temp_mana = std::min(temp_mana + amount, MANA_LIMIT);
}

void Player::gain_mana(int amount) {
	gain_perm_mana(amount);
	gain_temp_mana(amount);
}

void Player::refresh_mana() {
	temp_mana = perm_mana;
}

int Player::get_temp_mana() const {
	return temp_mana;
}

int Player::get_perm_mana() const {
	return perm_mana;
}
