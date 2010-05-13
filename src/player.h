#ifndef PLAYER_H
#define PLAYER_H
#include "matrix.h"

//Takeover code..
inline void set_state(int *state, int what, int value) {*state &= ~what; *state |= (what & -!!value);}

class Player {
    public:
		enum{K_UP = 0x001, K_DOWN = 0x002, K_LEFT = 0x004,
			K_RIGHT = 0x008, K_FORTH = 0x010, K_BRAKE = 0x020,
			K_FIRE = 0x040, K_TLEFT = 0x080, K_TRIGHT = 0x100,
			K_BRAKEDEBUG = 0x200};
        Player();
        ~Player() {
        }
        
        void setCamera();
        void process();
        void procState(int key, bool state);
        int keystate;
        double x,y,z,vx,vy,vz,droll, dpitch, dyaw,ox, oy, oz;
		
		RotMatrix rot;
};

extern class Player player;

#endif
