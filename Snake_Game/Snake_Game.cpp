#include "Header.hpp"

int main(int argc, char const *argv[]) {
  
  // INITIALIZE WINDOW
  initwindow(screen_width, screen_height, "", -3, -3, FALSE, TRUE);
  
  // COLORS
  int background_color  = BLACK;
  int snake_color_outer = WHITE;
  int snake_color_inner = YELLOW;
  int fruit_color_outer = BLUE;
  int fruit_color_inner = LIGHTBLUE;
  int collision_color   = DARKGRAY;
  
  // SNAKE
  int snake_box_size = 30;
  int snake_box_diff = snake_box_size / 7;
  int snake_design   = SLASH_FILL;
  int snake[(screen_height / snake_box_size) * (screen_width / snake_box_size) + 1][4];
  int snake_length;
  
  // FRUIT
  int fruit_box_diff = snake_box_diff + 2;
  int fruit_design   = XHATCH_FILL;
  int fruit[4];
  
  // GAME PROPERTIES
  int difficulty  = MEDIUM;
  int speed_delay = spdDelay(difficulty, snake_box_size);
  int old_score, score;
  
  // ESSENTIALS
  int last_box_left, last_box_top;
  char char_input, scr[35];
  char up = 'w', down = 's', left = 'a', right = 'd';

  // STRINGS TO DISPLAY
  char str0[] = "Snake Game", char_size0 = 10;
  char str1[] = "PRESS ENTER TO PLAY", char_size1 = 4;
  char str2[] = "PRESS \'A\' TO PLAY AGAIN OR \'E\' TO EXIT", char_size2 = 4;

  FILE *fptr = fopen("Score.bin", "rb");
  if (fptr == NULL) return 1;
  
  fread(&old_score, sizeof(int), 1, fptr);
  fclose(fptr);
  
  initializeBackground(background_color);
  srand(time(NULL));

  bool first_time = true;
  bool play_again = true;
  
  while (play_again == true) {
    cleardevice();

    if (first_time == true) {
      setcolor(RED);
      settextstyle(SANS_SERIF_FONT, HORIZ_DIR, char_size0);
      outtextxy(mid_x - (char_size0 * 30), mid_y - (char_size0 * 20), str0);
    
      setcolor(GREEN);
      settextstyle(BOLD_FONT, HORIZ_DIR, char_size1);
      outtextxy(mid_x - (char_size1 * 50), mid_y - (char_size1 * 10), str1);

      getch();
      cleardevice();

      first_time = false; 
    }  

    snake_length = 4;
    score = 0;
  
    initializeSnake(snake_box_size, &snake[0][0], &snake[0][1], &snake[0][2], &snake[0][3]);
    initializeFood(snake_box_size, fruit);
  
    switch(rand() % 4) { case 0: char_input = up; break;  case 1: char_input = down; break;  case 2: char_input = left; break;  case 3: char_input = right; break; }

    bool stop_game = false;
    while(stop_game == false) {
      
      // PRINTING SCORE
      sprintf(scr, "HIGHSCORE : %i    SCORE : %i", old_score, score);
      setcolor(DARKGRAY); 
      
      settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
      outtextxy(10, 10, scr);
    
      // SNAKE +
      setcolor(snake_color_outer); 
      setfillstyle(snake_design, snake_color_inner);
    
      rectangle(snake[0][0] + snake_box_diff, snake[0][1] + snake_box_diff, snake[0][2] - snake_box_diff, snake[0][3] - snake_box_diff);
      floodfill(snake[0][0] + snake_box_size / 2, snake[0][1] + snake_box_size / 2, snake_color_outer); 
    
      // SNAKE -
      setfillstyle(SOLID_FILL, background_color); 
      floodfill(last_box_left + snake_box_size / 2, last_box_top + snake_box_size / 2, snake_color_outer);
    
      setcolor(background_color); 
      rectangle(last_box_left + snake_box_diff, last_box_top + snake_box_diff, last_box_left + snake_box_size - snake_box_diff, last_box_top + snake_box_size - snake_box_diff);
    
      // FRUIT
      setcolor(fruit_color_outer); 
      setfillstyle(fruit_design, fruit_color_inner);
    
      rectangle(fruit[0] + fruit_box_diff, fruit[1] + fruit_box_diff, fruit[2] - fruit_box_diff, fruit[3] - fruit_box_diff);  
      floodfill(fruit[0] + snake_box_size / 2, fruit[1] + snake_box_size / 2, fruit_color_outer);

      Sleep(speed_delay);
    
      // SNAKE EATS FRUIT
      if (snake[0][0] == fruit[0] && snake[0][1] == fruit[1]) {
        snake_length++; 
        score++;

        setfillstyle(snake_design, snake_color_inner);
        floodfill(fruit[0] + snake_box_size / 2, fruit[1] + snake_box_size / 2, snake_color_outer);  
      
        srand(time(NULL));

        // RE-SPAWN FRUIT
        fruit_color_outer = (fruit_color_outer ==  5) ? 1 : fruit_color_outer + 1;
        fruit_color_inner = (fruit_color_inner == 13) ? 9 : fruit_color_inner + 1;

        int fruit_condition = false;      
        while (fruit_condition == false) {

          fruit[0] = rand() % (screen_width  / snake_box_size) * snake_box_size; 
          fruit[1] = rand() % (screen_height / snake_box_size) * snake_box_size;
          fruit[2] = fruit[0] + snake_box_size;
          fruit[3] = fruit[1] + snake_box_size; 

          if (getpixel(fruit[0] + snake_box_diff, fruit[1] + snake_box_diff) != snake_color_outer) fruit_condition = true; 
        }
      }  

      last_box_left  = snake[snake_length - 1][0]; 
      last_box_top   = snake[snake_length - 1][1];
    
      // POSITION CHANGE
      for (int i = snake_length - 1; i > 0; i--) {
      
        snake[i][0] = snake[i - 1][0];  
        snake[i][1] = snake[i - 1][1];
        snake[i][2] = snake[i - 1][2];  
        snake[i][3] = snake[i - 1][3]; 
      }  
    
      // KEYBOARD INPUT
      if(kbhit()) char_input = getch();
           if (char_input == up)    { snake[0][1] -= snake_box_size; snake[0][3] -= snake_box_size; }   
      else if (char_input == down)  { snake[0][1] += snake_box_size; snake[0][3] += snake_box_size; }
      else if (char_input == left)  { snake[0][0] -= snake_box_size; snake[0][2] -= snake_box_size; }
      else if (char_input == right) { snake[0][0] += snake_box_size; snake[0][2] += snake_box_size; }
      else     stop_game  =  true; 
      
      // COLLISION
      if(getpixel(snake[0][0] + snake_box_diff, snake[0][1] + snake_box_diff) == snake_color_outer) { 
        
        setfillstyle(SOLID_FILL, collision_color);
        floodfill(snake[0][0] + snake_box_size / 2, snake[0][1] + snake_box_size / 2, snake_color_outer);
        
        setcolor(collision_color);  
        rectangle(snake[0][0] + snake_box_diff, snake[0][1] + snake_box_diff, snake[0][2] - snake_box_diff, snake[0][3] - snake_box_diff);
        
        stop_game = true;
      }

      // TELEPORT
      if(snake[0][2] > screen_width ) { snake[0][0] = 0;                                                  snake[0][2] = snake[0][0] + snake_box_size; }
      if(snake[0][3] > screen_height) { snake[0][1] = 0;                                                  snake[0][3] = snake[0][1] + snake_box_size; }
      if(snake[0][0] < 0            ) { snake[0][0] = (screen_width  / snake_box_size) * snake_box_size;  snake[0][2] = snake[0][0] + snake_box_size; }
      if(snake[0][1] < 0            ) { snake[0][1] = (screen_height / snake_box_size) * snake_box_size;  snake[0][3] = snake[0][1] + snake_box_size; }
        
    }

    if (score > old_score) {
      fptr = fopen("Score.bin", "wb");
      if (fptr == NULL) return 1;
      
      fwrite(&score, sizeof(int), 1 , fptr);
      fclose(fptr);

      old_score = score;
    }

    setcolor(GREEN);
    settextstyle(BOLD_FONT, HORIZ_DIR, char_size2);
    outtextxy(mid_x - (char_size2 * 90), mid_y - (char_size2 * 10), str2);  
    
    char ch = getch();
    if (ch == 'E' || ch == 'e') play_again = false;  
  }

  return 0;
}