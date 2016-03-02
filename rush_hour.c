#include <stdio.h>
#include <stdlib.h>
#include "piece.h"
#include "game.h"
#include "game.c"
#include "piece.c"

#define NB_PIECES 7

piece pieces[NB_PIECES];
int piecesNum[6][6];

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

void fillArrayWithPieces(){
  for(int i = 0; i < 6; ++i){
    for(int j = 0; j < 6; ++j){
      piecesNum[i][j] = -1;
    }
  }
  for(int i = 0; i < NB_PIECES; ++i){
    if(pieces[i]->horizontal){
      for(int j = pieces[i]->x; j < pieces[i]->x + get_width(pieces[i]); ++j)
	piecesNum[j][pieces[i]->y] = i;
    }
    else{
      for(int j = pieces[i]->y; j < pieces[i]->y + get_height(pieces[i]); ++j)
	piecesNum[pieces[i]->x][j] = i;
    }
  }
}

void draw_game(){
  for(int i = 0; i < 6; ++i){
    for(int j = 5; j >= 0; --j){
      printf("|");
      switch(piecesNum[5-j][5-i]){
      case -1:
	printf("   ");
	break;
      case 0:
	printf(" 0 ");
	break;
      case 1:
	printf(" 1 ");
	break;
      case 2:
	printf(" 2 ");
	break;	
      case 3:
	printf(" 3 ");
	break;
      case 4:
	printf(" 4 ");
	break;
      case 5:
	printf(" 5 ");
	break;	
     case 6:
	printf(" 6 ");
	break;	
      }
    }
    printf("|\n");
  }
}

int main(int argc, char *argv[]){
  set_up_pieces();
  fillArrayWithPieces();
  draw_game();
  return EXIT_SUCCESS;
}
