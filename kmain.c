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
	unsigned int loc = 2*i;
	fb[loc] = c;

	//just insert character there, not color 
	fb[loc+1] = ((bg & 0x0f) << 4) | (fg & 0x0f);

}
/** fb_clear_all:
 *  clears entire framebuffer by filling it with spaces 
 *  
 *  @param bg color to set framebufer to
 */
//void fb_clear_all(unsigned char bg)
//{
	
//}


int kmain () 
{
	fb_write_cell (0, 'A', FB_GREEN, FB_BLACK);
	//fb_write_cell (80, 'A', FB_GREEN, FB_BLACK);
	fb_write_cell (1999, 'A', FB_GREEN, FB_BLACK);
	fb_write_cell (1920, 'A', FB_GREEN, FB_BLACK);
	fb_write_cell (79, 'A', FB_GREEN, FB_BLACK);
	return 0;
}

