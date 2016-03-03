#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "piece.h"

struct piece_s
{
  int x;
  int y;
  bool small;
  bool horizontal;
};

piece new_piece_rh (int x, int y, bool small, bool horizontal){
  piece p = (piece)malloc(sizeof(struct piece_s));
  if (p == NULL){
    fprintf(stderr, "Allocation problem");
    exit(EXIT_FAILURE);
  }
  p->x = x;
  p->y = y;
  p->small = small;
  p->horizontal = horizontal;
  return p;
}

void delete_piece (piece p){
  free(p);
}

void copy_piece (cpiece src, piece dst){
  dst->x = src->x;
  dst->y = src->y;
  dst->small = src->small;
  dst->horizontal = src->horizontal;
}

void move_piece (piece p, dir d, int distance){
  if (p->horizontal){
    if (d == RIGHT)
      p->x += distance;
    if (d == LEFT)
      p->x -= distance;
    else{
      //fprintf(stderr, "You can't move the car like this.");
      return;
    }
  }
  else{
    if (d == UP)
      p->y += distance;
    if (d == DOWN)
      p->y -= distance;
    else{
      //fprintf(stderr, "You can't move the car like this.");      
      return;
    }
  }
}

bool intersect (cpiece p1, cpiece p2){
  if (is_horizontal(p1) && is_horizontal(p2)){
    for (int i = get_x(p1); i < get_x(p1) + get_width(p1); ++i){
      for (int j = get_x(p2); j < get_x(p2) + get_width(p2); ++j){
	if (i == j && get_y(p1) == get_y(p2))
	  return true;
      }
    }
    return false;
  }
  else if (!is_horizontal(p1) && !is_horizontal(p2)){
    for (int i = get_y(p1); i < get_y(p1) + get_height(p1); ++i){
      for (int j = get_y(p2); j < get_y(p2) + get_height(p2); ++j){
	if (get_x(p1) == get_x(p2) && i == j)
	  return true;
      }
    }
    return false;
  }
  else if (is_horizontal(p1) && !is_horizontal(p2)){
    for (int i = get_x(p1); i < get_x(p1) + get_width(p1); ++i){
      for (int j = get_y(p2); j < get_y(p2) + get_height(p2); ++j){
	if (i == get_x(p2) && get_y(p1) == j)
	  return true;
      }
    }
    return false;
  }
  else {
    for (int i = get_y(p1); i < get_y(p1) + get_height(p1); ++i){
      for (int j = get_x(p2); j < get_x(p2) + get_width(p2); ++j){
	if (get_x(p1) == j && i == get_y(p2))
	  return true;
      }
    }
    return false;
  }
}

int get_x (cpiece p){
  return p->x;
}

int get_y(cpiece p){
  return p->y;
}

int get_height (cpiece p){
  if (p->horizontal)
    return 1;
  else{
    if (p->small)
      return 2;
    return 3;
  }
}

int get_width (cpiece p){
  if (!p->horizontal)
    return 1;
  else{
    if (p->small)
      return 2;
    return 3;
  }
}

bool is_horizontal (cpiece p){
  return p->horizontal;
}
