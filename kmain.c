#define FB_BLACK	0
#define FB_BLUE		1
#define FB_GREEN	2
#define FB_CYAN		3
#define FB_RED		4
#define FB_MAGENTA	5
#define FB_BROWN	6
#define FB_LIGHT_GREY	7
#define FB_DARK_GREY	8

#define FB_WHITE	'f'

char *fb = (char *) 0x000B8000; // starting address of framebuffer

/** fb_write_cell:
 *  writes a character with the given foreground and background to position i
 *  in the framebuffer
 *
 *  @param i the location in the framebuffer
 *  @param c the character to write
 *  @param fg the foreground color
 *  @param bg the background color
 */
void fb_write_cell (unsigned int i, char c, unsigned char fg, unsigned char bg)
{
	fb[i] = c;
	fb[i + 1] = ((fg & 0x0f) << 4) | (bg & 0x0f);
}
int kmain () 
{	
	fb_write_cell (0, 'A', FB_LIGHT_GREY, FB_BLACK);
	fb_write_cell (1, 'A', FB_LIGHT_GREY, FB_BLACK);
	fb_write_cell (2, 'A', FB_LIGHT_GREY, FB_BLACK);
	fb_write_cell (3, 'A', FB_LIGHT_GREY, FB_BLACK);
	return 0;
}

//TODO: make seperate init function
//	seperate fb functions into seperate function
