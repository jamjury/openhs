#ifndef WINSTONE_EVENT_H
#define WINSTONE_EVENT_H


#include "../Board.h"

/**
 * An Event is any change in the game state. For example: Damage Event, Heal
 * Event, Death Event, etc. (Additionally, all Phases have an associated
 * Event(s).)
 */
class Event {
public:
	virtual void occur(Board &board) = 0;
};


#endif //WINSTONE_EVENT_H
