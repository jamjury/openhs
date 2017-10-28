#include <gtest/gtest.h>
#include <Player.h>
#include <events/mana/GainTemporaryManaEvent.h>
#include <events/mana/GainPermanentManaEvent.h>
#include <events/mana/GainManaEvent.h>
#include <events/mana/RefreshManaEvent.h>

TEST(GainPermanentMana, LessThanLimit) {
	Player player;
	int amount = 6;
	ASSERT_LE(amount, MANA_LIMIT);

	GainPermanentManaEvent(amount).occur(player);
	EXPECT_EQ(player.permanent_mana, amount);
}

TEST(GainPermanentMana, ExceedLimit) {
	Player player;
	int amount = 15;
	ASSERT_GT(amount, MANA_LIMIT);

	GainPermanentManaEvent(amount).occur(player);
	EXPECT_EQ(player.permanent_mana, MANA_LIMIT);
}

TEST(GainTemporaryMana, LessThanPermanent) {
	Player player;
	player.permanent_mana = 6;
	int amount = 5;

	GainTemporaryManaEvent(amount).occur(player);
	EXPECT_EQ(player.temporary_mana, amount);
}

TEST(GainTemporaryMana, ExceedLimit) {
	Player player;
	int amount = 11;
	ASSERT_GT(amount, MANA_LIMIT);

	GainTemporaryManaEvent(amount).occur(player);
	EXPECT_EQ(player.temporary_mana, MANA_LIMIT);
}

TEST(GainMana, LessThanLimit) {
	Player player;
	int amount = 5;
	ASSERT_LE(amount, MANA_LIMIT);

	GainManaEvent(amount).occur(player);
	EXPECT_EQ(player.temporary_mana, amount);
	EXPECT_EQ(player.permanent_mana, amount);
}

TEST(GainMana, ExceedLimitWithInitialPermanent) {
	Player player;
	int initial_permanent = 8;
	int amount = 6;
	player.permanent_mana = initial_permanent;
	ASSERT_GT(amount + initial_permanent, MANA_LIMIT);

	GainManaEvent(amount).occur(player);
	EXPECT_EQ(player.temporary_mana, amount);
	EXPECT_EQ(player.permanent_mana, MANA_LIMIT);
}

TEST(RefreshMana, PermanentOnly) {
	Player player;
	player.permanent_mana = 5;
	ASSERT_LE(player.permanent_mana, MANA_LIMIT) <<
		"Permanent mana amount cant exceed mana limit";

	RefreshManaEvent().occur(player);
	EXPECT_EQ(player.temporary_mana, player.permanent_mana);
}

TEST(RefreshMana, TemporaryWithPermanent) {
	Player player;
	player.permanent_mana = 8;
	player.temporary_mana = 6;
	ASSERT_LE(player.permanent_mana, MANA_LIMIT);

	RefreshManaEvent().occur(player);
	EXPECT_EQ(player.temporary_mana, player.permanent_mana);
}