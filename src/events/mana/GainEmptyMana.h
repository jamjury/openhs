#ifndef WINSTONE_GAINEMPTYMANA_H
#define WINSTONE_GAINEMPTYMANA_H


#include "events/Event.h"

class GainEmptyMana : public Event {
    int amount;

public:
    GainEmptyMana(int amount = 1) : amount(amount) {}

    void occur(Player &player) override;
};


#endif //WINSTONE_GAINEMPTYMANA_H
