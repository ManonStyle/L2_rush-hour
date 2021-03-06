#include <stdlib.h>
#include <stdio.h>
#include "game.h"

#define SIZE_ARRAY 6


struct game_s{
  int nb_pieces;
  int nb_moves;
  piece *pieces;
};

game new_game_hr (int nb_pieces, piece *pieces){
  game g = (game)malloc(sizeof(struct game_s));
  g->nb_pieces = nb_pieces;
  g->nb_moves = 0;
  g->pieces = (piece*)malloc(nb_pieces*sizeof(piece));
  for(int i=0; i<nb_pieces; ++i){
    g->pieces[i] = new_piece_rh(0, 0, true, true);
    copy_piece(pieces[i], g->pieces[i]);
  }
  return g;
}

void delete_game (game g){
  for(int i=0; i<g->nb_pieces; ++i)
    delete_piece(g->pieces[i]);
  free(g->pieces);
  free(g);
}

void copy_game (cgame src, game dst){
  dst->nb_pieces = src->nb_pieces;
  dst->nb_moves = src->nb_moves;
  dst->pieces = (piece*)realloc(dst->pieces, sizeof(src->nb_pieces*sizeof(piece*)));
  for(int i=0; i<src->nb_pieces; ++i){
    dst->pieces[i] = new_piece_rh(0, 0, true, true);
    copy_piece(src->pieces[i], dst->pieces[i]);
  }
}

int game_nb_pieces(cgame g){
  return g->nb_pieces;
}

cpiece game_piece(cgame g, int piece_num){
  if(piece_num >= g->nb_pieces){
    fprintf(stderr, "index is out of range\n");
    return NULL;
  }
  return g->pieces[piece_num];
}


bool game_over_hr (cgame g){
  return get_x(g->pieces[0]) == 4 && get_y(g->pieces[0]) == 3;
}

bool is_in_game(cgame g, int piece_num){
  cpiece p = g->pieces[piece_num];
  return get_x(p)>=0 && get_x(p)<=SIZE_ARRAY-get_width(p) && get_y(p)>=0 && get_y(p)<=SIZE_ARRAY-get_height(p);
}

bool is_above_piece(cgame g, int piece_num){
  cpiece p = g->pieces[piece_num];
  for(int i=0; i<piece_num; ++i){
    if(intersect(p,g->pieces[i]))
      return true;
  }
  for(int i=piece_num+1; i<g->nb_pieces; ++i){
    if(intersect(p,g->pieces[i]))
      return true;
  }
  return false;
}

bool play_move(game g, int piece_num, dir d, int distance){
  piece p = g->pieces[piece_num];
  if(is_horizontal(p)){
    if(d == UP || d == DOWN)
      return false;
  }else{
    if(d == RIGHT || d == LEFT)
      return false;
  }
  int cover_distance;
  for(cover_distance = 1; cover_distance<=distance; ++cover_distance){
    move_piece(p, d, 1);
    if(!is_in_game(g, piece_num) || is_above_piece(g, piece_num)){      //If wrong movement, the piece go back to the initial coordinates
      if(d == RIGHT)
	move_piece(p, LEFT, cover_distance);
      else if(d == LEFT)
	move_piece(p, RIGHT, cover_distance);
      else if(d == UP)
	move_piece(p, DOWN, cover_distance);
      else
	move_piece(p, UP, cover_distance);
      return false;
    }
  }
  g->nb_moves += distance;
  return true;
}

int game_nb_moves(cgame g){
  return g->nb_moves;
}
