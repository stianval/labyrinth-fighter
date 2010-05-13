#include "port.h"
class Utilities {
	enum textquality {solid, shaded, blended};
	SDL_Surface *drawtext(TTF_Font *fonttodraw, char fgR, char fgG, char fgB, char fgA, 
char bgR, char bgG, char bgB, char bgA, char text[], textquality quality);
}