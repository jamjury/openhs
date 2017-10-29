#include "GainManaEvent.h"
#include "GainPermanentManaEvent.h"
#include "GainTemporaryManaEvent.h"

GainManaEvent::GainManaEvent(unsigned amount) :
	CombinedEvent(
		std::unique_ptr<Event>(new GainPermanentManaEvent(amount)),
		std::unique_ptr<Event>(new GainTemporaryManaEvent(amount))
	)
{}
