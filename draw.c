#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if(x0 == x1){
    vertical(x0, y0, x1, y1, s, c);
    return;
  }
  int slope = (y1 - y0)/(x1 - x0);
  if(slope < 0) right(x0, y0, x1, y1, s, c);
  else if(slope > 0) left(x0, y0, x1, y1, s, c);
  else horizontal(x0, y0, x1, y1, s, c);
}

void right(int x0, int y0, int x1, int y1, screen s, color c){
  return;
}

void left(int x0, int y0, int x1, int y1, screen s, color c){
  int startx = min_coor(x0,x1);
  int starty = min_coor(y0,y1);
  int endx = max_coor(x0,x1);
  int endy = max_coor(y0,y1);
  int a = endy - starty;
  int b = -1 * (endx - startx);
  int d = 2 * a + b;
  float m = (a + 0.0) / b * -1;
  if(m > 1){ //2nd octant works
    while(startx <  endx){
      plot(s, c, startx, starty);
      if(d < 0){
        startx += 1;
        d += 2 * a;
      }
      starty += 1;
      d += 2 * b;
    }
  }
  else{//1st octant doesn't work
    while(startx < endx){
      plot(s, c, startx, starty);
      if(d > 0){
        starty ++;
        d += 2 * b;
      }
      startx ++;
      d += 2 * a;
    }
  }
}

void horizontal(int x0, int y0, int x1, int y1, screen s, color c){
  int start = min_coor(x0, x1);
  int end = max_coor(x0, x1);
  while(start < end){
    plot(s, c, start, y0);
    start += 1;
  }
}

void vertical(int x0, int y0, int x1, int y1, screen s, color c){
  int start = min_coor(y0, y1);
  int end = max_coor(y0,y1);
  while(start < end){
    plot(s, c, x0, start);
    start += 1;
  }
}

int max_coor(int i1, int i2){
  if(i1 < i2) return i2;
  return i1;
}

int min_coor(int i1, int i2){
  if (i1 < i2) return i1;
  return i2;
}
