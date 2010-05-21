#include <cstdlib>
#include <ctime>
#include "port.h"

int os_init(){
    // Seed random generator
	srand(time(NULL));

    return 0;
}

int random(){
    return rand();
}

void setWindowCursor(int x, int y){
    glWindowPos2i(x, y);
}