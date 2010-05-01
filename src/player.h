#ifndef PLAYER_H
#define PLAYER_H
#include "matrix.h"

//Takeover code..
inline void set_state(int *state, int what, int value) {*state &= ~what; *state |= (what & -!!value);}
#define K_UP          0x001
#define K_DOWN        0x002
#define K_LEFT        0x004
#define K_RIGHT       0x008
#define K_FORTH       0x010
#define K_BRAKE       0x020
#define K_FIRE        0x040
#define K_TLEFT       0x080
#define K_TRIGHT      0x100
#define K_BRAKEDEBUG  0x200

class Player {
    public:
        Player();
        
        ~Player() {
        }
        
        void setCamera();
        void process();
        
        int keystate;
		// bool k_up, k_down, k_left, k_right, k_forth, k_brake, k_fire, k_tleft, k_tright, k_brakedebug;
    private:
        double x,y,z,vx,vy,vz,droll, dpitch, dyaw;
		
		RotMatrix rot;
};

#endif
