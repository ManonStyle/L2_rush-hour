#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "piece.h"
#include "game.h"


#define SIZE_ARRAY 6

struct dir_option_s{
  char dir_name[6];
  dir dir_option;
};

typedef struct dir_option_s dir_option;
dir_option direction[] = {{"up",UP},{"down",DOWN},{"right",RIGHT},{"left",LEFT}};


// return the number of the piece in (,y) or -1
int is_piece(game g, int x, int y){
  for(int i=0; i<game_nb_pieces(g); ++i){
    cpiece p = game_piece(g, i);
    int x_piece = get_x(p);
    int y_piece = get_y(p);
    if(x_piece == x && !is_horizontal(p)){
      if(y_piece == y || y_piece == y-1)
	return i;
      if(get_height(p) == 3 && y_piece == y-2)
	return i;
    }
    if(y_piece == y && is_horizontal(p)){
      if(x_piece == x || x_piece == x-1)
	return i;
      if(get_width(p) == 3 && x_piece == x-2)
	return i;
    }
  }
  return -1;
}


// Print the board of the current game in the terminal
void print_game(game g){
  printf("-------------------------------------------\n");
  for(int y=SIZE_ARRAY-1; y>=0; --y){
    if(y == 3)
      printf("|      |      |      |      |      |      ------\n");
    else
      printf("|      |      |      |      |      |      |\n");
    for(int x=0; x<SIZE_ARRAY; ++x){
      int piece_num = is_piece(g, x, y);
      if(piece_num != -1)
	printf("|  %2d  ", piece_num);
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

bool can_move(game g, int piece_num){
  cpiece p = game_piece(g, piece_num);
  int x_piece = get_x(p);
  int y_piece = get_y(p);
  if(is_horizontal(p)){
    //Check if the piece is not nears the limit board and if there is not an other piece sticks to hir
    if(x_piece-1 >= 0 && x_piece+get_width(p) < SIZE_ARRAY)
      return is_piece(g, x_piece-1, y_piece) == -1 || is_piece(g, x_piece+get_width(p), y_piece) == -1;
    if(x_piece+get_width(p) < SIZE_ARRAY)
      return is_piece(g, x_piece+get_width(p), y_piece) == -1;
    if(x_piece-1 >= 0)
      return is_piece(g, x_piece-1, y_piece) == -1;
  }else{
    if(y_piece-1 >= 0 && y_piece+get_height(p) < SIZE_ARRAY)
      return is_piece(g, x_piece, y_piece-1) == -1 || is_piece(g, x_piece, y_piece+get_height(p)) == -1;
    if(y_piece+get_height(p) < SIZE_ARRAY)
      return is_piece(g, x_piece, y_piece+get_height(p)) == -1;
    if(y_piece-1 >= 0)
      return is_piece(g, x_piece, y_piece-1) == -1;
  }
  return false;
} 

bool is_dir_option(char* str){
  //Verify if the string str is an option's name of direction.
  for(int i=0; i<4; ++i){
    if(strcmp(str, direction[i].dir_name) == 10)
      return true;
  }
  return false;
}

bool good_direction(game g, int piece_num, dir d){
  //Verify if you can move to the direction d
  cpiece p = game_piece(g, piece_num);
  int x_piece = get_x(p);
  int y_piece = get_y(p);
  if(is_horizontal(p)){
    if(d == UP || d == DOWN){
      printf("The piece %d cannot move vertycaly\n", piece_num);
      return false;
    }
    if(d == RIGHT){
      //Verify if the piece is not nears the limit board and if there is not an other piece sticks to hir
      if(x_piece+get_width(p) >= SIZE_ARRAY || is_piece(g, x_piece+get_width(p),y_piece) != -1){
	printf("The piece %d cannot move to right\n", piece_num);
	return false;
      }
    }
    if(d == LEFT){
      if(x_piece-1 < 0 || is_piece(g, x_piece-1, y_piece) != -1){
	printf("The piece %d cannot move to left\n", piece_num);
	return false;
      }
    }	
  }else{
    if(d == RIGHT || d == LEFT){
      printf("The piece %d cannot move horizontaly\n", piece_num);
      return false;
    }
    if(d == UP){
      if(y_piece+get_height(p) >= SIZE_ARRAY || is_piece(g, x_piece, y_piece+get_height(p)) != -1){
	printf("The piece %d cannot move to up\n", piece_num);
	return false;
      }
    }
    if(d == DOWN){
      if(y_piece-1 < 0 || is_piece(g, x_piece, y_piece-1) != -1){
	printf("The piece %d cannot move to down\n", piece_num);
	return false;
      }
    }
  }
  return true;
}



int take_piece_num(game g, char* buf, int* piece_num){
  while(true){
    printf("What piece do you want to move?\n");
    read(0, buf, sizeof(char)*100);
    if(strcmp(buf, "cancel") == 10)
      break;
    if(strcmp(buf, "exit") == 10)
      return -1;
    if(buf[0]<48 || buf[0]>=48+game_nb_pieces(g) || buf[1] != 10)
      printf("Write a number between 0 and %dt\tor write cancel or exit.\n",game_nb_pieces(g)-1);
    else{
      *(piece_num) = atoi(buf);
      if(!can_move(g,*(piece_num)))
	printf("The piece %d cannot move.\n", *(piece_num));
      else
	return 1;
    }
  }
  return 0;
}

int take_direction(game g, int piece_num, char* buf, dir* d){
  while(true){
    printf("In what direction?\n");
    read(0, buf,  sizeof(char)*100);
    if(strcmp(buf, "cancel") == 10)
      break;
    if(strcmp(buf, "exit") == 10)
      return -1;
    if(!is_dir_option(buf))
      printf("Write one of those direction: up, down, right, left\tor write cancel or exit.\n");
    else{
      for(int i=0; i<4; ++i){
	if(strcmp(buf, direction[i].dir_name) == 10)
	  *(d) = direction[i].dir_option;
      }
      if(good_direction(g, piece_num, *(d))){
	return 1;
      }
    }
  }
  return 0;
}

int take_number_case(game g, int piece_num, dir d, char* buf, int* distance){
  while(true){
    printf("How many case?\n");
    read(0, buf,  sizeof(char)*100);
    if(strcmp(buf, "cancel") == 10)
      break;
    if(strcmp(buf, "exit") == 10)
      return -1;
    if(buf[0]<48 || buf[0]>=48+SIZE_ARRAY || buf[1] != 10)
      printf("Write a number between 0 and %d\tor write cancel or exit.\n",SIZE_ARRAY-1);
    else{
      *(distance) = atoi(buf);
      if(!play_move(g, piece_num, d, *(distance)))
	printf("The piece %d cannot move of %d case(s).\n", piece_num, *(distance));
      else
	return 1;
    }
  }
  return 0;
}

game init_game(int level){
  FILE* f = fopen("../../rush_hour/rush_hour.txt", "r");
  if(f == NULL)
    fprintf(stderr, "erreur rush_hour.txt\n");
    exit(EXIT_FAILURE);
  char tmp[100]; 
  for(int i=0; i<level; ++i){
    if(!fgets(tmp, 100, f)){
      fprintf(stderr, "There is no level %d\n", level);
      exit(EXIT_FAILURE);
    }
  }
  const char limit[1] = ".";
  char* splited = strtok(tmp, limit);
  int nb_pieces = atoi(splited);
  piece pieces[nb_pieces];
  char value[1];
  for(int i=0; i<nb_pieces; ++i){
    splited = strtok(NULL, limit);
    printf("%s\n", splited);
    value[0] = splited[0];
    int x = atoi(value);
    value[0] = splited[1];
    int y = atoi(value);
    value[0] = splited[2];
    bool small = atoi(value);
    value[0] = splited[3];
    bool horizontal = atoi(value);
    pieces[i] = new_piece_rh(x, y, small, horizontal);
  }
  fclose(f);
  return new_game_hr(nb_pieces, pieces);
}

void usage(char* str){
  fprintf(stderr, "Usage: %s <int level>\n", str);
  return exit(EXIT_FAILURE);
}


int main(int argc, char *argv[]){
  if(argc != 2)
    usage(argv[0]);
  int level = atoi(argv[1]);
  if(level <= 0)
    usage(argv[0]);
  game g = init_game(level);
  char buf[3][100];
  int piece_num;
  dir d;
  int distance;
  int back_code;
  while(!game_over_hr(g)){
    bool good = false;
    while(!good){
      //Loop for the break of cancel instruction
      while(!good){
	system("clear");
	print_game(g);
	printf("Move the pieces for free the piece 0 to the exit:\n");
	printf("Write exit for quit the game or cancel for restart the current move.\n");
	printf("Total move: %d\n",game_nb_moves(g));
	//First loop to take the number piece that you want to move
	back_code = take_piece_num(g, buf[0], &(piece_num));
	if(back_code == 0)
	  break;
	if(back_code == -1)
	  return EXIT_SUCCESS;
	//Second loop to take the direction where you want to move
	back_code = take_direction(g, piece_num, buf[1], &(d));
	if(back_code == 0)
	  break;
	if(back_code == -1)
	  return EXIT_SUCCESS;
	//Third loop to take the number of case that need for the move
	back_code = take_number_case(g, piece_num, d, buf[2], &(distance));
	if(back_code == 0)
	  break;
	if(back_code == -1)
	  return EXIT_SUCCESS;
	good = true;
      }
    }
  }
  system("clear");
  print_game(g);
  printf("CONGRATULATION\nYou won in %d moves\n", game_nb_moves(g));
  delete_game(g);
  return EXIT_SUCCESS;
}
