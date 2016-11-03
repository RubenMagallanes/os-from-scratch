#define FB_GREEN	2
#define FB_DARK_GREY	8

char *fb;

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
	fb = (char *) 0x000B8000; // init framebuffer
	
	fb_write_cell (0, 'A', FB_GREEN, FB_DARK_GREY);
	fb_write_cell (3, 'B', FB_GREEN, FB_DARK_GREY);
	return 0;
}

//TODO: make seperate init function
//	seperate fb functions into seperate function
