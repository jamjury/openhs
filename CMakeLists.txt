cmake_minimum_required(VERSION 3.8.2)
project(openhs)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        openhs/TriggerContainer.h openhs/TriggerContainer.cpp
        openhs/Event.h openhs/Event.cpp
        openhs/Player.h openhs/Player.cpp
        openhs/events/CombinedEvent.cpp openhs/events/CombinedEvent.h
        openhs/events/StartTurnPhase.cpp openhs/events/StartTurnPhase.h
        openhs/Board.cpp openhs/Board.h
        openhs/events/OwnedEvent.cpp openhs/events/OwnedEvent.h
        openhs/Zone.cpp openhs/Zone.h
        openhs/Card.cpp openhs/Card.h
        openhs/cards/Minion.cpp openhs/cards/Minion.h
        openhs/cards/classic/ChillwindYeti.cpp openhs/cards/classic/ChillwindYeti.h
        openhs/cards/classic/TheCoin.cpp openhs/cards/classic/TheCoin.h
        openhs/cards/Spell.cpp openhs/cards/Spell.h
        openhs/events/OriginEvent.cpp openhs/events/OriginEvent.h
        openhs/events/GainTempManaEvent.cpp openhs/events/GainTempManaEvent.h)
add_library(openhs ${SOURCE_FILES})

include_directories(${openhs_SOURCE_DIR})

add_subdirectory(googletest EXCLUDE_FROM_ALL)
add_subdirectory(test)
