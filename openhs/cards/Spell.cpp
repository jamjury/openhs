#include "Spell.h"

EmptySpell::EmptySpell(int cost) : Card(cost) {}

Spell::Spell(int cost, Event *text) :
	EmptySpell(cost),
	text(text)
{}

Spell::~Spell() {
	delete text;
}
