#include "Zone.h"

Zone::Zone(unsigned limit) :
	limit(limit)
{
	content = new Card *[limit];
	size = 0;
}

Zone::~Zone() {
	delete[] content;
}

bool Zone::insert(Card *card) {
	if (size < limit) {
		content[size++] = card;
		return true;
	} else {
		return false;
	}
}

unsigned int Zone::get_size() const {
	return size;
}
