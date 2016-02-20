#include <stdlib.h>
#include <stdio.h>
#include "game.h"

struct game_s{
  int nb_pieces;
  int nb_moves;
  piece *pieces;
};

game new_game_hr (int nb_pieces, piece *pieces){
  game g = (game)malloc(sizeof(struct game_s));
  g->nb_pieces = nb_pieces;
  g->nb_moves = 0;
  g->pieces = (piece*)malloc(sizeof(nb_pieces*sizeof(piece*)));
  for(int i=0; i<nb_pieces; ++i)
    copy_piece(pieces[i], g->pieces[i]);
  return g;
}

void delete_game (game g){
  free(g->pieces);
  free(g);
}

void copy_game (cgame src, game dst){
  dst = new_game_hr (src->nb_pieces, src->pieces);
  dst->nb_moves = src->nb_moves;
}

int game_nb_piece (cgame g){
  return g->nb_pieces;
}

cpiece game_piece(cgame g, int piece_num){
  if(piece_num <= g->nb_pieces){
    fprintf(stderr, "index is out of range\n");
    exit(EXIT_FAILURE);
  }
  return g->pieces[piece_num];
}

bool game_over_hr (cgame g){
  return get_x(g->pieces[0]) == 4 && get_y(g->pieces[0]) == 3;
}

bool is_in_game(game g, int piece_num){
  cpiece p = g->pieces[piece_num];
  return get_x(p)>=0 && get_x(p)<6 && get_y(p)>=0 && get_y(p)<6;
}

bool is_above_piece(game g, int piece_num){
  cpiece p = g->pieces[piece_num];
  for(int i=0; i<piece_num; ++i){
    if(intersect(p,g->pieces[i]))
      return false;
  }
  for(int i=0; i<g->nb_pieces; ++i){
    if(intersect(p,g->pieces[i]))
      return false;
  }
  return true;
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
  move_piece(p, d, distance);
  if(is_in_game(g, piece_num) && !is_above_piece(g, piece_num)){
    g->nb_moves += distance;
    return true;
  }else{
    if(d == RIGHT)
      move_piece(p, LEFT, distance);
    else if(d == LEFT)
      move_piece(p, RIGHT, distance);
    else if(d == UP)
      move_piece(p, DOWN, distance);
    else
      move_piece(p, UP, distance);
    return false;
  }
}

int game_nb_moves(cgame g){
  return g->nb_moves;
}
