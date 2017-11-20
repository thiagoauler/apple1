#include <curses.h>
#include "inc/interface.h"
#include "inc/memory.h"

void io_init()
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
}

void input()
{
    int ch = getch();
    if (ch != ERR)
    {
        keyboard_buffer  = ch | 0x80;
        keyboard_control = 0xFF;
    }
}

void output()
{
    // display is ready to ouptup
    if (display_buffer & 0x80)
    {
        // outputs the buffer character
        display_buffer = display_buffer & 0x7F;
        addch(display_buffer);
        //refresh();
    }
    
    //refresh();
}
