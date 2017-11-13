#include "Player.h"
#include "Zone.h"
#include <vector>

const unsigned Player::MANA_LIMIT = 10;

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

void Player::destroy_mana(unsigned amount) {
	// Destroying not more permanent mana than we have
	auto perm_delta = std::min(perm_mana, amount);
	perm_mana -= perm_delta;
	// Destroying not more temporary mana than permanent
	temp_mana -= std::min(temp_mana, perm_delta);
}

unsigned Player::gain_perm_mana(unsigned amount) {
	return perm_mana = std::min(perm_mana + amount, MANA_LIMIT);
}

unsigned Player::gain_temp_mana(unsigned amount) {
	return temp_mana = std::min(temp_mana + amount, MANA_LIMIT);
}

void Player::gain_mana(unsigned amount) {
	gain_perm_mana(amount);
	gain_temp_mana(amount);
}

void Player::refresh_mana() {
	temp_mana = perm_mana;
}

unsigned Player::get_temp_mana() const {
	return temp_mana;
}

unsigned Player::get_perm_mana() const {
	return perm_mana;
}
