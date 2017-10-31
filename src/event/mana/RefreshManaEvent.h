#ifndef OPENHS_REFRESHMANA_H
#define OPENHS_REFRESHMANA_H


#include "../PlayerEvent.h"

class RefreshManaEvent : public PlayerEvent {
public:
	void act() override;
};


#endif //OPENHS_REFRESHMANA_H
