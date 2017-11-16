#ifndef OPENHS_CARD_H
#define OPENHS_CARD_H


class Player;

class Card {
	int cost;
	Player *controller;

public:
	explicit Card(int cost);
};


#endif //OPENHS_CARD_H
