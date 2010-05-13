#define GL_GLEXT_PROTOTYPES

#if !defined(WIN32) && !defined(WIN64) && !defined(_MSC_VER)
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <SDL_TTF.h>
#else
#include "SDL.h"
#include "SDL_opengl.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glext.h"
#include "SDL_TTF.h"
#endif