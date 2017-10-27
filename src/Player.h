#ifndef WINSTONE_PLAYER_H
#define WINSTONE_PLAYER_H


/**
 * Holds player's and his entities's game state. For example: minions, their
 * health and attack values; mana amount; fatigue counter
 */
class Player {
public:
	static const int MAX_MANA;

    int cur_mana;
    int cur_max_mana;
};


#endif //WINSTONE_PLAYER_H
