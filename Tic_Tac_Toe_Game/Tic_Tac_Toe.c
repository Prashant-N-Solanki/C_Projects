#include <stdio.h> 
#include <windows.h>

int fg=' ',bg=' ',winlose(char*),indexerr(int);
void draw(int),finish(int *, int *);

int main(int argc, char const *argv[]) {system("TITLE TIC-TAC-TOE");system("MODE CON: cols=40 lines=26");
    int i,k,l,m,index,again,choice,choice1,wl[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    char t[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '},*ptr=t;
    system("color 01");system("cls");for(l=1;l<=20;l++) {if(l==1||l==2||l==19||l==20) draw(1); else if(l==5) {for(;l<=17;l++) {printf("%c%c%c%c",fg,fg,bg,bg);switch(l) {
        case 5: printf("     _____   _____   _____      ");break;case 6: printf("    |_|_|_| |_|_|_| | |_|_|     ");break;case 7: printf("      | |    _| |_  | |___      ");break;case 8: printf("      |_|   |_|_|_| |_|_|_|     ");break;
        case 9: printf("     _____     _     _____      ");break;case 10: printf("    |_|_|_|   /_\\   | |_|_|     ");break;case 11: printf("      | |    //_\\\\  | |___      ");break;case 12: printf("      |_|   /_/ \\_\\ |_|_|_|     ");break;
        case 13: printf("     _____   _____   _____      ");break;case 14: printf("    |_|_|_| | |_ _| | |_|_|     ");break;case 15: printf("      | |   |_|_| | | |_|_      ");break;case 16: printf("      |_|   |___|_| |_|_|_|     ");break;
        case 17: printf("                                ");break;}printf("%c%c%c%c\n",bg,bg,fg,fg);}l-=1;}else draw(2);}for(m=0;m<20;m++) printf(" ");Sleep(3*1000);
    system("color 08");for(k=1;k<=20;k++) {system("cls");for(l=1;l<=20;l++) {if(l==1||l==2||l==19||l==20) draw(1);   
        else if(l==10) {printf("%c%c%c%c%c%c%c%c%c      LOADING...      %c%c%c%c%c%c%c%c%c\n%c%c%c%c%c%c%c%c%c ",fg,fg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,fg,fg,fg,fg,bg,bg,bg,bg,bg,bg,bg);
        for(m=1;m<=20;m++) (m<=k)?printf("%c",176):printf(" ");printf(" %c%c%c%c%c%c%c%c%c\n",bg,bg,bg,bg,bg,bg,bg,fg,fg);l++;}else draw(2);}for(m=0;m<20;m++) printf(" ");Sleep(20);}Sleep(2*1000);
    mainmenu :choice=0;choice1=0;
    system("cls");system("color 03");draw(1);draw(1);draw(2);for(m=0;m<7;m++) {printf("%c%c",fg,fg);for(l=1;l<=11;l++) printf("%c",bg);switch (m) {
        case 0: printf("+---+---+---+");break;case 1: printf("| X | O | X |");break;case 2: printf("+---+---+---+");break;case 3: printf("| O | X | O |");break;
        case 4: printf("+---+---+---+");break;case 5: printf("| X | O | X |");break;case 6: printf("+---+---+---+");break;} for(l=1;l<=12;l++) printf("%c",bg);printf("%c%c\n",fg,fg);}draw(2);
        for(m=0;m<=6;m++) {printf("%c%c%c%c",fg,fg,bg,bg);switch (m) {case 0: printf("                                ");break;case 1: printf("  PRESS \"1\" FOR PLAYER VS BOT   ");break;
        case 2: printf("                                ");break;case 3: printf(" PRESS \"2\" FOR PLAYER VS PLAYER ");break;case 4: printf("                                ");break;case 5: printf("     PRESS \"3\" FOR SETTINGS     ");break;
        case 6: printf("                                ");break;}printf("%c%c%c%c\n",bg,bg,fg,fg);}draw(1);draw(1);for(m=0;m<20;m++) printf(" ");scanf("%d",&choice);getchar();PlaySoundA(TEXT("C:\\Users\\thepn\\OneDrive\\VSC\\GAMES\\TTT\\TTTSS.wav"),NULL,SND_ASYNC);
    if(choice==3) {setting:choice1=0;
        system("cls");system("color 0f");draw(1);draw(1);draw(2);for(m=0;m<7;m++) {printf("%c%c%c%c%c%c",fg,fg,bg,bg,bg,bg);switch (m) {
        case 0: printf("                            ");break;case 1: printf("          SETTINGS          ");break;case 2: printf(" -------------------------- ");break;case 3: printf(" >>> FOREGROUND CHAR : \"%c\"  ",fg);break;
        case 4: printf("                            ");break;case 5: printf(" >>> BACKGROUND CHAR : \"%c\"  ",bg);break;case 6: printf(" -------------------------- ");break;}printf("%c%c%c%c%c%c\n",bg,bg,bg,bg,fg,fg);}draw(2);
        for(m=0;m<=6;m++) {printf("%c%c%c%c%c%c",fg,fg,bg,bg,bg,bg);switch (m) {
        case 0: printf("                            ");break;case 1: printf(" PRESS \"1\" TO CHANGE THE FG ");break;case 2: printf("                            ");break;case 3: printf(" PRESS \"2\" TO CHANGE THE BG ");break;
        case 4: printf("                            ");break;case 5: printf(" PRESS \"3\" TO EXIT SETTINGS ");break;case 6: printf("                            ");break;}printf("%c%c%c%c%c%c\n",bg,bg,bg,bg,fg,fg);}
        draw(1);draw(1);for(m=0;m<20;m++) printf(" ");scanf("%d",&choice1);getchar();PlaySoundA(TEXT("C:\\Users\\thepn\\OneDrive\\VSC\\GAMES\\TTT\\TTTSS.wav"),NULL,SND_ASYNC);}
    if(choice1==1||choice1==2) {draw(1);printf("%c%c     ENTER NEW %sGROUND CHAR      %c%c\n",fg,fg,((choice1==1)?"FORE":"BACK"),fg,fg);draw(1);for(m=0;m<20;m++) printf(" ");
        again:
        if(choice1==1) {fg=getchar();if(fg==10) goto again;} else {bg=getchar();if(fg==10) goto again;} goto setting;}
    else if(choice1==3) goto mainmenu;
    restart : 
    system("cls");system("color 06");for(l=1;l<=20;l++) {if(l==1||l==2||l==19||l==20) draw(1);
        else if(l==16) {draw(1);printf("%c%c%c%c                                %c%c%c%c\n%c%c%c%c PRESS ENTER TO START THE GAME  %c%c%c%c\n",fg,fg,bg,bg,bg,bg,fg,fg,fg,fg,bg,bg,bg,bg,fg,fg);l+=2;}
        else {for(;l<=15;l++) {printf("%c%c%c%c%c",fg,fg,bg,bg,bg); switch(l) {case 3: printf("                              ");break;case 4: printf("    %%%%%%%%%%%%  %%%%  %%%%  %%%%%%%%%%%%    ");break;
        case 5: printf("    %%%%  %%%%  %%%%  %%%%  %%%%  %%%%    ");break;case 6: printf("    %%%%%%%%%%%%  %%%%  %%%%  %s    ",(choice==1)?"%% %% ":"%%%%%%");break;
        case 7: printf("    %%%%       %%%%%%%%   %s    ",(choice==1)?"%%  %%":"%%    ");break;case 8: printf("    %%%%        %%%%    %s    ",(choice==1)?"%%%%%%":"%%    ");break;
        case 9: printf(" ---------------------------  ");break;case 10: printf(" This mode is played between  ");break;
        case 11: (choice==1)?printf(" a person and a bot in which  "):printf(" two people in which both of  ");break;case 12: (choice==1)?printf(" both of them tries to win by "):printf(" them tries to win by placing ");break;
        case 13: (choice==1)?printf("placing their X's or O's three"):printf(" their X's or O's three in a  ");break;case 14: (choice==1)?printf("  in a row in any direction.  "):printf("    row in any direction.     ");break;
        case 15: printf("                              ");break;}printf("%c%c%c%c%c\n",bg,bg,bg,fg,fg);}l-=1;}}for(m=0;m<20;m++) printf(" ");getchar();PlaySoundA(TEXT("C:\\Users\\thepn\\OneDrive\\VSC\\GAMES\\TTT\\TTTSS.wav"),NULL,SND_ASYNC);
    system("cls");system("color 0a");for(i=1;i<11;i++) {if(i==10) {for(l=0;l<9;l++) t[l]=' '; (indexerr((choice==1)?9:4)==1)?({goto restart;}):({goto mainmenu;});} 
        if(!(choice==1&&i%2==0)) {system("cls");draw(1);draw(1);draw(2);draw(2);draw(2);for(m=0;m<7;m++) {printf("%c%c",fg,fg);for(l=1;l<=11;l++) printf("%c",bg);switch (m) {
        case 0: printf("+---+---+---+");break;case 1: (i==1)?printf("| 1 | 2 | 3 |"):printf("| %c | %c | %c |",t[0],t[1],t[2]);break;case 2: printf("+---+---+---+");break;case 3: (i==1)?printf("| 4 | 5 | 6 |"):printf("| %c | %c | %c |",t[3],t[4],t[5]);break;
        case 4: printf("+---+---+---+");break;case 5: (i==1)?printf("| 7 | 8 | 9 |"):printf("| %c | %c | %c |",t[6],t[7],t[8]);break;case 6: printf("+---+---+---+");break;}for(l=1;l<=12;l++) printf("%c",bg);printf("%c%c\n",fg,fg);}draw(2);
        if(choice==1) {printf("%c%c%c%c%c%c%c                          %c%c%c%c%c%c%c\n",fg,fg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,fg,fg);printf("%c%c%c%c%c%c%c        YOUR TURN         %c%c%c%c%c%c%c\n",fg,fg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,fg,fg);
        printf("%c%c%c%c%c%c%c ENTER THE INDEX FOR \"X\"  %c%c%c%c%c%c%c\n",fg,fg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,fg,fg);printf("%c%c%c%c%c%c%c                          %c%c%c%c%c%c%c\n",fg,fg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,fg,fg);
        draw(2);draw(1);draw(1);for(m=0;m<20;m++) printf(" ");scanf("%d",&index);Beep(1000,200);}
        if(choice==2) {printf("%c%c%c%c%c%c%c                          %c%c%c%c%c%c%c\n",fg,fg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,fg,fg);printf("%c%c%c%c%c%c%c%s%c%c%c%c%c%c%c\n",fg,fg,bg,bg,bg,bg,bg,(i%2==0)?"      PLAYER 2 TURN       ":"      PLAYER 1 TURN       ",bg,bg,bg,bg,bg,fg,fg);
        printf("%c%c%c%c%c%c%c%s%c%c%c%c%c%c%c\n",fg,fg,bg,bg,bg,bg,bg,(i%2==0)?" ENTER THE INDEX FOR \"O\"  ":" ENTER THE INDEX FOR \"X\"  ",bg,bg,bg,bg,bg,fg,fg);printf("%c%c%c%c%c%c%c                          %c%c%c%c%c%c%c\n",fg,fg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,fg,fg);
        draw(2);draw(1);draw(1);for(m=0;m<20;m++) printf(" ");scanf("%d",&index);Beep((i%2==0)?1500:1000,200);}again=indexerr((index<1||index>9)?1:(t[index-1]=='O')?2:(t[index-1]=='X')?3:0);if(again==1||again==3) {for(l=0;l<9;l++)t[l]=' '; (again==1) ? ({goto restart;}) : ({goto mainmenu;}) ;}}    
        if(choice==1) {if(i%2==0) { if(i==2) {t[(t[9-index]=='X')?10-index:9-index]='O';}else {for(l=0;l<8;l++) {if(t[wl[l][0]]=='O'&&t[wl[l][1]]=='O'&&t[wl[l][2]]==' ') {t[wl[l][2]]='O';goto skip;}
        else if(t[wl[l][0]]=='O'&&t[wl[l][2]]=='O'&&t[wl[l][1]]==' ') {t[wl[l][1]]='O';goto skip;}else if(t[wl[l][1]]=='O'&&t[wl[l][2]]=='O'&&t[wl[l][0]]==' ') {t[wl[l][0]]='O';goto skip;}}
        for(l=0;l<8;l++) {if(t[wl[l][0]]=='X'&&t[wl[l][1]]=='X'&&t[wl[l][2]]==' ') {t[wl[l][2]]='O';goto skip;} else if(t[wl[l][0]]=='X'&&t[wl[l][2]]=='X'&&t[wl[l][1]]==' ') {t[wl[l][1]]='O';goto skip;}
        else if(t[wl[l][1]]=='X'&&t[wl[l][2]]=='X'&&t[wl[l][0]]==' ') {t[wl[l][0]]='O';goto skip;}} for(l=9;l>=0;l--) if(t[l]==' ') {t[l]='O';break;}skip: printf("");}}else t[index-1]='X';}    
        if(choice==2) t[index-1]=(i%2==0)?'O':'X';
        if(winlose(ptr)==1) {again=indexerr((choice==1)?8:6);if(again==1||again==3) {for(l=0;l<9;l++) t[l]=' '; (again==1)?({goto restart;}):({goto mainmenu;});}}    
        if(winlose(ptr)==2) {again=indexerr((choice==1)?7:5);if(again==1||again==3) {for(l=0;l<9;l++) t[l]=' '; (again==1)?({goto restart;}):({goto mainmenu;});}}}return 0;}

void draw(int i) {if(i==1) {for(int l=0;l<40;l++) printf("%c",fg);printf("\n");}
    else {for(int l=0;l<40;l++) (l==0||l==1||l==38||l==39)?printf("%c",fg):printf("%c",bg);printf("\n");}}

int winlose(char *p) {char wl[8][3]={{p[0],p[1],p[2]},{p[3],p[4],p[5]},{p[6],p[7],p[8]},{p[0],p[3],p[6]},{p[1],p[4],p[7]},{p[2],p[5],p[8]},{p[0],p[4],p[8]},{p[2],p[4],p[6]}};
    for(int i=0;i<8;i++) {if (wl[i][0]=='O'&&wl[i][1]=='O'&&wl[i][2]=='O') return 1;else if(wl[i][0]=='X'&&wl[i][1]=='X'&&wl[i][2]=='X') return 2;}return 0;}

int indexerr(int err) {
    static int mode[10]={0,0,0,0,0,0,0,0,0,0},win[10]={0,0,0,0,0,0,0,0,0,0},mwp=0;
    int l,m,choice,*pm=mode,*pw=win;if(mwp==10) {for(l=0;l<10;l++) {mode[l]=0;win[l]=0;}mwp=0;}
    if(err==0) return 0; else if(err==4||err==5||err==6) {mode[mwp]=2;win[mwp]=(err==5)?1:(err==6)?2:3;mwp++;} else if(err==7||err==8||err==9) {mode[mwp]=1;win[mwp]=(err==7)?1:(err==8)?2:3;mwp++;}
    system("cls");system("color 04");PlaySoundA(TEXT("C:\\Users\\thepn\\OneDrive\\VSC\\GAMES\\TTT\\TTTES.wav"),NULL,SND_ASYNC);draw(1);draw(1);draw(2);draw(2);draw(2);
    printf("%c%c%c%c%c%c%c%c%c----------------------%c%c%c%c%c%c%c%c%c\n",fg,fg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,fg,fg);printf("%c%c%c%c%c%c%c%c%c",fg,fg,bg,bg,bg,bg,bg,bg,bg);switch(err) {
        case 1: printf("  INDEX OUT OF RANGE  ");break;case 2: printf(" INDEX OCCUPIED BY O  ");break;case 3: printf(" INDEX OCCUPIED BY X  ");break;case 4: printf("      GAME DRAW       ");break;
        case 5: printf("   PLAYER \"1\" WINS    ");break;case 6: printf("   PLAYER \"2\" WINS    ");break;case 7: printf("       YOU WON        ");break;case 8: printf("       BOT WON        ");break;
        case 9: printf("      GAME DRAW       ");break;}printf("%c%c%c%c%c%c%c%c%c\n",bg,bg,bg,bg,bg,bg,bg,fg,fg);
    printf("%c%c%c%c%c%c%c%c%c----------------------%c%c%c%c%c%c%c%c%c\n",fg,fg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,bg,fg,fg);draw(2);draw(2);draw(2);for(m=0;m<=6;m++) {
    printf("%c%c%c%c%c%c%c",fg,fg,bg,bg,bg,bg,bg);switch (m) {case 0: printf("                          ");break;case 1: printf("   PRESS \"1\" TO RESTART   ");break;
        case 2: printf("                          ");break;case 3: printf("    PRESS \"2\" TO EXIT     ");break;case 4: printf("                          ");break;case 5: printf(" PRESS \"3\" FOR MAIN MENU  ");break;
        case 6: printf("                          ");break;}printf("%c%c%c%c%c%c%c\n",bg,bg,bg,bg,bg,fg,fg);}draw(1);draw(1);
    for(m=0;m<20;m++) printf(" ");scanf("%d",&choice);getchar();if(choice!=2) PlaySoundA(TEXT("C:\\Users\\thepn\\OneDrive\\VSC\\GAMES\\TTT\\TTTSS.wav"),NULL,SND_ASYNC);if(choice==1) return 1;else if(choice==2) finish(pm,pw);else if(choice==3) return 3;}

void finish(int *pm, int *pw) {int k=0,l,m;system("cls");system("color 0F");for(l=1;l<=20;l++) {if(l==1||l==2||l==19||l==20) draw(1); else if(l==17) {printf("%c%c%c%c                                %c%c%c%c\n%c%c%c%c  PRESS ENTER TO EXIT THE GAME  %c%c%c%c\n",fg,fg,bg,bg,bg,bg,fg,fg,fg,fg,bg,bg,bg,bg,fg,fg);l+=1;}
        else if(l==4) {for(;l<6;l++) {printf("%c%c%c%c%c%c%c%c%c",fg,fg,bg,bg,bg,bg,bg,bg,bg);switch(l) {case 4: printf("   SCORE OF THE DAY   ");break;case 5: printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ",22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22);break;}printf("%c%c%c%c%c%c%c%c%c\n",bg,bg,bg,bg,bg,bg,bg,fg,fg);}
        for(;l<=15;l++) {printf("%c%c%c%c%c%c%c%c%c",fg,fg,bg,bg,bg,bg,bg,bg,bg);if(pm[k]!=0) (pm[k]==1)?printf(" %02d.   PVB    %s ",k+1,(pw[k]==1)?"YOU WON":(pw[k]==2)?"BOT WON":"  DRAW "):printf(" %02d.   PVP    %s ",k+1,(pw[k]==1)?"PY1 WON":(pw[k]==2)?"PY2 WON":"  DRAW ");
        else printf("                      ");k++;printf("%c%c%c%c%c%c%c%c%c\n",bg,bg,bg,bg,bg,bg,bg,fg,fg);}l-=1;}else draw(2);}for(m=0;m<20;m++) printf(" ");getchar();
    system("cls");system("color 05");PlaySoundA(TEXT("C:\\Users\\thepn\\OneDrive\\VSC\\GAMES\\TTT\\TTTTS.wav"),NULL,SND_ASYNC);for(l=1;l<=20;l++) {if(l==1||l==2||l==19||l==20) draw(1);else if(l==6) {for(;l<=14;l++) {printf("%c%c%c%c",fg,fg,bg,bg);switch(l) {
        case 6: printf("                                ");break;case 7: printf(" %c%c%c%c%c %c   %c   %c   %c%c  %c %c   %c  ",207,207,207,207,207,207,207,207,207,207,207,207,207);break;
        case 8: printf("   %c   %c%c%c%c%c  %c%c%c  %c %c %c %c %c    ",207,207,207,207,207,207,207,207,207,207,207,207,207,207);break;case 9: printf("   %c   %c   %c %c   %c %c  %c%c %c   %c  ",207,207,207,207,207,207,207,207,207,207);break;
        case 10: printf("                                ");break;case 11: printf("       %c%c %c%c  %c%c%c  %c   %c        ",207,207,207,207,207,207,207,207,207);break;case 12: printf("         %c   %c   %c %c   %c        ",207,207,207,207,207);break;case 13: printf("         %c    %c%c%c   %c%c%c         ",207,207,207,207,207,207,207);break;
        case 14: printf("                                ");break;}printf("%c%c%c%c\n",bg,bg,fg,fg);}l-=1;}else draw(2);}for(m=0;m<20;m++) printf(" ");Sleep(2*1000);system("cls");exit(0);}            