#include <time.h>
#include <stdio.h>
#include <graphics.h>

#define screen_width  GetSystemMetrics(0)
#define screen_height GetSystemMetrics(1)
#define mid_x         screen_width  / 2
#define mid_y         screen_height / 2

#define EASY   0
#define MEDIUM 1
#define HARD   2

int spdDelay(int gameMode, int boxSize) {
  int fps;

  switch(gameMode) {
    case EASY  : fps = (boxSize < 70) ? 10 : (boxSize < 50) ? 15 : (boxSize < 30) ? 20 : (boxSize < 10) ?  25 :  5;  break;
    case MEDIUM: fps = (boxSize < 70) ? 20 : (boxSize < 50) ? 27 : (boxSize < 30) ? 35 : (boxSize < 10) ?  62 : 10;  break;
    case HARD  : fps = (boxSize < 70) ? 30 : (boxSize < 50) ? 40 : (boxSize < 30) ? 50 : (boxSize < 10) ? 100 : 20;  break;
  }

  return 1000 / fps; 
}

void initializeBackground(int color) {
  setbkcolor(color); 
  cleardevice(); 
  setbkcolor(color);

  return;
}  

void initializeSnake(int boxSize, int *left, int *top, int *right, int *bottom) {
  *left   = rand() % (screen_width  / boxSize) * boxSize;  
  *top    = rand() % (screen_height / boxSize) * boxSize;  

  *right  = *left + boxSize;
  *bottom = *top  + boxSize;

  return;
}

void initializeFood(int boxSize, int fruit[4]) {
  fruit[0] = rand() % (screen_width  / boxSize) * boxSize;
  fruit[1] = rand() % (screen_height / boxSize) * boxSize;

  fruit[2] = fruit[0] + boxSize;
  fruit[3] = fruit[1] + boxSize;

  return;
}