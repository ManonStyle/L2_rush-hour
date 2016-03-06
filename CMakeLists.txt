cmake_minimum_required (VERSION 2.8)

project (rush-hour)

add_definitions (-std=c99 -g)

#set (CMAKE_INSTALL_PREFIX .)


set(SRCS
  piece.c
  game.c
  rush_hour.c
  )
    
set(HEADERS
  piece.h
  game.h
  )

add_executable(rush-hour ${SRCS} ${HEADERS})


set(SRCS
  piece.c
  test_piece1.c
  )

add_executable(test-piece ${SRCS} )


set(SRCS
  piece.c
  game.c
  test_game1.c
  )

add_executable(test-game ${SRCS} )