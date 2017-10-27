#include <gtest/gtest.h>
#include <Player.h>
#include <events/mana/GainManaOnce.h>
#include <events/mana/GainEmptyMana.h>
#include <events/mana/GainMana.h>

TEST(mana, gain_once_limit) {
	Player player;
	GainEmptyMana(5).occur(player);
    GainManaOnce(6).occur(player);
    EXPECT_EQ(player.cur_mana, 5);
}

TEST(mana, gain_empty_limit) {
	Player player;
	GainEmptyMana(Player::MAX_MANA).occur(player);
	GainEmptyMana(6).occur(player);
	EXPECT_EQ(player.cur_max_mana, Player::MAX_MANA);
}

TEST(mana, gain) {
	Player player;
	GainEmptyMana(3).occur(player);
	GainMana(5).occur(player);
	EXPECT_EQ(player.cur_mana, 5);
	EXPECT_EQ(player.cur_max_mana, 8);
}