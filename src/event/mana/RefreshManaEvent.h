#ifndef WINSTONE_REFRESHMANA_H
#define WINSTONE_REFRESHMANA_H


#include "../Event.h"

class RefreshManaEvent : public Event {
public:
	void occur() override;
};


#endif //WINSTONE_REFRESHMANA_H
