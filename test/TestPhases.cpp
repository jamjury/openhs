#include <gtest/gtest.h>
#include <Board.h>
#include <Player.h>
#include <event/phase/StartTurnPhase.h>

TEST(StartTurnPhase, SwitchPlayer) {
	Board board;
	Player *prev_player = board.get_current_player();
	board.start_event<StartTurnPhase>();
	EXPECT_NE(prev_player, board.get_current_player());
}

TEST(StartTurnPhase, RefreshMana) {
	Board board;
	board.current_opponent()->gain_perm_mana(6);
	board.start_event<StartTurnPhase>();
	EXPECT_EQ(board.get_current_player()->get_temp_mana(), 6);
}