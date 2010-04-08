#ifndef PLAYER_H
#define PLAYER_H
#include "matrix.h"

class Player {
    public:
        Player();
        
        ~Player() {
        }
        
        void setCamera();
        void process();
        
		bool k_up, k_down, k_left, k_right, k_forth, k_break;
    private:
        double x,y,z;
        double vx,vy,vz;
		
		RotMatrix rot;
};

#endif
