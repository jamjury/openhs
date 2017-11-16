#ifndef OPENHS_BOARD_H
#define OPENHS_BOARD_H

#include "Player.h"
#include "TriggerContainer.h"

class Board final {
	Player player1, player2;
	// A player that makes a move
	Player *cur_player;

public:
	TriggerContainer triggers;

	Board();

	template<typename StartingEvent, typename ...Args>
	void start_event(Args &&...args);

	Player &get_cur_player();

	Player &get_cur_opp();

	void switch_player();
};

#include <type_traits>
#include <algorithm>

class Event;

template<typename StartingEvent, typename ...Args>
void Board::start_event(Args &&... args) {
	static_assert(
		std::is_base_of<Event, StartingEvent>::value,
		"You can only pass classes that derive from Event here"
	);

	StartingEvent(std::forward<Args>(args)...).occur(*this);
}

#endif //OPENHS_BOARD_H
