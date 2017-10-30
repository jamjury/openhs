#ifndef WINSTONE_EVENT_H
#define WINSTONE_EVENT_H


class Board;

#include "../Board.h"

/**
 * An Event is any change in the game state. For example: Damage Event, Heal
 * Event, Death Event, etc. (Additionally, all Phases have an associated
 * Event(s).)
 */
class Event {
protected:
	Board *board;

public:
	Event();
	explicit Event(Board *board);

	virtual void occur() = 0;

	void set_board(Board *board);
};


#endif //WINSTONE_EVENT_H
