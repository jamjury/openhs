cmake_minimum_required(VERSION 3.8.2)
project(openhs)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/event/Event.h src/Player.h src/Player.cpp src/event/CombinedEvent.cpp src/event/CombinedEvent.h src/event/phase/Phase.cpp src/event/phase/Phase.h src/event/phase/StartTurnPhase.cpp src/event/phase/StartTurnPhase.h src/Board.cpp src/Board.h src/event/Event.cpp src/event/PlayerEvent.cpp src/event/PlayerEvent.h src/Zone.cpp src/Zone.h src/card/Card.cpp src/card/Card.h src/card/Minion.cpp src/card/Minion.h src/card/ChillwindYeti.cpp src/card/ChillwindYeti.h)
add_library(openhs ${SOURCE_FILES})

include_directories(src)

add_subdirectory(googletest EXCLUDE_FROM_ALL)
add_subdirectory(test)
