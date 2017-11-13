#ifndef OPENHS_BOARD_H
#define OPENHS_BOARD_H


#include <vector>
#include <unordered_map>
#include <typeindex>

class Event;

class Player;

class Board final {
	friend Event;

	std::unordered_map<
		std::type_index,
		std::vector<Event *>
	> triggered_events;

	void trigger_conseq(Event *event);

public:
	Player *player_one, *player_two;
	// A player that makes a move
	Player *current_player;

	Player *current_opponent();

	Board();

	~Board();

	// Add consequence of a trigger
	template<typename Trigger>
	void add_conseq(Event *conseq);

	// Add consequence of a multiple triggers
	template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
	void add_conseq(Event *conseq);

	// Remove consequence of a trigger
	template<typename Trigger>
	void remove_conseq(Event *conseq);

	// Remove consequence of a multiple triggers
	template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
	void remove_conseq(Event *conseq);

	template<typename StartingEvent, typename ...Args>
	void start_event(Args &&...args);

	void switch_player();
};

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
void Board::add_conseq(Event *conseq) {
	add_conseq<Trigger1>(conseq);
	add_conseq<Trigger2, OtherTriggers...>(conseq);
}

template<typename Trigger>
void Board::remove_conseq(Event *conseq) {
	static_assert(
		std::is_base_of<Event, Trigger>::value,
		"You can only pass classes that derive from Event here"
	);

	auto &conseqs = triggered_events[typeid(Trigger)];
	auto new_end = std::remove(conseqs.begin(), conseqs.end(), conseq);
	conseqs.erase(new_end, conseqs.end());
}

template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
void Board::remove_conseq(Event *conseq) {
	remove_conseq<Trigger1>(conseq);
	remove_conseq<Trigger2, OtherTriggers...>(conseq);
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

#endif //OPENHS_BOARD_H
