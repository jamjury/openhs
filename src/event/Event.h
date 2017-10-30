#ifndef WINSTONE_EVENT_H
#define WINSTONE_EVENT_H


class Board;

#include "../Board.h"

/**
 * An Event is any change in the game state (Board). For example: Damage Event,
 * Heal Event, Death Event, etc.
 */
class Event {
protected:
	Board *board;

public:
	Event();
	explicit Event(Board *board);

	virtual void occur() = 0;

	virtual void set_board(Board *board);
};


#endif //WINSTONE_EVENT_H
