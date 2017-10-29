#ifndef WINSTONE_REFRESHMANA_H
#define WINSTONE_REFRESHMANA_H


#include "../Event.h"

class RefreshManaEvent : public Event {
public:
	void occur(Board &board) override;
};


#endif //WINSTONE_REFRESHMANA_H
