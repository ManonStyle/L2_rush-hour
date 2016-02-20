#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "piece.h"

struct piece_s {
  int x, y;
  bool small, horizontal;
};

piece new_piece_rh (int x, int y, bool small, bool horizontal){
  piece new_car = (piece) malloc(sizeof(struct piece_s));
  if(new_car == NULL){
    fprintf(stderr, "probleme allocation\n");
    exit(EXIT_FAILURE);
  }
  new_car->x = x;
  new_car->y = y;
  new_car->small = small;
  new_car->horizontal = horizontal;
  return new_car;
}

void delete_piece (piece p){
  free(p);
}


void copy_piece (cpiece src, piece dst){
  dst = new_piece_rh (src->x, src->y, src->small, src->horizontal);
}

void move_piece (piece p, dir d, int distance){
  if(p->horizontal){
    if(d == UP || d == DOWN){
      fprintf(stderr, "the piece is not allowed to move vertically");
      exit(EXIT_FAILURE);
    }
    if(d == RIGHT){
      p->x += distance;
    }else
      p->x -= distance;
  }else{
    if(d == RIGHT || d == DOWN){
      fprintf(stderr, "the piece is not allowed to move horizontally");
      exit(EXIT_FAILURE);
    }
    if(d == UP){
      p->y += distance;
    }else
      p->x -= distance;
  }
}

bool intersect(cpiece p1, cpiece p2){
  int size_p1, size_p2;
  if(p1->small)
    size_p1 = 2;
  else
    size_p1 = 3;
  if(p2->small)
    size_p2 = 2;
  else
    size_p2 = 3;
  if(p1->horizontal){
    if(p2->horizontal){
      if((p2->y)-(p1->y)==0){
	if((p2->x)-(p1->x) < size_p1+size_p2-1 && (p2->x)-(p1->x) > -(size_p1+size_p2-1))
	  return true;
      }
    }else{
      if((p2->y)-(p1->y) <= 0 && (p2->y)-(p1->y) > -size_p2 &&
	 (p2->x)-(p1->x) >= 0 && (p2->x)-(p1->x) > size_p1)
	return true;
    }
  }else{
    if(p2->horizontal){
      if((p2->x)-(p1->x) <= 0 && (p2->x)-(p1->x) > -size_p2 &&
	 (p2->y)-(p1->y) >= 0 && (p2->y)-(p1->y) > size_p1)
	return true;
    }else{  
      if((p2->x)-(p1->x)==0){
	if((p2->y)-(p1->y) < size_p1+size_p2-1 && (p2->y)-(p1->y) > -(size_p1+size_p2-1))
	  return true;
      }
    }
  }
  return false;
}

int get_x(cpiece p){
  return p->x;
}

int get_y(cpiece p){
  return p->y;
}

int get_height(cpiece p){
  if(p->horizontal)
    return 1;
  if(p->small)
    return 2;
  return 3;
}

int get_width(cpiece p){
  if(p->horizontal){
    if(p->small)
      return 2;
    return 3;
  }
  return 1;
}

bool is_horizontal(cpiece p){
  return p->horizontal;
}
