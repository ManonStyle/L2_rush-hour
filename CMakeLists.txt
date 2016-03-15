cmake_minimum_required (VERSION 3.2)

project (rush-hour)

add_definitions (-std=c99 -g)

#set (CMAKE_INSTALL_PREFIX .)


add_executable(rush_hour piece.c piece.h game.c game.h rush_hour.c)

add_executable(test_piece piece.c test_piece1.c)

add_executable(test_game piece.c game.c test_game1.c)
