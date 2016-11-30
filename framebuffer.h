#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#define FB_BLACK                0
#define FB_BLUE                 1
#define FB_GREEN                2
#define FB_CYAN                 3
#define FB_RED                  4
#define FB_MAGENTA              5
#define FB_BROWN                6
#define FB_LIGHT_GREY           7
#define FB_DARK_GREY            8
#define FB_LIGHT_BLUE           9
#define FB_LIGHT_GREEN          10
#define FB_LIGHT_CYAN           11
#define FB_LIGHT_RED            12
#define FB_LIGHT_MAGENTA        13
#define FB_LIGHT_BROWN          14
#define FB_WHITE                15

#define FB_WIDTH        80
#define FB_HEIGHT       25

/** fb_write_cell:
 *  writes a character with the given foreground and background to posit$
 *  in the framebuffer
 *
 *  @param i the location in the framebuffer
 *  @param c the character to write
 *  @param fg the foreground color
 *  @param bg the background color
 */
void fb_write_cell (unsigned int i, char c, unsigned char fg, unsigned char bg);


/** fb_clear_all:
 *  clears entire framebuffer by filling it with spaces 
 *  
 *  @param bg color to set framebufer to
 */
void fb_clear_all(unsigned char bg);

/**
 * draws char at specified location (x, y) where the top left of the fb $
 * 0 <= x < 80
 * 0 <= y < 25
 */
void fb_write_char_at  (int x, int y, char c, unsigned char fg, unsigned char bg);

/**
 *  draws chars to each corner of the framebuffer
 */
void corners();

#endif // FRAMEBUFFER_H_
