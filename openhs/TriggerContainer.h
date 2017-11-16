#ifndef OPENHS_TRIGGERCONTAINER_H
#define OPENHS_TRIGGERCONTAINER_H


#include <unordered_map>
#include <typeindex>
#include <vector>
#include <functional>
#include <algorithm>

class Event;
class Board;
class OriginEvent;

class TriggerContainer {
	friend OriginEvent;

	void trigger_conseq(Event &event);

	std::unordered_map<
		std::type_index,
		std::vector<Event *>
	> triggered_events;

	Board &board;
public:
	explicit TriggerContainer(Board &);

	// Add consequence of an origin
	template<typename Origin>
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
};

template<typename Trigger>
void TriggerContainer::add_conseq(Event *conseq) {
	static_assert(
		std::is_base_of<Event, Trigger>::value,
		"You can only pass classes that derive from Event here"
	);

	triggered_events[typeid(Trigger)].push_back(conseq);
}

template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
void TriggerContainer::add_conseq(Event *conseq) {
	add_conseq<Trigger1>(conseq);
	add_conseq<Trigger2, OtherTriggers...>(conseq);
}

template<typename Trigger>
void TriggerContainer::remove_conseq(Event *conseq) {
	static_assert(
		std::is_base_of<Event, Trigger>::value,
		"You can only pass classes that derive from OriginEvent here"
	);

	auto &conseqs = triggered_events[typeid(Trigger)];
	auto new_end = remove(conseqs.begin(), conseqs.end(), conseq);
	conseqs.erase(new_end, conseqs.end());
}

template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
void TriggerContainer::remove_conseq(Event *conseq) {
	remove_conseq<Trigger1>(conseq);
	remove_conseq<Trigger2, OtherTriggers...>(conseq);
}


#endif //OPENHS_TRIGGERCONTAINER_H
