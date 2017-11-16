#include <gtest/gtest.h>
#include <openhs/Zone.h>

class Card {};

TEST(Zone, Limit) {
	Zone play(7);
	Card *cards[10];
	for (auto &card : cards)
		play.insert(card = new Card);
	EXPECT_EQ(play.get_size(), 7);
	for (auto &card : cards)
		delete card;
}
