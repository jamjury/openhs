#include "TheCoin.h"
#include "openhs/events/GainTempManaEvent.h"

TheCoin::TheCoin() : Spell(0, new GainTempManaEvent(1)) {}
