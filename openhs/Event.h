#ifndef OPENHS_EVENT_H
#define OPENHS_EVENT_H


class Board;

/**
 * An Event is a change in the board state.
 * For example: Damage Event, Heal Event, Death Event, etc.
 */
class Event {
	/**
	 * All actions happen here.
	 * Override it, but never call. Call occur() instead
	 */
	virtual void act(Board &) = 0;

public:
	virtual ~Event();

	virtual void occur(Board &);
};


#endif //OPENHS_EVENT_H
