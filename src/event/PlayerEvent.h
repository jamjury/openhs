#ifndef WINSTONE_PLAYEREVENT_H
#define WINSTONE_PLAYEREVENT_H


#include "Event.h"
#include "Player.h"

// Just an Event that has field player (=board.current_player) for DRY code
class PlayerEvent : public virtual Event {
public:
	Player *player;

	void set_board(Board *board) override;

	void set_player(Player *player);
};


#endif //WINSTONE_PLAYEREVENT_H
