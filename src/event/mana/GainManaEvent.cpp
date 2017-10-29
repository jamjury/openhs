#include "GainManaEvent.h"
#include "GainPermanentManaEvent.h"
#include "GainTemporaryManaEvent.h"

GainManaEvent::GainManaEvent(unsigned amount) :
	CombinedEvent(
		std::make_unique<GainPermanentManaEvent>(amount),
		std::make_unique<GainTemporaryManaEvent>(amount)
	)
{}
