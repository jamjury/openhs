#ifndef WINSTONE_BOARD_H
#define WINSTONE_BOARD_H


#include <vector>
#include <unordered_map>
#include <typeindex>
#include <type_traits>
#include <memory>
#include <stdexcept>
#include <iostream>
#include "event/Event.h"
class Player;

class Board {
public:
	Player *player_one, *player_two;
	Player *current_player;

	std::unordered_map<
		std::type_index,
		std::vector<std::unique_ptr<Event>>
	> triggered_events;

	template<typename Trigger>
	void add_triggered_event(std::unique_ptr<Event> event) {
		static_assert(
			std::is_base_of<Event, Trigger>::value,
			"You can only pass classes that derive from Event here"
		);

		triggered_events[typeid(Trigger)].push_back(move(event));
	}

	template<typename Trigger>
	void remove_triggered_event(Event *event) {
		// TODO: remove event from this Trigger's events
	}

	template<typename Trigger>
	void trigger() {
		static_assert(
			std::is_base_of<Event, Trigger>::value,
			"You can only pass classes that derive from Event here"
		);

		for (auto &event : triggered_events[typeid(Trigger)]) {
			event->occur();
		}
	}

	template<typename StartingEvent, typename ...Args>
	void start_event(Args && ...args) {
		static_assert(
			std::is_base_of<Event, StartingEvent>::value,
			"You can only pass classes that derive from Event here"
		);

		Event *event = new StartingEvent(std::forward<Args>(args)...);
		event->set_board(this);
		event->occur();
	}

	Board();

	~Board();
};


#endif //WINSTONE_BOARD_H
