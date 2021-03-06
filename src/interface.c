#include <curses.h>
#include "inc/interface.h"
#include "inc/memory.h"

void io_init()
{
    initscr();
    noecho();
    cbreak();
    
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    
    //curs_set(FALSE);
    
    keyboard_control = 0x00;
}

void input()
{
    int ch = getch();
    
    if (ch == 0x107) { ch = '_';  }
    if (ch ==  0x7F) { ch = '_';  }
    if (ch ==  '\n') { ch = '\r'; }
    if (ch >= 'a' && ch <= 'z') { ch = ch - 0x20; }
    
    if (ch == '\r' || (ch >= 0x20 && ch <= 0x7F))
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
        if (display_buffer == '\r')
        {
            display_buffer = '\n';
        }
        if (display_buffer != 0x7F)
        {
            addch(display_buffer);
            refresh();
        }
    }
}
