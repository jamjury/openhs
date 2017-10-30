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
	EXPECT_EQ(player.permanent_mana, amount);
}

TEST_F(ManaEvent, GainPermanent_ExceedLimit) {
	unsigned amount = 15;

	ASSERT_GT(amount, Player::MANA_LIMIT);

	board.start_event<GainPermanentManaEvent>(amount);
	EXPECT_EQ(player.permanent_mana, Player::MANA_LIMIT);
}

TEST_F(ManaEvent, GainTemporary_LessThanLimit) {
	unsigned amount = 5;

	ASSERT_LE(amount, Player::MANA_LIMIT);

	board.start_event<GainTemporaryManaEvent>(amount);
	EXPECT_EQ(player.temporary_mana, amount);
}

TEST_F(ManaEvent, GainTemporary_ExceedLimit) {
	unsigned amount = 11;

	ASSERT_GT(amount, Player::MANA_LIMIT);

	board.start_event<GainTemporaryManaEvent>(amount);
	EXPECT_EQ(player.temporary_mana, Player::MANA_LIMIT);
}

TEST_F(ManaEvent, Gain_LessThanLimit) {
	unsigned amount = 5;

	ASSERT_LE(amount, Player::MANA_LIMIT);

	board.start_event<GainManaEvent>(amount);
	EXPECT_EQ(player.temporary_mana, amount);
	EXPECT_EQ(player.permanent_mana, amount);
}

TEST_F(ManaEvent, Gain_ExceedLimitWithInitialPermanent) {
	unsigned amount = 6;
	player.permanent_mana = 6;

	ASSERT_LE(player.permanent_mana, Player::MANA_LIMIT);
	ASSERT_GT(amount + player.permanent_mana, Player::MANA_LIMIT);

	board.start_event<GainManaEvent>(amount);
	EXPECT_EQ(player.temporary_mana, amount);
	EXPECT_EQ(player.permanent_mana, Player::MANA_LIMIT);
}

TEST_F(ManaEvent, Refresh_PermanentOnly) {
	player.permanent_mana = 5;

	ASSERT_LE(player.permanent_mana, Player::MANA_LIMIT);

	board.start_event<RefreshManaEvent>();
	EXPECT_EQ(player.temporary_mana, player.permanent_mana);
}

TEST_F(ManaEvent, Refresh_TemporaryWithPermanent) {
	player.temporary_mana = 6;
	player.permanent_mana = 8;

	ASSERT_LE(player.temporary_mana, Player::MANA_LIMIT);
	ASSERT_LE(player.permanent_mana, Player::MANA_LIMIT);

	board.start_event<RefreshManaEvent>();
	EXPECT_EQ(player.temporary_mana, player.permanent_mana);
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
	unsigned init_temporary = player.temporary_mana = 6;
	unsigned init_permanent = player.permanent_mana = 8;

	ASSERT_LE(amount, player.temporary_mana);
	ASSERT_LE(amount, player.permanent_mana);
	ASSERT_LE(player.temporary_mana, Player::MANA_LIMIT);
	ASSERT_LE(player.permanent_mana, Player::MANA_LIMIT);

	board.start_event<DestroyManaEvent>(amount);
	EXPECT_EQ(player.temporary_mana, init_temporary - amount);
	EXPECT_EQ(player.permanent_mana, init_permanent - amount);
}

/// permanent <= amount && permanent <= temporary
TEST_F(ManaEvent, Destroy_TemporaryLeft) {
	unsigned amount = 6;
	unsigned init_temporary = player.temporary_mana = 8;
	unsigned init_permanent = player.permanent_mana = 4;

	ASSERT_LE(player.permanent_mana, amount);
	ASSERT_LE(player.permanent_mana, player.temporary_mana);
	ASSERT_LE(player.temporary_mana, Player::MANA_LIMIT);
	ASSERT_LE(player.permanent_mana, Player::MANA_LIMIT);

	board.start_event<DestroyManaEvent>(amount);
	EXPECT_EQ(player.temporary_mana, init_temporary - init_permanent);
	EXPECT_EQ(player.permanent_mana, 0);
}

/// temporary <= amount <= permanent
TEST_F(ManaEvent, Destroy_PermanentLeft) {
	unsigned amount = 6;
	player.temporary_mana = 4;
	unsigned init_permanent = player.permanent_mana = 8;

	ASSERT_LE(player.temporary_mana, amount);
	ASSERT_LE(amount, player.permanent_mana);
	ASSERT_LE(player.permanent_mana, Player::MANA_LIMIT);

	board.start_event<DestroyManaEvent>(amount);
	EXPECT_EQ(player.temporary_mana, 0);
	EXPECT_EQ(player.permanent_mana, init_permanent - amount);
}

/// temporary <= permanent <= amount
TEST_F(ManaEvent, Destroy_BothGone) {
	unsigned amount = 8;
	player.temporary_mana = 4;
	player.permanent_mana = 6;

	ASSERT_LE(player.temporary_mana, player.permanent_mana);
	ASSERT_LE(player.permanent_mana, amount);
	ASSERT_LE(player.permanent_mana, Player::MANA_LIMIT);

	board.start_event<DestroyManaEvent>(amount);
	EXPECT_EQ(player.temporary_mana, 0);
	EXPECT_EQ(player.permanent_mana, 0);
}
