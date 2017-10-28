#ifndef WINSTONE_PLAYER_H
#define WINSTONE_PLAYER_H


/**
 * Holds player's and his entities's game state. For example: minions, their
 * health and attack values; mana amount; fatigue counter
 */
class Player {
public:
	Player();

    int temporary_mana;
    int permanent_mana;
};

static const int MANA_LIMIT = 10;

#endif //WINSTONE_PLAYER_H
