#include <curses.h>

int main()
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    
    int ch = ERR;
    while (ch == ERR)
    {
        ch = getch();
        //addch('.');
    }
    
    addch(ch);
    //refresh();
    
    nodelay(stdscr, FALSE);
    getch();
    endwin();
}
