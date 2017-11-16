#include "GainTempManaEvent.h"

GainTempManaEvent::GainTempManaEvent(int amount) : amount(amount) {}

void GainTempManaEvent::act(Player &owner) {
	owner.gain_temp_mana(amount);
}
