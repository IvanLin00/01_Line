#include "ml6.h"

#ifndef DRAW_H
#define DRAW_H

void draw_line(int x0, int y0, int x1, int y1, screen s, color c);
void oct1(int startx, int starty, int endx, int endy, screen s, color c, int a, int b);
void oct2(int startx, int starty, int endx, int endy, screen s, color c, int a, int b);
void oct7(int startx, int starty, int endx, int endy, screen s, color c, int a, int b);
void oct8(int startx, int starty, int endx, int endy, screen s, color c, int a, int b);
void horizontal(int startx, int starty, int endx, int endy, screen s, color c);
void vertical(int startx, int starty, int endx, int endy, screen s, color c);

#endif
