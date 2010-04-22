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
        
		bool k_up, k_down, k_left, k_right, k_forth, k_break, k_fire, k_tleft, k_tright;
    private:
        double x,y,z,vx,vy,vz,droll, dpitch, dyaw;
		
		RotMatrix rot;
};

#endif
