#ifndef OPENHS_BASETRIGGERCONTAINER_H
#define OPENHS_BASETRIGGERCONTAINER_H


#include <vector>

class Event;

template<typename Origin>
struct BaseContainer {
	std::vector<Event *> conseqs;
};

class Board;

template<typename ...Origins>
class BaseTriggerContainer : private BaseContainer<Origins>... {
protected:
	template<typename Trigger>
	BaseContainer<Trigger> &container();

public:
	// Add consequence of an origin
	template<typename Trigger>
	void add_conseq(Event *conseq);

	// Add consequence of a multiple triggers
	template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
	void add_conseq(Event *conseq);;

	// Remove consequence of a trigger
	template<typename Trigger>
	void remove_conseq(Event *conseq);

	// Remove consequence of a multiple triggers
	template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
	void remove_conseq(Event *conseq);;
};

#include <algorithm>

template<typename ...Origins>
template<typename Trigger>
BaseContainer<Trigger> &BaseTriggerContainer<Origins...>::container() {
	static_assert(
		std::is_base_of<BaseContainer<Trigger>,
			BaseTriggerContainer<Origins...>>::value,
		"This container can't handle event that you've passed. "
		"Please add your event type as a template parameter."
	);
	return *static_cast<BaseContainer<Trigger>*>(this);
}

template<typename ...Origins>
template<typename Trigger>
void BaseTriggerContainer<Origins...>::add_conseq(Event *conseq) {
	container<Trigger>().conseqs.push_back(conseq);
}

template<typename ...Origins>
template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
void BaseTriggerContainer<Origins...>::add_conseq(Event *conseq) {
	add_conseq<Trigger1>(conseq);
	add_conseq<Trigger2, OtherTriggers...>(conseq);
}

template<typename ...Origins>
template<typename Trigger>
void BaseTriggerContainer<Origins...>::remove_conseq(Event *conseq) {
	auto &conseqs = container<Trigger>().conseqs;
	auto new_end = remove(conseqs.begin(), conseqs.end(), conseq);
	conseqs.erase(new_end, conseqs.end());
}

template<typename ...Origins>
template<typename Trigger1, typename Trigger2, typename ...OtherTriggers>
void BaseTriggerContainer<Origins...>::remove_conseq(Event *conseq) {
	remove_conseq<Trigger1>(conseq);
	remove_conseq<Trigger2, OtherTriggers...>(conseq);
}


#endif //OPENHS_BASETRIGGERCONTAINER_H
