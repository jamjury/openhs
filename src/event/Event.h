#ifndef WINSTONE_EVENT_H
#define WINSTONE_EVENT_H


class Board;

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

	virtual void occur();

	virtual void set_board(Board *board);

private:
	/**
	 * All actions happen here
	 * You should never call this. Call occur instead
	 */
	virtual void act() = 0;

	void resolve();
};


#endif //WINSTONE_EVENT_H
