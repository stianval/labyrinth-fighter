#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Player() {
            x=y=z=0.0;
            vx=vy=vz=0.0;
        }
        
        ~Player() {
        }
        
        void setCamera();
        void process();
        
    private:
        double x,y,z;
        double vx,vy,vz;
};

#endif
