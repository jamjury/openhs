#ifndef WINSTONE_PLAYEREVENT_H
#define WINSTONE_PLAYEREVENT_H


#include "Event.h"

// Just an Event that has field player (=board.current_player) for DRY code
class PlayerEvent : public Event {
protected:
	Player *player;

public:
	void set_board(Board *board) override;
};


#endif //WINSTONE_PLAYEREVENT_H
