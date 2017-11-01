#ifndef OPENHS_PLAYER_H
#define OPENHS_PLAYER_H


/**
 * Holds player's and his entities's game state. For example: minions, their
 * health and attack values; mana amount; fatigue counter
 */
class Player {
public:
	static const unsigned MANA_LIMIT;

	Player();

	unsigned temp_mana;
	unsigned perm_mana;
};


#endif //OPENHS_PLAYER_H
