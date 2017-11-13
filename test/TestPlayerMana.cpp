#include <gtest/gtest.h>
#include <Player.h>
#include <Board.h>


struct PlayerMana : public ::testing::Test {
	Player player;
};

TEST_F(PlayerMana, GainPermanent_LessThanLimit) {
	unsigned amount = 6;

	ASSERT_LE(amount, Player::MANA_LIMIT);

	player.gain_perm_mana(amount);
	EXPECT_EQ(player.get_perm_mana(), amount);
}

TEST_F(PlayerMana, GainPermanent_ExceedLimit) {
	unsigned amount = 15;

	ASSERT_GT(amount, Player::MANA_LIMIT);

	player.gain_perm_mana(amount);
	EXPECT_EQ(player.get_perm_mana(), Player::MANA_LIMIT);
}

TEST_F(PlayerMana, GainTemporary_LessThanLimit) {
	unsigned amount = 5;

	ASSERT_LE(amount, Player::MANA_LIMIT);

	player.gain_temp_mana(amount);
	EXPECT_EQ(player.get_temp_mana(), amount);
}

TEST_F(PlayerMana, GainTemporary_ExceedLimit) {
	unsigned amount = 11;

	ASSERT_GT(amount, Player::MANA_LIMIT);

	player.gain_temp_mana(amount);
	EXPECT_EQ(player.get_temp_mana(), Player::MANA_LIMIT);
}

TEST_F(PlayerMana, Gain_LessThanLimit) {
	unsigned amount = 5;

	ASSERT_LE(amount, Player::MANA_LIMIT);

	player.gain_mana(amount);
	EXPECT_EQ(player.get_temp_mana(), amount);
	EXPECT_EQ(player.get_perm_mana(), amount);
}

TEST_F(PlayerMana, Gain_ExceedLimitWithInitialPermanent) {
	unsigned amount = 6;
	player.gain_perm_mana(6);

	ASSERT_LE(player.get_perm_mana(), Player::MANA_LIMIT);
	ASSERT_GT(amount + player.get_perm_mana(), Player::MANA_LIMIT);

	player.gain_mana(amount);
	EXPECT_EQ(player.get_temp_mana(), amount);
	EXPECT_EQ(player.get_perm_mana(), Player::MANA_LIMIT);
}

TEST_F(PlayerMana, Refresh_PermanentOnly) {
	player.gain_perm_mana(5);

	ASSERT_LE(player.get_perm_mana(), Player::MANA_LIMIT);

	player.refresh_mana();
	EXPECT_EQ(player.get_temp_mana(), player.get_perm_mana());
}

TEST_F(PlayerMana, Refresh_TemporaryWithPermanent) {
	player.gain_temp_mana(6);
	player.gain_perm_mana(8);

	ASSERT_LE(player.get_temp_mana(), Player::MANA_LIMIT);
	ASSERT_LE(player.get_perm_mana(), Player::MANA_LIMIT);

	player.refresh_mana();
	EXPECT_EQ(player.get_temp_mana(), player.get_perm_mana());
}

/**
 * DestroyMana tests:
 * 1. amount <= temporary && amount <= permanent
 * 2. permanent <= amount && permanent <= temporary
 * 3. temporary <= amount <= permanent
 * 4. temporary <= permanent <= amount
 */

/// amount <= temporary && amount <= permanent
TEST_F(PlayerMana, Destroy_BothLeft) {
	unsigned amount = 4;
	unsigned init_temporary = player.gain_temp_mana(6);
	unsigned init_permanent = player.gain_perm_mana(8);

	ASSERT_LE(amount, player.get_temp_mana());
	ASSERT_LE(amount, player.get_perm_mana());
	ASSERT_LE(player.get_temp_mana(), Player::MANA_LIMIT);
	ASSERT_LE(player.get_perm_mana(), Player::MANA_LIMIT);

	player.destroy_mana(amount);
	EXPECT_EQ(player.get_temp_mana(), init_temporary - amount);
	EXPECT_EQ(player.get_perm_mana(), init_permanent - amount);
}

/// permanent <= amount && permanent <= temporary
TEST_F(PlayerMana, Destroy_TemporaryLeft) {
	unsigned amount = 6;
	unsigned init_temporary = player.gain_temp_mana(8);
	unsigned init_permanent = player.gain_perm_mana(4);

	ASSERT_LE(player.get_perm_mana(), amount);
	ASSERT_LE(player.get_perm_mana(), player.get_temp_mana());
	ASSERT_LE(player.get_temp_mana(), Player::MANA_LIMIT);
	ASSERT_LE(player.get_perm_mana(), Player::MANA_LIMIT);

	player.destroy_mana(amount);
	EXPECT_EQ(player.get_temp_mana(), init_temporary - init_permanent);
	EXPECT_EQ(player.get_perm_mana(), 0);
}

/// temporary <= amount <= permanent
TEST_F(PlayerMana, Destroy_PermanentLeft) {
	unsigned amount = 6;
	player.gain_temp_mana(4);
	unsigned init_permanent = player.gain_perm_mana(8);

	ASSERT_LE(player.get_temp_mana(), amount);
	ASSERT_LE(amount, player.get_perm_mana());
	ASSERT_LE(player.get_perm_mana(), Player::MANA_LIMIT);

	player.destroy_mana(amount);
	EXPECT_EQ(player.get_temp_mana(), 0);
	EXPECT_EQ(player.get_perm_mana(), init_permanent - amount);
}

/// temporary <= permanent <= amount
TEST_F(PlayerMana, Destroy_BothGone) {
	unsigned amount = 8;
	player.gain_temp_mana(4);
	player.gain_perm_mana(6);

	ASSERT_LE(player.get_temp_mana(), player.get_perm_mana());
	ASSERT_LE(player.get_perm_mana(), amount);
	ASSERT_LE(player.get_perm_mana(), Player::MANA_LIMIT);

	player.destroy_mana(amount);
	EXPECT_EQ(player.get_temp_mana(), 0);
	EXPECT_EQ(player.get_perm_mana(), 0);
}
