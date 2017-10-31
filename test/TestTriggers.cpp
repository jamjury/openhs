#include <gtest/gtest.h>
#include <event/Event.h>
#include <Board.h>

int trigger_order = 0, event_order = 0, order = 1;
TEST(Triggers, EventWithOneTrigger) {
	class Trigger : public Event {
		void act() override {
			trigger_order = order++;
		}
	};
	class TriggeredEvent : public Event {
		void act() override {
			event_order = order++;
		}
	};
	Board board;
	board.add_conseq<Trigger>(new TriggeredEvent());
	board.start_event<Trigger>();
	EXPECT_EQ(trigger_order, 1);
	EXPECT_EQ(event_order, 2);
}