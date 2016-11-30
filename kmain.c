#define FB_BLACK		0
#define FB_BLUE			1
#define FB_GREEN		2
#define FB_CYAN			3	
#define FB_RED			4
#define FB_MAGENTA		5
#define FB_BROWN		6
#define FB_LIGHT_GREY		7
#define FB_DARK_GREY		8
#define FB_LIGHT_BLUE		9
#define FB_LIGHT_GREEN		10
#define FB_LIGHT_CYAN		11
#define FB_LIGHT_RED		12
#define FB_LIGHT_MAGENTA 	13
#define FB_LIGHT_BROWN		14
#define FB_WHITE		15

#define FB_WIDTH	80
#define FB_HEIGHT	25

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
	fb[loc+1] = ((bg & 0x0f) << 4) | (fg & 0x0f);
}

/** fb_clear_all:
 *  clears entire framebuffer by filling it with spaces 
 *  
 *  @param bg color to set framebufer to
 */
void fb_clear_all(unsigned char bg)
{
	unsigned int i;
	for ( i = 0; i < FB_WIDTH * FB_HEIGHT; i++)
	{
		fb_write_cell (i, ' ', FB_WHITE, bg);
	}
}
void colortest()
{
	fb_write_cell (161, 'c', FB_LIGHT_GREY, FB_BLACK);
	fb_write_cell (162, 'o', FB_LIGHT_GREY, FB_BLACK);
	fb_write_cell (163, 'l', FB_LIGHT_GREY, FB_BLACK);
	fb_write_cell (164, 't', FB_LIGHT_GREY, FB_BLACK);
	fb_write_cell (165, 'e', FB_LIGHT_GREY, FB_BLACK);
	fb_write_cell (166, 's', FB_LIGHT_GREY, FB_BLACK);
	fb_write_cell (167, 't', FB_LIGHT_GREY, FB_BLACK);

	//foreground		
	unsigned int col; 
	for(col = 0; col < 16; col++)
	{
		fb_write_cell(col, 'A', col, FB_BLACK);
	}
	//background		
	 
	for(col = 0; col < 16; col++)
	{
		fb_write_cell(col+ 16, 'A', FB_BLACK, col);
	}	
}
void corners()
{
	fb_write_cell (0, '#', FB_GREEN, FB_BLACK);
	fb_write_cell (79, '#', FB_GREEN, FB_BLACK);
	fb_write_cell (1920, '#', FB_GREEN, FB_BLACK);
	fb_write_cell (1999, '#', FB_GREEN, FB_BLACK);
}
int kmain () 
{
	fb_clear_all(FB_BLACK);	
	corners();
	//colortest();
	
	return 0;
}

