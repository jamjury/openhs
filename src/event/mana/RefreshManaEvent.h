#ifndef WINSTONE_REFRESHMANA_H
#define WINSTONE_REFRESHMANA_H


#include "../PlayerEvent.h"

class RefreshManaEvent : public PlayerEvent {
public:
	void act() override;
};


#endif //WINSTONE_REFRESHMANA_H
