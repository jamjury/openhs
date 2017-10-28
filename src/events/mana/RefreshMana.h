#ifndef WINSTONE_REFRESHMANA_H
#define WINSTONE_REFRESHMANA_H


#include "../Event.h"

class RefreshMana : public Event {
public:
	void occur(Player &player) override;
};


#endif //WINSTONE_REFRESHMANA_H
