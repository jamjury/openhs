#include <gtest/gtest.h>
#include <Player.h>
#include <events/mana/GainMana.h>
#include <events/mana/GainEmptyMana.h>

TEST(mana, gain_limit) {
	Player player;
	GainEmptyMana(5).occur(player);
    GainMana(6).occur(player);
    EXPECT_EQ(player.cur_mana, 5);
}

TEST(mana, gain_empty_limit) {
	Player player;
	GainEmptyMana(5).occur(player);
	GainEmptyMana(6).occur(player);
	EXPECT_EQ(player.cur_max_mana, Player::MAX_MANA);
}