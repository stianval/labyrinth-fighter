#include <cstdlib>
#include <ctime>
#include "../port.h"

static void (APIENTRY *myWindowPos)(GLint, GLint);

int os_init(){
    // Get the pointer for the glWindowPos2i function 
    // (in windows it seems the linker won't do the work, arg! >:( )
    myWindowPos = (void (APIENTRY *)(GLint, GLint)) wglGetProcAddress("glWindowPos2i");

    if (!myWindowPos){
        MessageBoxA(NULL, "Could not get glWindowPos2i pointer", "Error", MB_ICONERROR | MB_OK);
        exit(EXIT_FAILURE);
    }

    // Seed random generator. In windows we should do this another way.
	srand(time(NULL));

    return 0;
}

int random(){
    return rand();
}

void setWindowCursor(int x, int y){
    myWindowPos(x, y);
}