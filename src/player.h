#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Player();
        
        ~Player() {
        }
        
        void setCamera();
        void process();
        
    private:
        double x,y,z;
        // current rotation
        // 
        double rot[9]; 
        double vx,vy,vz;
};

#endif
