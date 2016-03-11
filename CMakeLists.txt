
# cmake principal


cmake_minimum_required(VERSION 2.8)

project(RUSHHOUR)

add_definitions(-std=c99 -g -Wall)

set(CMAKE_INSTALL_PREFIX .)

include_directories(
	$(RUSHHOUR_SOURCE_DIR)/game/game
	$(RUSHHOUR_SOURCE_DIR)/game/piece)

add_subdirectory(game)
add_subdirectory(rush_hour)
#add_subdirectory(test)





#add_executable(rush_hour piece.c piece.h game.c game.h rush_hour.c)

#add_executable(test_piece piece.c test_piece1.c)

#add_executable(test_game piece.c game.c test_game1.c)
