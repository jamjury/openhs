#include <gtest/gtest.h>
#include <openhs/Event.h>
#include <openhs/events/OriginEvent.h>
#include <openhs/Board.h>

int trigger_order = 0, event_order = 0, order = 1;

TEST(Trigger, EventWithOneTrigger) {
	class Trigger : public OriginEvent {
		void act(Board &) override {
			trigger_order = order++;
		}
	};
	class TriggeredEvent : public Event {
		void act(Board &) override {
			event_order = order++;
		}
	};
	Board board;
	auto *conseq = new TriggeredEvent();
	board.triggers.add_conseq<Trigger>(conseq);
	board.start_event<Trigger>();
	EXPECT_EQ(trigger_order, 1);
	EXPECT_EQ(event_order, 2);
	delete conseq;
}