#ifndef WINSTONE_BOARD_H
#define WINSTONE_BOARD_H


#include <vector>
#include <unordered_map>
#include <typeindex>
#include <type_traits>
#include <memory>
#include <stdexcept>
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
		using DecayTrigger = typename std::decay<Trigger>::type;
		static_assert(std::is_base_of<Event, DecayTrigger>::value,
			"Can only add events");

		triggered_events[typeid(DecayTrigger)].push_back(move(event));
	}

	template<typename Trigger>
	void remove_triggered_event(Event *event) {
		// TODO: remove event from this Trigger's events
	}

	template<typename Trigger>
	void trigger() {
		using DecayTrigger = typename std::decay<Trigger>::type;
		static_assert(std::is_base_of<Event, DecayTrigger>::value,
			"Can only be triggered by event");

		for (auto &event : triggered_events[typeid(DecayTrigger)]) {
			event->occur();
		}
	}

	template<typename Event, typename ...Args>
	void start_event(Args && ...args) {
		using DecayEvent = typename std::decay<Event>::type;
		static_assert(std::is_base_of<::Event, DecayEvent>::value,
			"Can only start events");

		::Event* event = new Event(std::forward<Args>(args)...);
		event->set_board(this);
		event->occur();
	}

	Board();

	~Board();
};


#endif //WINSTONE_BOARD_H
