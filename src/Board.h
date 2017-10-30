#ifndef WINSTONE_BOARD_H
#define WINSTONE_BOARD_H


class Event;

#include "Player.h"
#include "event/Event.h"
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <memory>

class Board {
public:
	Player *player_one, *player_two;
	Player *current_player;

	std::unordered_map<
		std::type_index,
		std::vector<std::shared_ptr<Event>>
	> triggered_events;

	template<typename Trigger>
	void add_triggered_event(const std::shared_ptr<Event> &event) {
		// TODO: static check Trigger is an Event
		triggered_events[typeid(Trigger)].push_back(event);
	}

	template<typename Trigger>
	void remove_triggered_event(Event *event) {
		// TODO: remove event from this Trigger's events
	}

	Board();

	~Board();
};


#endif //WINSTONE_BOARD_H
