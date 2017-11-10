#include "GainManaEvent.h"
#include "GainPermanentManaEvent.h"
#include "GainTemporaryManaEvent.h"

GainManaEvent::GainManaEvent(unsigned amount) :
	CombinedEvent(
		new GainPermanentManaEvent(amount),
		new GainTemporaryManaEvent(amount)
	)
{}

void GainManaEvent::set_board(Board *board) {
	CombinedEvent::set_board(board);
	PlayerEvent::set_board(board);
}
