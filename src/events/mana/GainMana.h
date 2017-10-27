#ifndef WINSTONE_GAINMANA_H
#define WINSTONE_GAINMANA_H


#include "events/Event.h"

class GainMana : public Event {
    int amount;

public:
    GainMana(int amount = 1) : amount(amount) {}

    void occur(Player &player) override;
};


#endif //WINSTONE_GAINMANA_H
