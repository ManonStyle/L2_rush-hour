#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piece.h"
#include "game.h"


#define NB_PIECES 7
#define SIZE_ARRAY 6

piece pieces[NB_PIECES];
/* configue de test
....6.
111.6.
00..6.
.2.344
.2.3..
.2.555
 */

char board[SIZE_ARRAY][SIZE_ARRAY];


void set_up_pieces(){
  pieces[0] = new_piece_rh(0, 3, true, true);
  pieces[1] = new_piece_rh(0, 4, false, true);
  pieces[2] = new_piece_rh(1, 0, false, false);
  pieces[3] = new_piece_rh(3, 1, true, false);
  pieces[4] = new_piece_rh(4, 2, true, true);
  pieces[5] = new_piece_rh(3, 0, false, true);
  pieces[6] = new_piece_rh(4, 3, false, false);
}

void set_up_board(game g){
  for(int x=0; x<SIZE_ARRAY; ++x){
    for(int y=0; y<SIZE_ARRAY; ++y)
      board[x][y] = 100;
  }
  for(int y=0; y<SIZE_ARRAY; ++y){
    for(int x=0; x<SIZE_ARRAY; ++x){
      for(char piece_num=0; piece_num<NB_PIECES; ++piece_num){
	cpiece p = game_piece(g, piece_num);
	if(get_x(p) == x && get_y(p) == y){
	  if(is_horizontal(p)){
	    for(int i=0; i<get_width(p); ++i)
	      board[x+i][y] = piece_num;
	    break;
	  }else{
	    for(int i=0; i<get_height(p); ++i)
	      board[x][y+i] = piece_num;
	    break;
	  }
	}
      }
    }
  }
}


void print_game(cgame g){
  printf("-------------------------------------------\n");
  for(int y=5; y>=0; --y){
    if(y == 3)
      printf("|      |      |      |      |      |      ------\n");
    else
      printf("|      |      |      |      |      |      |\n");
    for(int x=0; x<SIZE_ARRAY; ++x){
      if(board[x][y]!=100)
	printf("|  %d   ",board[x][y]);
      else
	printf("|      ");
    }
    if(y == 3)
      printf(" exit\n|      |      |      |      |      |      ------\n");
    else
      printf("|\n|      |      |      |      |      |      |\n");
    printf("|-----------------------------------------|\n");
  }
}

int main(int argc, char *argv[]){
  set_up_pieces();
  game g = new_game_hr(NB_PIECES, pieces);
  set_up_board(g);
  print_game(g);
  return EXIT_SUCCESS;
}
