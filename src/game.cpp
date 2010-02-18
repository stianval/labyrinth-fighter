#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "game.h"
#include "player.h"

int game(void)
{
	bool quit = false;
	SDL_Event event;
	Player pl;
	
	while(!quit) {
		if( SDL_PollEvent( &event ) ) {
			if( event.type == SDL_QUIT ) {
				quit=true;
			}
		}
		
		pl.process();
		pl.setCamera();
		
	  	/* Move Right 3 Units */
		glLoadIdentity( );
		glTranslatef( 0.0f, 0.0f, -6.0f );

		glBegin( GL_QUADS );                 /* Draw A Quad                      */
		  glColor3f(   0.0f,  1.0f,  0.0f ); /* Set The Color To Green           */
		  glVertex3f(  1.0f,  1.0f, -1.0f ); /* Top Right Of The Quad (Top)      */
		  glVertex3f( -1.0f,  1.0f, -1.0f ); /* Top Left Of The Quad (Top)       */
		  glVertex3f( -1.0f,  1.0f,  1.0f ); /* Bottom Left Of The Quad (Top)    */
		  glVertex3f(  1.0f,  1.0f,  1.0f ); /* Bottom Right Of The Quad (Top)   */

		  glColor3f(   1.0f,  0.5f,  0.0f ); /* Set The Color To Orange          */
		  glVertex3f(  1.0f, -1.0f,  1.0f ); /* Top Right Of The Quad (Botm)     */
		  glVertex3f( -1.0f, -1.0f,  1.0f ); /* Top Left Of The Quad (Botm)      */
		  glVertex3f( -1.0f, -1.0f, -1.0f ); /* Bottom Left Of The Quad (Botm)   */
		  glVertex3f(  1.0f, -1.0f, -1.0f ); /* Bottom Right Of The Quad (Botm)  */

		  glColor3f(   1.0f,  0.0f,  0.0f ); /* Set The Color To Red             */
		  glVertex3f(  1.0f,  1.0f,  1.0f ); /* Top Right Of The Quad (Front)    */
		  glVertex3f( -1.0f,  1.0f,  1.0f ); /* Top Left Of The Quad (Front)     */
		  glVertex3f( -1.0f, -1.0f,  1.0f ); /* Bottom Left Of The Quad (Front)  */
		  glVertex3f(  1.0f, -1.0f,  1.0f ); /* Bottom Right Of The Quad (Front) */

		  glColor3f(   1.0f,  1.0f,  0.0f ); /* Set The Color To Yellow          */
		  glVertex3f(  1.0f, -1.0f, -1.0f ); /* Bottom Left Of The Quad (Back)   */
		  glVertex3f( -1.0f, -1.0f, -1.0f ); /* Bottom Right Of The Quad (Back)  */
		  glVertex3f( -1.0f,  1.0f, -1.0f ); /* Top Right Of The Quad (Back)     */
		  glVertex3f(  1.0f,  1.0f, -1.0f ); /* Top Left Of The Quad (Back)      */

		  glColor3f(   0.0f,  0.0f,  1.0f ); /* Set The Color To Blue            */
		  glVertex3f( -1.0f,  1.0f,  1.0f ); /* Top Right Of The Quad (Left)     */
		  glVertex3f( -1.0f,  1.0f, -1.0f ); /* Top Left Of The Quad (Left)      */
		  glVertex3f( -1.0f, -1.0f, -1.0f ); /* Bottom Left Of The Quad (Left)   */
		  glVertex3f( -1.0f, -1.0f,  1.0f ); /* Bottom Right Of The Quad (Left)  */

		  glColor3f(   1.0f,  0.0f,  1.0f ); /* Set The Color To Violet          */
		  glVertex3f(  1.0f,  1.0f, -1.0f ); /* Top Right Of The Quad (Right)    */
		  glVertex3f(  1.0f,  1.0f,  1.0f ); /* Top Left Of The Quad (Right)     */
		  glVertex3f(  1.0f, -1.0f,  1.0f ); /* Bottom Left Of The Quad (Right)  */
		  glVertex3f(  1.0f, -1.0f, -1.0f ); /* Bottom Right Of The Quad (Right) */
		glEnd( );                            /* Done Drawing The Quad            */

		/* Draw it to the screen */
		SDL_GL_SwapBuffers( );
		
		
		}
	
	return 0;
}
