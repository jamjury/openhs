#ifndef OPENHS_PLAYER_H
#define OPENHS_PLAYER_H


class Zone;

/**
 * Holds player's and his entities's game state. For example: minions, their
 * health and attack values; mana amount; fatigue counter
 */
class Player final {
	int temp_mana;
	int perm_mana;

public:
	static const int MANA_LIMIT;

	Zone *play_zone;
	Zone *hand_zone;
	Zone *deck_zone;

	Player();

	~Player();

	int get_temp_mana() const;

	int get_perm_mana() const;

	/// @returns Amount of permanent mana (after gaining)
	int gain_perm_mana(int amount);

	/// @returns Amount of temporary mana (after gaining)
	int gain_temp_mana(int amount);

	void gain_mana(int amount);

	void destroy_mana(int amount);

	void refresh_mana();
};


#endif //OPENHS_PLAYER_H
