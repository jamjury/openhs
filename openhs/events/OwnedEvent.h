#ifndef OPENHS_PLAYEREVENT_H
#define OPENHS_PLAYEREVENT_H


#include "../Event.h"
#include "../Player.h"

// Event that has field player (=board.cur_player)
// Helper class.
class OwnedEvent : public virtual Event {
	void act(Board &) final;

	virtual void act(Player &owner) = 0;
};


#endif //OPENHS_PLAYEREVENT_H
