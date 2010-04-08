#ifndef PLAYER_H
#define PLAYER_H
#include "matrix.h"

class Player {
    public:
        Player() {
            x=y=z=0.0;
            vx=vy=vz=0.0;
			rot.roll(-0.5);
        }
        
        ~Player() {
        }
        
        void setCamera();
        void process();
        
    private:
        double x,y,z;
        double vx,vy,vz;
		
		RotMatrix rot;
};

#endif
