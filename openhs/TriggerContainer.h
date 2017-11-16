#ifndef OPENHS_TRIGGERCONTAINER_H
#define OPENHS_TRIGGERCONTAINER_H

#include "BaseTriggerContainer.h"
class StartTurnPhase;

class TriggerContainer : public BaseTriggerContainer<
	StartTurnPhase
> {
	Board &board;
public:
	explicit TriggerContainer(Board &board);

	template<typename Trigger>
	void trigger_conseq() {
		for (auto &conseq : container<Trigger>().conseqs) {
			conseq->occur(board);
		}
	}
};


#endif //OPENHS_TRIGGERCONTAINER_H
