#include <curses.h>
WINDOW *ventana; WINDOW *Box1; WINDOW *Box2;  WINDOW *Box3;
int main(){
    int MaxY, MaxX;
    initscr();
    getmaxyx(stdscr, MaxY, MaxX);
    if (!has_colors()){
        endwin();
        return 1;
    }
    cbreak();
    noecho();
    nonl();
    intrflush(ventana, FALSE);
    keypad(ventana, TRUE);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    ventana = newwin(MaxY, MaxX, 0, 0);
    Box1 = newwin(3, MaxX - 4, 2, 2);
    Box2 = newwin(MaxY - 9, (MaxX / 3) - 2, 6, 2);
    Box3 = newwin(MaxY - 9, ((MaxX * 2) / 3) - 3, 6, (MaxX / 3) + 2);
    wbkgd(ventana, COLOR_PAIR(1));
    wbkgd(Box1, COLOR_PAIR(1));
    wbkgd(Box2, COLOR_PAIR(1));
    wbkgd(Box3, COLOR_PAIR(1));
    refresh();
     box(Box1, 0, 0);
    box(Box2, 0, 0);
    box(Box3, 0, 0);
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    attrset(COLOR_PAIR(2));
    wattroff(ventana, COLOR_PAIR(2));
    mvwprintw(ventana, 0, 1, "                                                                                       YaST @ g185");
    mvwprintw(ventana, 0, 0, " ");
    for (int i = 12; i < MaxX - 18; i++){
        mvwprintw(ventana, 0, i, " ");
    }  
    mvwprintw(ventana, 0, MaxX - 18, "Press F1 for Help");
    mvwprintw(ventana, 0, MaxX, " ");
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    attrset(COLOR_PAIR(3));
    wattroff(ventana, COLOR_PAIR(3));
    mvwprintw(ventana, MaxY - 2, 4, "[Help]");
    mvwprintw(ventana, MaxY - 2, MaxX - 6, "[Quit]");

    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    attrset(COLOR_PAIR(4));
    wattroff(Box1, COLOR_PAIR(4)); 
    mvwprintw(Box1, 1, 1, "YaST2 Control Center");
    
    init_pair(6, COLOR_WHITE, COLOR_BLUE);
    attrset(COLOR_PAIR(6));
    wattroff(Box2, COLOR_PAIR(6)); 
    mvwprintw(Box2, 1, 1, "Software");
    for (int i = 9; i < (MaxX / 3) - 3; i++){
        mvwprintw(Box2, 1, i, " ");
    }
    mvwprintw(Box2, 2, 1, "Hardware");
    mvwprintw(Box2, 3, 1, "System");
    mvwprintw(Box2, 4, 1, "Network Devices");
    mvwprintw(Box2, 5, 1, "Network Services");
    mvwprintw(Box2, 6, 1, "Security and Users");
    mvwprintw(Box2, 7, 1, "Misc");

    init_pair(5, COLOR_WHITE, COLOR_BLUE);
    attrset(COLOR_PAIR(5));
    wattroff(Box3, COLOR_PAIR(5));  
    mvwprintw(Box3, 1, 1, "Patch CD Update");
    mvwprintw(Box3, 2, 1, "Installation into Directory");
    mvwprintw(Box3, 3, 1, "Online Update");
    mvwprintw(Box3, 4, 1, "Install and Remove Software");
    mvwprintw(Box3, 5, 1, "Change Source of Installation");
    mvwprintw(Box3, 6, 1, "System Update");

    touchwin(ventana);
    wrefresh(ventana);
    touchwin(Box1);
    wrefresh(Box1);
    touchwin(Box2);
    wrefresh(Box2);
    touchwin(Box3);
    wrefresh(Box3);
    getchar();
    endwin();
    return 0;
} 