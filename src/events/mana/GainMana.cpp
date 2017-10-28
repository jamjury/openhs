#include "GainMana.h"
#include "GainPermanentMana.h"
#include "GainTemporaryMana.h"

GainMana::GainMana(int amount) :
	CombinedEvent(
		new GainPermanentMana(amount),
		new GainTemporaryMana(amount)
	)
{}
