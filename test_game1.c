#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "piece.h"
#include "game.h"

#define NB_PIECES 5

/**
 * @brief test if value is equal to expected; if not, displays an error message containing msg to standard error output 
 * @return true if expected==value
 */
bool test_equality_int(int expected, int value, char * msg) {
  if (expected != value)
    fprintf(stderr,"ERR: value expected %d ; value computed %d. %s\n", expected, value, msg);
  return expected == value;
}

/**
 * @brief test if value is equal to expected; if not, displays an error message containing msg to standard error output 
 */
bool test_equality_bool(bool expected, bool value, char * msg) {
  if (expected != value)
    fprintf(stderr,"ERR: value expected %d ; value computed %d. %s\n", expected, value, msg);
  return expected == value;
}

piece pieces[NB_PIECES];
/* configue de test
......
....2.
00..21
..4.21
..4.33
......
 */
void set_up() {
  pieces[0] = new_piece_rh(0, 3, true, true);
  pieces[1] = new_piece_rh(5, 2, true, false);
  pieces[2] = new_piece_rh(4, 2, false, false);
  pieces[3] = new_piece_rh(4, 1, true, true);
  pieces[4] = new_piece_rh(2, 1, true, false);
}

void tear_down() {
  for (int i = 0 ; i < NB_PIECES; i++)
    delete_piece(pieces[i]);
}

bool test_new_game(){
  bool result = true;
  return true;
}

bool test_play_move(){
  return true;
}

bool test_copy_game(){
  bool result = true;
  set_up();
  game g = new_game_hr(NB_PIECES, pieces);
  piece piecesC[]={new_piece_rh(2, 1, true, false)};
  game gC = new_game_hr(1, piecesC);
  copy_game(g, gC);
  result = result && test_equality_int(game_nb_pieces(g), game_nb_pieces(gC), "copy game_nb_pieces");
  result = result && test_equality_int(game_nb_moves(g), game_nb_moves(gC), "copy game_nb_moves");
  for (int i = 0; i < NB_PIECES; ++i){
    result = result && test_equality_bool(game_piece(g, i), game_piece(gC, i), "copy game_piece");
  }
  return result;
}

int main (int argc, char *argv[]){
  bool result = true;

  result = result && test_equality_bool(true, test_new_game(), "new_game");
  result = result && test_equality_bool(true, test_play_move(), "play_move");
  result = result && test_equality_bool(true, test_copy_game(), "copy_game");

  if (result) {
    printf("Youpi !\n");
    return EXIT_SUCCESS;
   }
  else
    return EXIT_FAILURE;
 }

     //new_game_hr
   	 //game_nb_piece int
	 //game_piece 

     //play_move
	 //is_in_game
	 //is_above_piece
	 //game_over_hr
