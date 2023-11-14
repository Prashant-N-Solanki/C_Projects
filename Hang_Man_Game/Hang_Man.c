// cls && gcc Hang-Man.c -o Hang-Man -lwinmm && start .\Hang-Man

#include <time.h>
#include <stdio.h>
#include <windows.h>

int main(int argc, char const *argv[]) {
  char words[7][20][20] = {
    /* 0 VEHICLES*/   { "van"           ,"taxi"          ,"police car"    ,"bus"           ,"ambulance"     ,
                        "skateboard"    ,"baby carriage" ,"bicycle"       ,"mountain bike" ,"scooter"       ,
                        "motorcycle"    ,"fire engine"   ,"crane"         ,"forklift"      ,"tractor"       ,
                        "truck"         ,"cement mixer"  ,"dump truck"    ,"subway"        ,"boat"          },
    
    /* 1 VEGETABLES*/ { "corn"          ,"mushroom"      ,"cucumber"      ,"red pepper"    ,"tomato"        ,
                        "carrot"        ,"pumpkin"       ,"cabbage"       ,"potato"        ,"sweet potato"  ,
                        "green chilli"  ,"onion"         ,"lettuce"       ,"radish"        ,"pea"           ,
                        "celery"        ,"green pepper"  ,"spinach"       ,"beetroot"      ,"bean"          },
    
    /* 2 FRUITS*/     { "apple"         ,"watermelon"    ,"orange"        ,"pear"          ,"cherry"        ,
                        "strawberry"    ,"grape"         ,"mango"         ,"blueberry"     ,"pomegranate"   ,
                        "banana"        ,"raspberry"     ,"jackfruit"     ,"papaya"        ,"kiwi"          ,
                        "pineapple"     ,"lime"          ,"lemon"         ,"grapefruit"    ,"melon"         },
    
    /* 3 COLOURS*/    { "white"         ,"yellow"        ,"blue"          ,"red"           ,"green"         ,
                        "black"         ,"brown"         ,"silver"        ,"purple"        ,"gray"          ,
                        "orange"        ,"maroon"        ,"charcoal"      ,"aqua"          ,"light green"   ,
                        "lime"          ,"crimson"       ,"khaki"         ,"magenta"       ,"cyan"          },
    
    /* 4 BODY PARTS*/ { "head"          ,"face"          ,"hair"          ,"ear"           ,"neck"          ,
                        "beard"         ,"eye"           ,"nose"          ,"mouth"         ,"chin"          ,
                        "shoulder"      ,"elbow"         ,"arm"           ,"chest"         ,"wrist"         ,
                        "toes"          ,"waist"         ,"leg"           ,"knee"          ,"hand"          },
    
    /* 5 HOME TOOLS*/ { "bolt"          ,"nail"          ,"screwdriver"   ,"handsaw"       ,"nut"           ,
                        "screw"         ,"wrench"        ,"hammer"        ,"hacksaw"       ,"spirit level"  ,
                        "pocketknife"   ,"scissors"      ,"chainsaw"      ,"cordless drill","brace"         ,
                        "toolbox"       ,"electric drill","corkscrew"     ,"tape measure"  ,"stepladder"    },
    
    /* 6 ANIMALS*/    { "dog"           ,"cat"           ,"mouse"         ,"tiger"         ,"lion"          ,
                        "chimpanzee"    ,"monkey"        ,"giraffe"       ,"zebra"         ,"fox"           ,
                        "hyena"         ,"wolf"          ,"bear"          ,"panda"         ,"hippo"         ,
                        "rhino"         ,"leopard"       ,"cheetah"       ,"panther"       ,"buffalo"       }
    
    /* 7 RANDOM*/                                                                                           };
  
  char down[20], ans[20], ch;
  int choice, i, j, k, l, wc, lives, di, spc, diff = 0, dp = 7;
  BOOL sfl, brk, ran = TRUE;
  
  srand(time(NULL));
  system("TITLE HANG-MAN && MODE CON: cols=48 lines=14"); 
  HWND consoleWindow = GetConsoleWindow();
  SetWindowLongA(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
  PlaySoundA("Audio\\HM_BM.wav", NULL, SND_ASYNC | SND_LOOP);
  
  Sleep(1000);
  for(int i = 1; i <= 16; i++) {
    system("cls"); system((i % 4 == 1) ? "color 04" : (i % 4 == 2) ? "color 01" : (i % 4 == 3) ? "color 02" : "color 06");    
    printf("\n _                                              \n");   
    printf("| |                                             \n");   
    printf("| |__   __ _ _ __   __ _  _ __ ___   __ _ _ __  \n");   
    printf("| '_ \\ / _` | '_ \\ / _` || '_ ` _ \\ / _` | '_ \\ \n");
    printf("| | | | (_| | | | | (_| || | | | | | (_| | | | |\n");   
    printf("|_| |_|\\__,_|_| |_|\\__, ||_| |_| |_|\\__,_|_| |_|\n");
    printf("                    __/ |                       \n");   
    printf("                   |___/                        \n");   
    printf("\n                       ");
    Sleep(200);
  }
  Sleep(1000);

  exit_to_mainmenu :
  system("cls && color 0b && TITLE HANG-MAN && MODE CON: cols=48 lines=14");
  printf("\n _______   _ _ _ _ _ _ _ _ _ _ _ _ _    _______ \n");   
  printf("  |   ||  |        MAIN MENU         |  ||   |  \n");   
  printf(" (_)  ||  |_ _ _ _ _ _ _ _ _ _ _ _ _ |  ||  (_) \n");   
  printf(" \\|/  ||   _ _ _ _ _ _ _ _ _ _ _ _ _    ||  \\|/ \n");   
  printf("  |   ||  |    PRESS '1' TO START    |  ||   |  \n");
  printf(" / \\  ||  |  PRESS '2' FOR SETTINGS  |  ||  / \\ \n");
  printf("   ___||_ |    PRESS '3' FOR HELP    | _||___   \n");   
  printf("          |_ _ PRESS '4' TO EXIT _ _ |          \n");
  printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");   
  printf("                       ");
  scanf("%d", &choice); getchar(); if(choice >= 1 && choice <= 3) Beep(2000, 100);

  if(choice == 1) { 
    while(TRUE) {
      lives = (diff == 0) ? 5 : (diff == 1) ? 7 : 10;
      if(dp == 7 || ran == TRUE) dp = rand() % 7;
          j = rand() % 20;
        sfl = FALSE;
         ch = '\0';
        spc = 0;
         di = 0;

            wc = strlen(words[dp][j]);
      for(i = 0; i < wc; i++) if(words[dp][j][i] != ' ') ans[i] = '_'; else { ans[i] = ' '; spc++; }
        ans[i] = '\0';
      down[di] = '\0';

      wc -= spc;
        k = (diff == 0) ? (wc + 1) / 2 : (diff == 1) ? (wc - 1) / 2 : (diff == 2 && wc > 3) ? (wc - 2) / 2 : 0;
      for(; k != 0; k--) {
        repeat :   
        l = rand() % strlen(words[dp][j]);
        if(ans[l] != '_') goto repeat;
        else { ans[l] = words[dp][j][l]; wc--; }
      }
    
      while(TRUE) {
        if(ch != '\0') {
          for(i = 0; words[dp][j][i] != '\0'; i++) if(ans[i] == '_' && words[dp][j][i] == ch) { sfl = TRUE; ans[i] = words[dp][j][i]; wc--; }
          if(sfl == FALSE) lives--; else sfl = FALSE;
          down[di++] = ch; down[di] = '\0';
        }
          
        if(wc == 0 || lives == 0) { brk = (wc == 0) ? TRUE : FALSE; break; } 
        system("cls && color 0d && TITLE HANG-MAN && MODE CON: cols=48 lines=14");  
        printf("\n _________  | CURRENT WORD TYPE : %s  \n", (ran == TRUE) ? "RANDOM      " : (dp == 0) ? "VEHICLES    " : (dp == 1) ? "VEGETABLES  " : (dp == 2) ? "FRUITS      " : (dp == 3) ? "COLOURS     " : (dp == 4) ? "BODY PARTS  " : (dp == 5) ? "HOME TOOLS  " : (dp == 6) ? "ANIMALS     " : "");   
        printf(" %s    ||  | _________________________________ \n"     , ((diff == 0 && lives ==  5) || 
                                                                          (diff == 1 && lives ==  7) || 
                                                                          (diff == 2 && lives == 10)) ? "   " : " | ");   
        printf(" %s    ||  | "                                         , ((diff == 0 && lives >= 4) ||   
                                                                          (diff == 1 && lives >= 6) || 
                                                                          (diff == 2 && lives >= 9)) ? "   " : ((diff == 1 && lives == 5) || 
                                                                                                                (diff == 2 && lives == 8)) ? " _ " : (diff == 2 && lives == 7) ? "(_ " : "(_)"); for(int i = 0; ans[i] != '\0'; i++) printf("%c ", ans[i]); for(int i = strlen(ans) * 2; i < 33; i++) printf(" ");  printf(" \n");   
        printf(" %s    ||  | _________________________________ \n"     , ((diff == 0 && lives >= 3) || 
                                                                          (diff == 1 && lives >= 4) || 
                                                                          (diff == 2 && lives >= 6)) ? "   " : ((diff == 1 && lives == 3) || 
                                                                                                                (diff == 2 && lives == 5)) ? " | " : (diff == 2 && lives == 4) ? "\\| " : "\\|/");   
        printf(" %s    ||  | REMAINING : %2d      LIVES : %2d    \n"   , ((diff == 0 && lives >= 2) || 
                                                                          (diff == 1 && lives >= 2) || 
                                                                          (diff == 2 && lives >= 3)) ? "   " : " | ", wc, lives);
        printf(" %s    ||  | _________________________________ \n"     , ((diff == 0 && lives >= 1) || 
                                                                          (diff == 1 && lives >= 1) || 
                                                                          (diff == 2 && lives >= 2)) ? "   " : (diff == 2 && lives == 1) ? "/  " : "/ \\");
        printf("     ___||_ | USED : "); for(int i = 0; down[i] != '\0'; i++) printf("%c ", down[i]); for(int i = strlen(down) * 2; i < 26; i++) printf(" ");  printf(" \n");   
        printf("            |     ONLY LOWER-CASE ALPHABETS     \n");   
        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
        printf("               INPUT : ");

        again : 
        ch = getchar(); getchar();
        for(i = 0; down[i] != '\0'; i++) if(down[i] == ch) goto again;
        if(! (ch >= 'a' && ch <= 'z') ) goto again; 
      }
    
      system("TITLE HANG-MAN && MODE CON: cols=48 lines=14");
      system((brk == TRUE) ? "color 02" : "color 04");
      if(brk == TRUE) mciSendStringA("play Audio\\HM_WM.wav", NULL, 0, 0);
      else            mciSendStringA("play Audio\\HM_LM.wav", NULL, 0, 0);
      for(i = 0; i < ((brk == TRUE) ? 2 : 6); i++) {
        system("cls");
        printf("\n _________  | %s \n"                                , (brk == TRUE) ? "   Congratulations! YOU WON     " : "         Sorry! YOU DIED         "); 
        printf("        ||  | _________________________________ \n"); 
        printf(" %s    ||  | "                                      , ((brk == TRUE && i == 0) || (brk == FALSE && i == 0)) ? "(_)"  : "   "); for(int i = 0; ans[i] != '\0'; i++) printf("%c ", ans[i]); for(int i = strlen(ans) * 2; i < 33; i++) printf(" ");  printf(" \n");
        printf(" %s    ||  | _________________________________ \n"  , ((brk == TRUE && i == 0) || (brk == FALSE && i == 0)) ? "\\|/" : ((brk == TRUE && i == 1) || (brk == FALSE && i == 1)) ? "(_)"  : "   "); 
        printf(" %s    ||  | THE WORD WAS : '%s'"                   , ((brk == TRUE && i == 0) || (brk == FALSE && i == 0)) ? " | "  : ((brk == TRUE && i == 1) || (brk == FALSE && i == 1)) ? "\\|/" : (brk == FALSE && i == 2) ? "(_)"  : "   ", words[dp][j]); for(int i = strlen(words[dp][j]); i < 16; i++) printf(" ");  printf(" \n"); 
        printf(" %s    ||  | _________________________________ \n"  , ((brk == TRUE && i == 0) || (brk == FALSE && i == 0)) ? "/ \\" : ((brk == TRUE && i == 1) || (brk == FALSE && i == 1)) ? " | "  : (brk == FALSE && i == 2) ? "\\|/" : (brk == FALSE && i == 3) ? "(_)"  : "   "); 
        printf(" %s ___||_ |   PRESS '1' TO CONTINUE PLAYING   \n"  , ((brk == TRUE && i == 0) || (brk == FALSE && i == 0)) ? "   "  : ((brk == TRUE && i == 1) || (brk == FALSE && i == 1)) ? "/ \\" : (brk == FALSE && i == 2) ? " | "  : (brk == FALSE && i == 3) ? "\\|/" : (brk == FALSE && i == 4) ? "(_)"  : "   ");
        printf("            |      PRESS '2' FOR MAIN MENU      \n");  
        printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n"); 
        printf("                       ");
        Sleep(500);
      }
      scanf("%d", &choice); getchar(); Beep(2000, 100);
      if(brk == TRUE) mciSendStringA("close Audio\\HM_WM.wav", NULL, 0, 0);
      else            mciSendStringA("close Audio\\HM_LM.wav", NULL, 0, 0);
      if(choice == 2) goto exit_to_mainmenu;
    }
  }

  else if(choice == 2) {
    exit_word_diff : 
    system("cls && color 06 && TITLE HANG-MAN && MODE CON: cols=48 lines=14");  
    printf("\n           _ _ _ _ _ _ _ _ _ _ _ _ _            \n");   
    printf("          |_ _ _ _ _SETTINGS _ _ _ _ |          \n");   
    printf("                                                \n");   
    printf("   WORD TYPE : '%d'         DIFFICULTY : '%d'   \n", (ran == TRUE) ? 7 : dp, diff);   
    printf("       _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _        \n");
    printf("      |  PRESS '1' TO CHANGE WORD TYPE   |      \n");
    printf("      |  PRESS '2' TO CHANGE DIFFICULTY  |      \n");   
    printf("      |_ _ PRESS '3' TO EXIT SETTINGS_ _ |      \n");
    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");   
    printf("                       ");
    scanf("%d", &choice); getchar(); Beep(2000, 100);

    if(choice == 1) {
      system("cls && color 08 && TITLE HANG-MAN && MODE CON: cols=48 lines=14");  
      printf("\n          _ _ _ _ _ _ _ _ _ _ _ _ _ _           \n");   
      printf("         |_ CURRENT WORD TYPE : '%d' _ |         \n", (ran == TRUE) ? 7 : dp);   
      printf("       VEHICLES   : 0      BODY PARTS : 4       \n");   
      printf("       VEGETABLES : 1      HOME TOOLS : 5       \n");
      printf("       FRUITS     : 2      ANIMALS    : 6       \n");
      printf("       COLOURS    : 3      RANDOM     : 7       \n");   
      printf("           _ _ _ _ _ _ _ _ _ _ _ _ _            \n");  
      printf("          |_ _PRESS NUM TO SELECT_ _ |          \n");   
      printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
      printf("                       ");

      dp_again : 
      scanf("%d", &dp); getchar();
      if(dp < 0 || dp > 7) goto dp_again;
      ran = FALSE;

      goto exit_word_diff;
    }

    else if(choice == 2) {
      system("cls && color 08 && TITLE HANG-MAN && MODE CON: cols=48 lines=14");  
      printf("\n          _ _ _ _ _ _ _ _ _ _ _ _ _ _           \n");   
      printf("         |_ CURRENT DIFF TYPE : '%d' _ |         \n", diff);   
      printf("                                                \n");   
      printf("                     EASY : 0                   \n");
      printf("                   MEDIUM : 1                   \n");
      printf("                     HARD : 2                   \n");   
      printf("           _ _ _ _ _ _ _ _ _ _ _ _ _            \n");  
      printf("          |_ _PRESS NUM TO SELECT_ _ |          \n");
      printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");   
      printf("                       ");

      diff_again : 
      scanf("%d", &diff); getchar();
      if(diff < 0 || diff > 2) goto diff_again;

      goto exit_word_diff;
    }

    else goto exit_to_mainmenu;
  }

  else if(choice == 3) {
    system("cls && color 09 && TITLE HANG-MAN && MODE CON: cols=48 lines=14");  
    printf("\n                    _ _  _ _                    \n");   
    printf("                   |_ HELP _|                   \n");   
    printf(" This game is a word finding game where you get \n");
    printf(" lives based on difficulty to guess a word by   \n");
    printf(" passing different characters but when you lose \n");   
    printf(" a life the person gets closer to be hanged.    \n");   
    printf("           _ _ _ _ _ _ _ _ _ _ _ _ _            \n");  
    printf("          |_ _PRESS ENTER TO EXIT_ _ |          \n");
    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");   
    printf("                       "); getchar(); Beep(2000, 100);

    goto exit_to_mainmenu;  
  }
  
  PlaySoundA(NULL, NULL, 0);
  mciSendStringA("play Audio\\HM_EM.wav", NULL, 0, 0);
  system("cls && color 0f && TITLE HANG-MAN && MODE CON: cols=48 lines=14");
  printf("\n _                                              \n");   
  printf("| |                                             \n");   
  printf("| |__   __ _ _ __   __ _  _ __ ___   __ _ _ __  \n");   
  printf("| '_ \\ / _` | '_ \\ / _` || '_ ` _ \\ / _` | '_ \\ \n");
  printf("| | | | (_| | | | | (_| || | | | | | (_| | | | |\n");   
  printf("|_| |_|\\__,_|_| |_|\\__, ||_| |_| |_|\\__,_|_| |_|\n");
  printf("                    __/ |                       \n");   
  printf("                   |___/                        \n");   
  printf("\n                       ");
  Sleep(3000);
  mciSendStringA("close Audio\\HM_EM.wav", NULL, 0, 0);
  return 0;
}

/**
 * Created By            : PRASHANT SOLANKI
 * Creation Date         : 13 / 03 / 2022
 * Last Code-Update Date : 15 / 04 / 2022
 * */