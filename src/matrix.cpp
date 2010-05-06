#include <math.h>
#include "port.h"
#include "matrix.h"

#define SET(i,j,x)	{m[(i-1)*4+(j-1)] = x;}
#define GET(i,j)	(m[(i-1)*4+(j-1)])

// Rotates around the x axis
void RotMatrix::roll(double ang)
{
	double t1 = GET(1,2), t2 = GET(1,3);
	SET(1,2, t1*cos(ang)+t2*sin(ang));
	SET(1,3,-t1*sin(ang)+t2*cos(ang));
	
	t1 = GET(2,2); t2 = GET(2,3);
	SET(2,2, t1*cos(ang)+t2*sin(ang));
	SET(2,3,-t1*sin(ang)+t2*cos(ang));
	
	t1 = GET(3,2); t2 = GET(3,3);
	SET(3,2, t1*cos(ang)+t2*sin(ang));
	SET(3,3,-t1*sin(ang)+t2*cos(ang));
}

// Rotates around the y axis
void RotMatrix::yaw(double ang)
{
	double t1 = GET(1,1), t2 = GET(1,3);
	SET(1,1, t1*cos(ang)+t2*sin(ang));
	SET(1,3,-t1*sin(ang)+t2*cos(ang));
	
	t1 = GET(2,1); t2 = GET(2,3);
	SET(2,1, t1*cos(ang)+t2*sin(ang));
	SET(2,3,-t1*sin(ang)+t2*cos(ang));
	
	t1 = GET(3,1); t2 = GET(3,3);
	SET(3,1, t1*cos(ang)+t2*sin(ang));
	SET(3,3,-t1*sin(ang)+t2*cos(ang));
}

// Rotates around the z axis
void RotMatrix::pitch(double ang)
{
	double t1 = GET(1,1), t2 = GET(1,2);
	SET(1,1, t1*cos(ang)+t2*sin(ang));
	SET(1,2,-t1*sin(ang)+t2*cos(ang));
	
	t1 = GET(2,1); t2 = GET(2,2);
	SET(2,1, t1*cos(ang)+t2*sin(ang));
	SET(2,2,-t1*sin(ang)+t2*cos(ang));
	
	t1 = GET(3,1); t2 = GET(3,2);
	SET(3,1, t1*cos(ang)+t2*sin(ang));
	SET(3,2,-t1*sin(ang)+t2*cos(ang));
}
