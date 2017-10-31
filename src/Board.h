#ifndef WINSTONE_BOARD_H
#define WINSTONE_BOARD_H


#include <vector>
#include <unordered_map>
#include <typeindex>

class Event;
class Player;

class Board {
public:
	Player *player_one, *player_two;
	Player *current_player;

	std::unordered_map<
		std::type_index,
		std::vector<Event*>
	> triggered_events;

	// Add consequence of a trigger
	template<typename Trigger>
	void add_conseq(Event *conseq);

	// Add consequence of a multiple triggers
	template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
	void add_conseq(Event *conseq);

	// Remove consequence of a trigger
	template<typename Trigger>
	void remove_conseq(Event *conseq);

	// Remove consequence of a multiple trigger
	template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
	void remove_conseq(Event *conseq);

	void trigger_consequences(Event *event);

	template<typename StartingEvent, typename ...Args>
	void start_event(Args && ...args);

	Board();

	~Board();
};

#include "event/Event.h"
#include <type_traits>
#include <algorithm>

template<typename Trigger>
void Board::add_conseq(Event *conseq) {
	static_assert(
		std::is_base_of<Event, Trigger>::value,
		"You can only pass classes that derive from Event here"
	);

	triggered_events[typeid(Trigger)].push_back(conseq);
}

template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
void Board::add_conseq(Event *consequence) {
	add_conseq<Trigger1>(consequence);
	add_conseq<Trigger2, OtherTriggers...>(consequence);
}

template<typename Trigger>
void Board::remove_conseq(Event *conseq)  {
	static_assert(
		std::is_base_of<Event, Trigger>::value,
		"You can only pass classes that derive from Event here"
	);

	auto &conseqs = triggered_events[typeid(Trigger)];
	auto new_end = std::remove(conseqs.begin(), conseqs.end(), conseq);
	conseqs.erase(new_end, conseqs.end());
}

template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
void Board::remove_conseq(Event *consequence) {
	remove_conseq<Trigger1>(consequence);
	remove_conseq<Trigger2, OtherTriggers...>(consequence);
}

template<typename StartingEvent, typename ...Args>
void Board::start_event(Args &&... args) {
	static_assert(
		std::is_base_of<Event, StartingEvent>::value,
		"You can only pass classes that derive from Event here"
	);

	auto *event = new StartingEvent(std::forward<Args>(args)...);
	event->set_board(this);
	event->occur();
	delete event;
}

#endif //WINSTONE_BOARD_H
