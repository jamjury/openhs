#ifndef OPENHS_PLAYER_H
#define OPENHS_PLAYER_H


class Zone;

/**
 * Holds player's and his entities's game state. For example: minions, their
 * health and attack values; mana amount; fatigue counter
 */
struct Player {
	static const unsigned MANA_LIMIT;
	static const unsigned PLAY_SIZE;

	unsigned temp_mana;
	unsigned perm_mana;
	Zone *play_zone;
	Zone *hand_zone;
	Zone *deck_zone;

	Player();

	virtual ~Player();
};


#endif //OPENHS_PLAYER_H
