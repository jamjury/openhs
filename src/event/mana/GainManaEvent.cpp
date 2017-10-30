#include "GainManaEvent.h"
#include "GainPermanentManaEvent.h"
#include "GainTemporaryManaEvent.h"

GainManaEvent::GainManaEvent(unsigned amount) :
	CombinedEvent(
		std::make_unique<GainPermanentManaEvent>(amount),
		std::make_unique<GainTemporaryManaEvent>(amount)
	)
{}

void GainManaEvent::set_board(Board *board) {
	Event::set_board(board);
	CombinedEvent::set_board(board);
	PlayerEvent::set_board(board);
}
