#ifndef OPENHS_SPELL_H
#define OPENHS_SPELL_H


#include "../Card.h"

class Event;

class EmptySpell : Card {
public:
	explicit EmptySpell(int cost);

	virtual void cast() = 0;
};

class Spell : EmptySpell {
	Event *text;
public:
	Spell(int cost, Event *text);

	virtual ~Spell();
};


#endif //OPENHS_SPELL_H
