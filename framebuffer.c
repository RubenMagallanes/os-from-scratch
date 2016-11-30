#include "framebuffer.h"

char *fb = (char *) 0x000B8000; // starting address of framebuffer

void fb_write_cell (unsigned int i, char c, unsigned char fg, unsigned char bg)
{
        unsigned int loc = 2*i;
        fb[loc] = c;
        fb[loc+1] = ((bg & 0x0f) << 4) | (fg & 0x0f);
}

void fb_clear_all (unsigned char bg)
{
        unsigned int i;
        for ( i = 0; i < FB_WIDTH * FB_HEIGHT; i++)
        {
                fb_write_cell (i, ' ', FB_WHITE, bg);
        }
}

void fb_write_char_at  (int x, int y, char c, unsigned char fg, unsigned char bg)
{
        if (x < 0 || x >= FB_WIDTH || y < 0 || y >= FB_HEIGHT)
                return; 
        
        unsigned int pos = y* FB_WIDTH + x;
        fb_write_cell (pos, c, fg, bg);
}

void corners ()
{
        fb_write_char_at (0, 0, '#', FB_LIGHT_BLUE, FB_BLACK);
        fb_write_char_at (79, 0, '#', FB_LIGHT_BLUE, FB_BLACK);
        fb_write_char_at (0, 24, '#', FB_LIGHT_BLUE, FB_BLACK);
        fb_write_char_at (79, 24, '#', FB_LIGHT_BLUE, FB_BLACK);
}
