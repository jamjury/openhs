#ifndef WINSTONE_BOARD_H
#define WINSTONE_BOARD_H


class Event;

#include "Player.h"
#include "event/Event.h"
#include <vector>
#include <unordered_map>
#include <typeindex>

class Board {
public:
	Player *player_one, *player_two;
	Player *current_player;

	std::unordered_map<std::type_index, std::vector<Event*>> triggered_events;

	template<typename Trigger>
	void add_triggered_event(Event *event) {
		triggered_events[typeid(Trigger)].push_back(event);
	}

	template<typename Trigger>
	void remove_triggered_event(Event *event) {
		// TODO: remove event from this Trigger events
	}

	Board();

	~Board();
};


#endif //WINSTONE_BOARD_H
