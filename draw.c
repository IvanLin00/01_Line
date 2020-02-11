#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if(x0 > x1){
    draw_line(x1,y1,x0,y0,s,c);
  }
  if(x0 == x1){
    vertical(x0, y0, x1, y1, s, c);
    return;
  }
  int slope = (y1 - y0)/(x1 - x0);
  if(slope < 0) right(x0, y0, x1, y1, s, c);
  else if(slope > 0) left(x0, y0, x1, y1, s, c);
  else horizontal(x0, y0, x1, y1, s, c);
}

void right(int startx, int starty, int endx, int endy, screen s, color c){
  int a = endy - starty;
  int b = endx - startx;
  int d = a + 2 * b;
  if(b < (-1 * a)){
    while (starty > endy){
      plot(s, c, startx, starty);
      if(d > 0){
        startx++;
        d += 2 * a;
      }
      starty--;
      d += 2 * b;
    }
  }
  else{
    d = 2 * a + b;
    while(startx < endx){
      plot(s, c, startx, starty);
      if(d < 0){
        starty--;
        d += 2 * b;
      }
      startx++;
      d += 2 * a;
    }
  }
}

void left(int startx, int starty, int endx, int endy, screen s, color c){
  int a = endy - starty;
  int b = -1 * (endx - startx);
  int d = 2 * a - b;
  if(a > (-1 * b)){ //2nd octant works
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
  else{//1st octant works 5th doesn't i think
    d = 2 * a + b;
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

void horizontal(int startx, int starty, int endx, int endy, screen s, color c){
  while(startx < endx){
    plot(s, c, startx, starty);
    startx += 1;
  }
}

void vertical(int startx, int starty, int endx, int endy, screen s, color c){
  while(starty < endy){
    plot(s, c, startx, starty);
    starty += 1;
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
