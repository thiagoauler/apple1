#include <curses.h>
#include "inc/interface.h"
#include "inc/memory.h"

void io_init()
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    
    keyboard_control = 0x00;
}

void input()
{
    int ch = getch();
    if (ch == '\n') { ch = '\r'; }
    if (ch == '\r' || ch == '.' || ch == ':' ||
       (ch >= '0' && ch <= '9') ||
       (ch >= 'A' && ch <= 'Z'))
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
        addch(display_buffer);
    }
}
