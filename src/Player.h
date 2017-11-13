#ifndef OPENHS_PLAYER_H
#define OPENHS_PLAYER_H


class Zone;

/**
 * Holds player's and his entities's game state. For example: minions, their
 * health and attack values; mana amount; fatigue counter
 */
class Player final {
	unsigned temp_mana;
	unsigned perm_mana;

public:
	static const unsigned MANA_LIMIT;

	Zone *play_zone;
	Zone *hand_zone;
	Zone *deck_zone;

	Player();

	~Player();

	unsigned get_temp_mana() const;

	unsigned get_perm_mana() const;

	/// @returns Amount of permanent mana after gaining
	unsigned gain_perm_mana(unsigned amount);

	/// @returns Amount of temporary mana after gaining
	unsigned gain_temp_mana(unsigned amount);

	void gain_mana(unsigned int amount);

	void destroy_mana(unsigned amount);

	void refresh_mana();
};


#endif //OPENHS_PLAYER_H
