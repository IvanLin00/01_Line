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
  int a = y1 - y0;
  int b = x1 - x0;
  if(x0 == x1) vertical(x0, y0, x1, y1, s, c);
  else if (y0 == y1) horizontal(x0, y0, x1, y1, s, c);
  else if(a <= b && a > 0) oct1(x0, y0, x1, y1, s, c, a, b);
  else if(a > b) oct2(x0, y0, x1, y1, s, c, a, b);
  else if(a < -1 * b) oct7(x0, y0, x1, y1, s, c, a, b);
  else oct8(x0, y0, x1, y1, s, c, a, b);
}

void oct1(int startx, int starty, int endx, int endy, screen s, color c, int a, int b){
  int d = 2 * a - b;
  while(startx < endx){
    plot(s, c, startx, starty);
    if(d > 0){
      starty ++;
      d -= 2 * b;
    }
    startx ++;
    d += 2 * a;
  }
}

void oct2(int startx, int starty, int endx, int endy, screen s, color c, int a, int b){
  int d = 2 * a + b;
  while(startx <  endx){
    plot(s, c, startx, starty);
    if(d < 0){
      startx += 1;
      d += 2 * a;
    }
    starty += 1;
    d -= 2 * b;
  }
}

void oct7(int startx, int starty, int endx, int endy, screen s, color c, int a, int b){
  int d = a + 2 * b;
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

void oct8(int startx, int starty, int endx, int endy, screen s, color c, int a, int b){
  int d = 2 * a + b;
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
