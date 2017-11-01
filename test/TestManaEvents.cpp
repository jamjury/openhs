#include <gtest/gtest.h>
#include <Player.h>
#include <event/mana/GainTemporaryManaEvent.h>
#include <event/mana/GainPermanentManaEvent.h>
#include <event/mana/GainManaEvent.h>
#include <event/mana/RefreshManaEvent.h>
#include <event/mana/DestroyManaEvent.h>
#include <Board.h>


struct ManaEvent : public ::testing::Test {
	Board board;
	Player &player = *board.current_player;
};

TEST_F(ManaEvent, GainPermanent_LessThanLimit) {
	unsigned amount = 6;

	ASSERT_LE(amount, Player::MANA_LIMIT);

	board.start_event<GainPermanentManaEvent>(amount);
	EXPECT_EQ(player.perm_mana, amount);
}

TEST_F(ManaEvent, GainPermanent_ExceedLimit) {
	unsigned amount = 15;

	ASSERT_GT(amount, Player::MANA_LIMIT);

	board.start_event<GainPermanentManaEvent>(amount);
	EXPECT_EQ(player.perm_mana, Player::MANA_LIMIT);
}

TEST_F(ManaEvent, GainTemporary_LessThanLimit) {
	unsigned amount = 5;

	ASSERT_LE(amount, Player::MANA_LIMIT);

	board.start_event<GainTemporaryManaEvent>(amount);
	EXPECT_EQ(player.temp_mana, amount);
}

TEST_F(ManaEvent, GainTemporary_ExceedLimit) {
	unsigned amount = 11;

	ASSERT_GT(amount, Player::MANA_LIMIT);

	board.start_event<GainTemporaryManaEvent>(amount);
	EXPECT_EQ(player.temp_mana, Player::MANA_LIMIT);
}

TEST_F(ManaEvent, Gain_LessThanLimit) {
	unsigned amount = 5;

	ASSERT_LE(amount, Player::MANA_LIMIT);

	board.start_event<GainManaEvent>(amount);
	EXPECT_EQ(player.temp_mana, amount);
	EXPECT_EQ(player.perm_mana, amount);
}

TEST_F(ManaEvent, Gain_ExceedLimitWithInitialPermanent) {
	unsigned amount = 6;
	player.perm_mana = 6;

	ASSERT_LE(player.perm_mana, Player::MANA_LIMIT);
	ASSERT_GT(amount + player.perm_mana, Player::MANA_LIMIT);

	board.start_event<GainManaEvent>(amount);
	EXPECT_EQ(player.temp_mana, amount);
	EXPECT_EQ(player.perm_mana, Player::MANA_LIMIT);
}

TEST_F(ManaEvent, Refresh_PermanentOnly) {
	player.perm_mana = 5;

	ASSERT_LE(player.perm_mana, Player::MANA_LIMIT);

	board.start_event<RefreshManaEvent>();
	EXPECT_EQ(player.temp_mana, player.perm_mana);
}

TEST_F(ManaEvent, Refresh_TemporaryWithPermanent) {
	player.temp_mana = 6;
	player.perm_mana = 8;

	ASSERT_LE(player.temp_mana, Player::MANA_LIMIT);
	ASSERT_LE(player.perm_mana, Player::MANA_LIMIT);

	board.start_event<RefreshManaEvent>();
	EXPECT_EQ(player.temp_mana, player.perm_mana);
}

/**
 * DestroyMana tests:
 * 1. amount <= temporary && amount <= permanent
 * 2. permanent <= amount && permanent <= temporary
 * 3. temporary <= amount <= permanent
 * 4. temporary <= permanent <= amount
 */

/// amount <= temporary && amount <= permanent
TEST_F(ManaEvent, Destroy_BothLeft) {
	unsigned amount = 4;
	unsigned init_temporary = player.temp_mana = 6;
	unsigned init_permanent = player.perm_mana = 8;

	ASSERT_LE(amount, player.temp_mana);
	ASSERT_LE(amount, player.perm_mana);
	ASSERT_LE(player.temp_mana, Player::MANA_LIMIT);
	ASSERT_LE(player.perm_mana, Player::MANA_LIMIT);

	board.start_event<DestroyManaEvent>(amount);
	EXPECT_EQ(player.temp_mana, init_temporary - amount);
	EXPECT_EQ(player.perm_mana, init_permanent - amount);
}

/// permanent <= amount && permanent <= temporary
TEST_F(ManaEvent, Destroy_TemporaryLeft) {
	unsigned amount = 6;
	unsigned init_temporary = player.temp_mana = 8;
	unsigned init_permanent = player.perm_mana = 4;

	ASSERT_LE(player.perm_mana, amount);
	ASSERT_LE(player.perm_mana, player.temp_mana);
	ASSERT_LE(player.temp_mana, Player::MANA_LIMIT);
	ASSERT_LE(player.perm_mana, Player::MANA_LIMIT);

	board.start_event<DestroyManaEvent>(amount);
	EXPECT_EQ(player.temp_mana, init_temporary - init_permanent);
	EXPECT_EQ(player.perm_mana, 0);
}

/// temporary <= amount <= permanent
TEST_F(ManaEvent, Destroy_PermanentLeft) {
	unsigned amount = 6;
	player.temp_mana = 4;
	unsigned init_permanent = player.perm_mana = 8;

	ASSERT_LE(player.temp_mana, amount);
	ASSERT_LE(amount, player.perm_mana);
	ASSERT_LE(player.perm_mana, Player::MANA_LIMIT);

	board.start_event<DestroyManaEvent>(amount);
	EXPECT_EQ(player.temp_mana, 0);
	EXPECT_EQ(player.perm_mana, init_permanent - amount);
}

/// temporary <= permanent <= amount
TEST_F(ManaEvent, Destroy_BothGone) {
	unsigned amount = 8;
	player.temp_mana = 4;
	player.perm_mana = 6;

	ASSERT_LE(player.temp_mana, player.perm_mana);
	ASSERT_LE(player.perm_mana, amount);
	ASSERT_LE(player.perm_mana, Player::MANA_LIMIT);

	board.start_event<DestroyManaEvent>(amount);
	EXPECT_EQ(player.temp_mana, 0);
	EXPECT_EQ(player.perm_mana, 0);
}
