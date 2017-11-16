#ifndef OPENHS_ORIGINEVENT_H
#define OPENHS_ORIGINEVENT_H


#include "../Event.h"

template<typename Origin>
class OriginEvent : public virtual Event {
	void resolve(Board &);

public:
	void occur(Board &) override;
};

#include "../Board.h"
#include "../TriggerContainer.h"

template<typename Origin>
void OriginEvent<Origin>::resolve(Board &board) {
	board.triggers.trigger_conseq<Origin>();
}

template<typename Origin>
void OriginEvent<Origin>::occur(Board &board) {
	Event::occur(board);
	resolve(board);
}


#endif //OPENHS_ORIGINEVENT_H
