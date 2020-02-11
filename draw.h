#include "ml6.h"

#ifndef DRAW_H
#define DRAW_H

void draw_line(int x0, int y0, int x1, int y1, screen s, color c);
void right(int startx, int starty, int endx, int endy, screen s, color c);
void left(int startx, int starty, int endx, int endy, screen s, color c);
void horizontal(int startx, int starty, int endx, int endy, screen s, color c);
void vertical(int startx, int starty, int endx, int endy, screen s, color c);
int max_coor(int i1, int i2);
int min_coor(int i1, int i2);

#endif
