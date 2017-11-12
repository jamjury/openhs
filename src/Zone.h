#ifndef OPENHS_ZONE_H
#define OPENHS_ZONE_H


#include <vector>

class Player;
class Card;

struct Zone {
	explicit Zone(unsigned limit);

	virtual ~Zone();

	/**
	 * Inserts card at the end of zone
	 * @returns true on success (not full zone)
	 */
	bool insert(Card *card);

	unsigned int get_size() const;

private:
	Card **content;
	unsigned size;
	unsigned const limit;
};


#endif //OPENHS_ZONE_H
