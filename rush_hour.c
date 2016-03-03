#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

struct dir_option_s{
  char dir_name[6];
  dir dir_option;
};

typedef struct dir_option_s dir_option;
dir_option direction[] = {{"up",UP},{"down",DOWN},{"right",RIGHT},{"left",LEFT}};


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

bool is_dir_option(char* str){
  for(int i=0; i<4; ++i){
    if(strcmp(str, direction[i].dir_name) == 10)
      return true;
  }
  return false;
}

bool good_direction(game g, int piece_num, dir d){
  cpiece p = game_piece(g, piece_num);
  if(is_horizontal(p)){
    if(d == UP || d == DOWN)
      return false;
  }else{
    if(d == RIGHT || d == LEFT)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]){
  set_up_pieces();
  game g = new_game_hr(NB_PIECES, pieces);
  char buf[3][100];
  int piece_num;
  dir d;
  int distance;
  while(!game_over_hr(g)){
    bool good = false;
    while(!good){
      while(!good){
	set_up_board(g);
	print_game(g);
	printf("Move the pieces for free the piece 0 to the exit:\n");
	printf("Total move: %d\n",game_nb_moves(g));
	while(!good){
	  printf("What piece do you want to move?\n");
	  read(0, buf[0], sizeof(char)*100);
	  if(strcmp(buf[0], "cancel") == 10)
	    break;
	  if(strcmp(buf[0], "exit") == 10)
	    return EXIT_SUCCESS;
	  if(buf[0][0]<48 || buf[0][0]>=48+NB_PIECES || buf[0][1] != 10)
	    printf("Write a number between 0 and %d\tor write cancel or exit.\n",NB_PIECES-1);
	  else{
	    piece_num = atoi(buf[0]);
	    good = true;
	  }
	}
	if(!good)
	  break;
	good = false;
	while(!good){
	  printf("In what direction?\n");
	  read(0, buf[1],  sizeof(char)*100);
	  if(strcmp(buf[1], "cancel") == 10)
	    break;
	  if(strcmp(buf[1], "exit") == 10)
	    return EXIT_SUCCESS;
	  if(!is_dir_option(buf[1]))
	    printf("Write one of those direction: up, down, right, left\tor write cancel or exit.\n");
	  else{
	    for(int i=0; i<4; ++i){
	      if(strcmp(buf[1], direction[i].dir_name) == 10)
		d = direction[i].dir_option;
	    }
	    if(!good_direction(g, piece_num, d)){
	      if(is_horizontal(game_piece(g, piece_num)))
		printf("The piece %d cannot move vertycaly\n", piece_num);
	      else
		printf("The piece %d cannot move horizontaly\n", piece_num);
	    }else
	      good = true;
	  }
	}
	if(!good)
	  break;
	good = false;
	while(!good){
	  printf("How many case?\n");
	  read(0, buf[2],  sizeof(char)*100);
	  if(strcmp(buf[2], "cancel") == 10)
	    break;
	  if(strcmp(buf[2], "exit") == 10)
	    return EXIT_SUCCESS;
	  if(buf[2][0]<48 || buf[2][0]>=48+SIZE_ARRAY || buf[2][1] != 10)
	    printf("Write a number between 0 and %d\tor write cancel or exit.\n",SIZE_ARRAY-1);
	  else{
	    distance = atoi(buf[2]);
	    good = play_move(g, piece_num, d, distance);
	    if(!good)
	      printf("The piece %d cannot move to that case.\n", piece_num);
	  }
	}
      }
    }
  }
  set_up_board(g);
  print_game(g);
  printf("CONGRETULATION\nYou won in %d moves\n", game_nb_moves(g));
  return EXIT_SUCCESS;
}
