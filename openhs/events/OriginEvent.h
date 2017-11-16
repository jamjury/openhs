#ifndef OPENHS_ORIGINEVENT_H
#define OPENHS_ORIGINEVENT_H


#include "../Event.h"

/// An Event that can trigger other events
class OriginEvent : public virtual Event {
	void resolve(Board &);

public:
	void occur(Board &) override;
};


#endif //OPENHS_ORIGINEVENT_H
