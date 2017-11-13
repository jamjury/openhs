#ifndef OPENHS_PLAYEREVENT_H
#define OPENHS_PLAYEREVENT_H


#include "Event.h"
#include "Player.h"

// Event that has field player (=board.cur_player)
// Helper class.
class PlayerEvent : public virtual Event {
public:
	Player *player;

	void set_board(Board *board) override;

	void set_player(Player *player);
};


#endif //OPENHS_PLAYEREVENT_H
