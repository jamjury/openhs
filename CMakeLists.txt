cmake_minimum_required(VERSION 3.8.2)
project(openhs)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        openhs/Event.cpp
        openhs/Player.cpp
        openhs/events/CombinedEvent.cpp
        openhs/events/StartTurnPhase.cpp
        openhs/Board.cpp
        openhs/events/OwnedEvent.cpp
        openhs/Zone.cpp
        openhs/Card.cpp
        openhs/cards/Minion.cpp
        openhs/cards/classic/ChillwindYeti.cpp
        openhs/cards/classic/TheCoin.cpp
        openhs/cards/Spell.cpp
        openhs/events/GainTempManaEvent.cpp
        openhs/TriggerContainer.cpp)
add_library(openhs ${SOURCE_FILES})

include_directories(${openhs_SOURCE_DIR})

add_subdirectory(googletest EXCLUDE_FROM_ALL)
add_subdirectory(test)
