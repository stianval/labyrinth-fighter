#ifndef MATRIX_H
#define MATRIX_H

#include "port.h"

class RotMatrix {
	public:
		RotMatrix() {
			memset(m,0, sizeof(GLfloat)*16);
			m[0] = 1;
			m[5] = 1;
			m[10]= 1;
			m[15]= 1;
		}
		
		void setVector(int j, GLfloat x, GLfloat y, GLfloat z) {
			m[j+4*0] = x;
			m[j+4*1] = y;
			m[j+4*2] = z;
		}
		
		GLfloat getIndex(int j,int i) {
			return(m[j*4+i]);
		}
		
		void roll(double ang);
		void yaw(double ang);
		void pitch(double ang);
	private:
		GLfloat m[16]; // 4x4
};

#endif
