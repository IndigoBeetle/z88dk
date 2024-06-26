
/////////////////////////////////////////////////////////////
// EXAMPLE PROGRAM #5c
// 04.2006 aralbrec
//
// Ex5b showed one way background tiles could appear to be
// in the foreground by using the idea of validating the
// relevant character squares prior to calling sp1_UpdateNow().
// The one drawback to this was that the act of validating
// was something that had to be done inside the main loop,
// meaning it slowed down the program.
//
// This time we accomplish the same thing but from outside
// the main loop so that the program is not slowed down at
// all.  sp1 supports the notion of removing character cells
// from the engine.  If a character cell is marked as 'removed'
// it will never draw to it.  Besides its use here as a means
// to make background tiles appear as foreground tiles, it
// can be used to prevent sp1 from drawing into areas of the
// screen that might contain art or graphics drawn by something
// other than sp1.
//
// Individual character squares can be removed or restored to
// the engine with calls to sp1_RemoveUpdateStruct() and
// sp1_RestoreUpdateStruct().  In this program we make use
// of sp1_IterateUpdateRect() which iterates over a rectangular
// area and calls a supplied function once for each character
// cell in the rectangle with the corresponding
// "struct sp1_update" as argument.  You'll see how this is
// used in combination with sp1_RemoveUpdateStruct() to easily
// remove the tic-tac-toe lines from sp1 below.
//
// One important thing you should notice in the program below
// is that the tic-tac-toe lines are drawn in the first
// sp1_UpdateNow() call before the character cells the lines
// occupy are removed from the engine.  Had the order been
// reversed, the tic-tac-toe lines would not have been drawn!
//
// Thus far we have seem how to make background tiles appear in
// the background (the normal behaviour) or the foreground
// (ex5a and this example) but what about somewhere in between?
// Perhaps some sprites should travel in front of a specific
// tile and others behind it?  For that we will need to examine
// free sprite characters (that is, "struct sp1_cs" that are
// not attached to any sprite) in a future series of examples.
/////////////////////////////////////////////////////////////

#include <arch/zx/sprites/sp1.h>
#include <malloc.h>
#include <spectrum.h>
#include <intrinsic.h>

#pragma output STACKPTR=53248                    // place stack at $d000 at startup
long heap;                                       // malloc's heap pointer


// Memory Allocation Policy                      // the sp1 library will call these functions
                                                 //  to allocate and deallocate dynamic memory
void *u_malloc(uint size) {
   return malloc(size);
}

void u_free(void *addr) {
    free(addr);
}

// Clipping Rectangle for Sprites

struct sp1_Rect cr = {0, 0, 32, 24};             // rectangle covering the full screen
struct sp1_Rect sr1;                             // spare rectangle to use as needed
struct sp1_Rect sr2;                             // spare rectangle to use as needed
struct sp1_Rect sr3;                             // spare rectangle to use as needed
struct sp1_Rect sr4;                             // spare rectangle to use as needed

// Table Holding Movement Data for Each Sprite

struct sprentry {
   struct sp1_ss  *s;                            // sprite handle returned by sp1_CreateSpr()
   char           dx;                            // signed horizontal speed in pixels
   char           dy;                            // signed vertical speed in pixels
};

struct sprentry sprtbl[] = {
   {0,1,0}, {0,0,1}, {0,1,2}, {0,2,1}, {0,1,3},
   {0,3,1}, {0,2,3}, {0,3,2}, {0,1,1}, {0,2,2}
};

// UDG Definitions for Background Characters

uchar hash   [] = {0x55,0xaa,0x55,0xaa,0x55,0xaa,0x55,0xaa};    // background hash
uchar horline[] = {0,0,0xff,0,0,0xff,0,0};                      // horizontal line
uchar verline[] = {0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24};    // vertical line
uchar intline[] = {0x24,0x24,0xe7,0,0,0xe7,0x24,0x24};          // intersection of horizontal and vertical lines

uchar window_data[] = {
    0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,
	128,127,  0,192,  0,191, 30,161,
	30,161, 30,161, 30,161,  0,191,
	0,191, 30,161, 30,161, 30,161,
	30,161,  0,191,  0,192,128,127,
	255,  0,255,  0,255,  0,255,  0,
	255,  0,255,  0,255,  0,255,  0,

	1,254,  0,  3,  0,253,120,133,
	120,133,120,133,120,133,  0,253,
	0,253,120,133,120,133,120,133,
	120,133,  0,253,  0,  3,  1,254,
	255,  0,255,  0,255,  0,255,  0,
	255,  0,255,  0,255,  0,255,  0
};
uchar *gr_window = &window_data[16];      // gr_window will hold the address of the asm label _gr_window

main()
{
   uchar i;
   struct sp1_ss *s;
   struct sprentry *se;

   intrinsic_di();

   // Initialize MALLOC.LIB
   
   heap = 0L;                  // heap is empty
   sbrk( ( void * ) 40000, 10000);         // add 40000-49999 to malloc

   // Initialize SP1.LIB
   
   zx_border(INK_BLACK);
   sp1_Initialize(SP1_IFLAG_MAKE_ROTTBL | SP1_IFLAG_OVERWRITE_TILES | SP1_IFLAG_OVERWRITE_DFILE, INK_BLACK | PAPER_WHITE, ' ');

   sp1_TileEntry(' ', hash);     // redefine graphic associated with space character
   sp1_TileEntry('H', horline);  // 'H' will be the horizontal line graphic
   sp1_TileEntry('V', verline);  // 'V' will be the vertical line graphic
   sp1_TileEntry('C', intline);  // 'C' will be the intersection graphic

   // Print a Tic-Tac-Toe Pattern
   
   for (i=0; i!=32; ++i)       // draw the two horizontal lines in tic-tac-toe pattern
   {
      sp1_PrintAt( 7, i, INK_RED | PAPER_GREEN, 'H');
      sp1_PrintAt(16, i, INK_RED | PAPER_GREEN, 'H');
   }
   
   for (i=0; i!=24; ++i)       // draw the two vertical lines in tic-tac-toe pattern
   {
      sp1_PrintAt(i, 10, INK_RED | PAPER_GREEN, 'V');
      sp1_PrintAt(i, 21, INK_RED | PAPER_GREEN, 'V');
   }
   
   sp1_PrintAt( 7, 10, INK_RED | PAPER_GREEN, 'C');    // where the lines intersect
   sp1_PrintAt( 7, 21, INK_RED | PAPER_GREEN, 'C');    // print the intersection graphic
   sp1_PrintAt(16, 10, INK_RED | PAPER_GREEN, 'C');
   sp1_PrintAt(16, 21, INK_RED | PAPER_GREEN, 'C');

   // Create Four Rectangles that Cover the Four Tic-Tac-Toe Lines
   
   sr1.row =  7; sr1.col =  0; sr1.width = 32; sr1.height =  1;    // top horizontal line
   sr2.row = 16; sr2.col =  0; sr2.width = 32; sr2.height =  1;    // bottom horizontal line
   sr3.row =  0; sr3.col = 10, sr3.width =  1; sr3.height = 24;    // leftmost vertical line
   sr4.row =  0; sr4.col = 21, sr4.width =  1; sr4.height = 24;    // rightmost vertical line

   sp1_Invalidate(&cr);        // invalidate entire screen so that it is all initially drawn
   sp1_UpdateNow();            // draw screen area managed by sp1 now

   // Now Remove the Tic-Tac-Toe Lines from the sp1 Engine
   
   sp1_IterateUpdateRect(&sr1, sp1_RemoveUpdateStruct);
   sp1_IterateUpdateRect(&sr2, sp1_RemoveUpdateStruct);
   sp1_IterateUpdateRect(&sr3, sp1_RemoveUpdateStruct);
   sp1_IterateUpdateRect(&sr4, sp1_RemoveUpdateStruct);

   // Create Ten Masked Software-Rotated Sprites
   
   for (i=0; i!=10; i++)
   {
      s = sprtbl[i].s = sp1_CreateSpr(SP1_DRAW_MASK2LB, SP1_TYPE_2BYTE, 3, 0, i);
      sp1_AddColSpr(s, SP1_DRAW_MASK2, 0, 48, i);
      sp1_AddColSpr(s, SP1_DRAW_MASK2RB, 0, 0, i);
      sp1_MoveSprAbs(s, &cr, gr_window, 10, 14, 0, 4);

   };
   
   while (1) {                                   // main loop
   
      sp1_UpdateNow();                           // draw screen now
      
      for (i=0; i!=10; i++) {                    // move all sprites
 
         se = &sprtbl[i];
         
         sp1_MoveSprRel(se->s, &cr, 0, 0, 0, se->dy, se->dx);
         
         if (se->s->row > 21)                    // if sprite went off screen, reverse direction
            se->dy = - se->dy;
            
         if (se->s->col > 29)                    // notice if coord moves less than 0, it becomes
            se->dx = - se->dx;                   //   255 which is also caught by these cases

      }
      
   }  // end main loop

}
