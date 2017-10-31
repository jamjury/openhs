cmake_minimum_required(VERSION 3.8.2)
project(openhs)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/event/Event.h src/Player.h src/event/mana/GainPermanentManaEvent.cpp src/event/mana/GainPermanentManaEvent.h src/Player.cpp src/event/CombinedEvent.cpp src/event/CombinedEvent.h src/event/mana/GainManaEvent.cpp src/event/mana/GainManaEvent.h src/event/mana/GainTemporaryManaEvent.cpp src/event/mana/GainTemporaryManaEvent.h src/event/mana/RefreshManaEvent.cpp src/event/mana/RefreshManaEvent.h src/event/mana/DestroyManaEvent.cpp src/event/mana/DestroyManaEvent.h src/event/phase/Phase.cpp src/event/phase/Phase.h src/event/phase/StartTurnPhase.cpp src/event/phase/StartTurnPhase.h src/Board.cpp src/Board.h src/event/ChangePlayerEvent.cpp src/event/ChangePlayerEvent.h src/event/Event.cpp src/event/PlayerEvent.cpp src/event/PlayerEvent.h)
add_library(openhs ${SOURCE_FILES})

include_directories(src)

add_subdirectory(googletest EXCLUDE_FROM_ALL)
add_subdirectory(test)
