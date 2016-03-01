#include <stdio.h>
#include <stdlib.h>
#include "piece.h"
#include "game.h"

#define NB_PIECES 7

piece pieces[NB_PIECES];
/* configue de test
....6.
111.6.
00..6.
.2.344
.2.3..
.2.555
 */

void set_up_pieces(){
  pieces[0] = new_piece_rh(0, 3, true, true);
  pieces[1] = new_piece_rh(0, 4, false, true);
  pieces[2] = new_piece_rh(1, 0, false, false);
  pieces[3] = new_piece_rh(3, 1, true, false);
  pieces[4] = new_piece_rh(4, 2, true, true);
  pieces[5] = new_piece_rh(3, 0, false, true);
  pieces[6] = new_piece_rh(4, 3, false, false);
}

int main(int argc, char *argv[]){
  set_up_pieces();

  return EXIT_SUCCESS;
}
