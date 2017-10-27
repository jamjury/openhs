#include "GainMana.h"
#include "GainEmptyMana.h"
#include "GainManaOnce.h"

GainMana::GainMana(int amount) :
	CombinedEvent(
		new GainEmptyMana(amount),
		new GainManaOnce(amount)
	)
{}
